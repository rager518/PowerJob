using System.Runtime.InteropServices;
using System;
using System.Security;
using Microsoft.Win32;
using System.Collections.Generic;

namespace SwitchDesktops.Helpers;

[ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("a5cd92ff-29be-454c-8d04-d82879fb3f1b")]
[SuppressUnmanagedCodeSecurity]
internal interface IVirtualDesktopManager
{
    [PreserveSig]
    int IsWindowOnCurrentVirtualDesktop([In] IntPtr TopLevelWindow, [Out] out int OnCurrentDesktop);

    [PreserveSig]
    int GetWindowDesktopId([In] IntPtr TopLevelWindow, [Out] out Guid CurrentDesktop);

    [PreserveSig]
    int MoveWindowToDesktop([In] IntPtr TopLevelWindow, [MarshalAs(UnmanagedType.LPStruct)][In] Guid CurrentDesktop);
}

[ComImport, Guid("Aa509086-5ca9-4c25-8f95-589d3c07b48a")]
internal class CVirtualDesktopManager
{
}

public class VirtualDesktopManager
{
    private readonly IVirtualDesktopManager _manager;

    public VirtualDesktopManager()
    {
        _manager = (IVirtualDesktopManager)new CVirtualDesktopManager();
    }

    public bool IsWindowOnCurrentVirtualDesktop(IntPtr TopLevelWindow)
    {
        int hr = _manager.IsWindowOnCurrentVirtualDesktop(TopLevelWindow, out int result);
        if (hr != 0)
        {
            Marshal.ThrowExceptionForHR(hr);
        }

        return result != 0;
    }

    public Guid GetWindowDesktopId(IntPtr TopLevelWindow)
    {
        int hr = _manager.GetWindowDesktopId(TopLevelWindow, out Guid result);
        if (hr != 0)
        {
            Marshal.ThrowExceptionForHR(hr);
        }

        return result;
    }

    public void MoveWindowToDesktop(IntPtr TopLevelWindow, Guid CurrentDesktop)
    {
        int hr = _manager.MoveWindowToDesktop(TopLevelWindow, CurrentDesktop);
        if (hr != 0)
        {
            Marshal.ThrowExceptionForHR(hr);
        }
    }

    public static IReadOnlyList<(Guid DesktopId, string DesktopName)> GetWindowDesktops()
    {
        var list = new List<(Guid, string)>();

        using var key = Registry.CurrentUser.OpenSubKey(@"SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\VirtualDesktops", writable: false);
        if (key != null)
        {
            if (key.GetValue("VirtualDesktopIDs") is byte[] ids)
            {
                const int GuidSize = 16;
                var span = ids.AsSpan();
                while (span.Length >= GuidSize)
                {
                    var guid = new Guid(span.Slice(0, GuidSize));
                    string name = null;
                    using (var keyName = key.OpenSubKey($@"Desktops\{guid:B}", writable: false))
                    {
                        name = keyName?.GetValue("Name") as string;
                    }

                    // note: you may want to use a resource string to localize the value
                    name ??= "Desktop " + (list.Count + 1);
                    list.Add((guid, name));

                    span = span.Slice(GuidSize);
                }
            }
        }

        return list;
    }
}