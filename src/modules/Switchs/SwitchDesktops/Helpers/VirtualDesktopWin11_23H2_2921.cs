using System.Runtime.InteropServices;
using System;
using System.Security;

namespace SwitchDesktops.Helpers;

/// <summary>
///  https://github.com/dankrusi/WindowsVirtualDesktopHelper.git
/// </summary>
public class VirtualDesktopWin11_23H2_2921 : IVirtualDManager
{
    const string GUID_CLSID_ImmersiveShell = "C2F03A33-21F5-47FA-B4BB-156362A2F239";
    const string GUID_CLSID_VirtualDesktopManagerInternal = "C5E0CDCA-7B6E-41B2-9FC4-D93975CC467B";
    const string GUID_IApplicationView = "372E1D3B-38D3-42E4-A15B-8AB2B178F513";
    const string GUID_IVirtualDesktop = "3F07F4BE-B107-441A-AF0F-39D82529072C";
    const string GUID_IVirtualDesktopManagerInternal = "53F5CA0B-158F-4124-900C-057158060B27";
    const string GUID_IObjectArray = "92CA9DCD-5622-4BBA-A805-5E9F541BD8C9";
    const string GUID_IServiceProvider10 = "6D5140C1-7436-11CE-8034-00AA006009FA";

    internal static class Guids
    {
        public static readonly Guid CLSID_ImmersiveShell = new Guid(GUID_CLSID_ImmersiveShell);
        public static readonly Guid CLSID_VirtualDesktopManagerInternal = new Guid(GUID_CLSID_VirtualDesktopManagerInternal);
    }

    [ComImport]
    [InterfaceType(ComInterfaceType.InterfaceIsIInspectable)]
    [Guid(GUID_IApplicationView)]
    internal interface IApplicationView
    {

    }


    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid(GUID_IVirtualDesktopManagerInternal)]
    [SuppressUnmanagedCodeSecurity]
    internal interface IVirtualDesktopManagerInternal
    {
        int GetCount();
        void MoveViewToDesktop(IApplicationView view, IVirtualDesktop desktop);
        bool CanViewMoveDesktops(IApplicationView view);
        IVirtualDesktop GetCurrentDesktop();
        void GetDesktops(out IObjectArray desktops);
        [PreserveSig]
        int GetAdjacentDesktop(IVirtualDesktop from, int direction, out IVirtualDesktop desktop);
        void SwitchDesktop(IVirtualDesktop desktop);
        IVirtualDesktop CreateDesktop(IntPtr hWndOrMon);
        void MoveDesktop(IVirtualDesktop desktop, IntPtr hWndOrMon, int nIndex);
        void RemoveDesktop(IVirtualDesktop desktop, IVirtualDesktop fallback);
        IVirtualDesktop FindDesktop(ref Guid desktopid);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid(GUID_IObjectArray)]
    internal interface IObjectArray
    {
        void GetCount(out int count);
        void GetAt(int index, ref Guid iid, [MarshalAs(UnmanagedType.Interface)] out object obj);
    }

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid(GUID_IVirtualDesktop)]
    [SuppressUnmanagedCodeSecurity]
    internal interface IVirtualDesktop
    {
        Guid GetId();

        [return: MarshalAs(UnmanagedType.HString)]
        string GetName();
    }

    [ComImport]
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [Guid(GUID_IServiceProvider10)]
    internal interface IServiceProvider10
    {
        [return: MarshalAs(UnmanagedType.IUnknown)]
        object QueryService(ref Guid service, ref Guid riid);
    }
    internal static class DesktopManager
    {
        internal static IVirtualDesktopManagerInternal VirtualDesktopManagerInternal;

        static DesktopManager()
        {
            var shell = (IServiceProvider10)Activator.CreateInstance(Type.GetTypeFromCLSID(Guids.CLSID_ImmersiveShell));
            VirtualDesktopManagerInternal = (IVirtualDesktopManagerInternal)shell.QueryService(Guids.CLSID_VirtualDesktopManagerInternal, typeof(IVirtualDesktopManagerInternal).GUID);
        }
        internal static IVirtualDesktop GetDesktopAtIndex(int index)
        {
            IVirtualDesktop desktop = null;
            IObjectArray desktops;
            VirtualDesktopManagerInternal.GetDesktops(out desktops);
            object objdesktop;
            for (int i = 0; i < VirtualDesktopManagerInternal.GetCount(); i++)
            {
                desktops.GetAt(i, typeof(IVirtualDesktop).GUID, out objdesktop);
                if (i == index)
                {
                    desktop = objdesktop as IVirtualDesktop;
                }
            }

            Marshal.ReleaseComObject(desktops);

            return desktop;
        }
    }

    public void SwitchToDesktop(int number, Guid id)
    {
        var d = DesktopManager.VirtualDesktopManagerInternal.FindDesktop(ref id);
        //var desk = DesktopManager.GetDesktopAtIndex(number);
        DesktopManager.VirtualDesktopManagerInternal.SwitchDesktop(d);
    }
}

