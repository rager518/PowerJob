using System;
using System.Runtime.InteropServices;

namespace Settings.UI.Library.Utilities;
internal static class NativeMethods
{
    [DllImport("user32.dll")]
    public static extern bool AllowSetForegroundWindow(int dwProcessId);

    public const int SWRESTORE = 9;

    [DllImport("User32.dll")]
    public static extern bool SetForegroundWindow(IntPtr handle);

    [DllImport("User32.dll")]
    public static extern bool ShowWindow(IntPtr handle, int nCmdShow);

    [DllImport("User32.dll")]
    public static extern bool IsIconic(IntPtr handle);
}