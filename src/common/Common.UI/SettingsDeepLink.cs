using System.Diagnostics;
using System.IO;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace Common.UI;
public static class SettingsDeepLink
{
    public enum SettingsWindow
    {
        Overview = 0,
        Awake,
        ColorPicker,
        FancyZones,
        Run,
        ImageResizer,
        KBM,
        MouseUtils,
        PowerRename,
        FileExplorer,
        ShortcutGuide,
        VideoConference,
        Hosts,
        MeasureTool,
        PowerOCR,
        RegistryPreview,
        CropAndLock,
        EnvironmentVariables,
        Dashboard,
        AdvancedPaste,
    }

    private static string SettingsWindowNameToString(SettingsWindow value)
    {
        switch (value)
        {
            case SettingsWindow.Overview:
                return "Overview";
            case SettingsWindow.Awake:
                return "Awake";
            case SettingsWindow.ColorPicker:
                return "ColorPicker";
            case SettingsWindow.FancyZones:
                return "FancyZones";
            case SettingsWindow.Run:
                return "Run";
            case SettingsWindow.ImageResizer:
                return "ImageResizer";
            case SettingsWindow.KBM:
                return "KBM";
            case SettingsWindow.MouseUtils:
                return "MouseUtils";
            case SettingsWindow.PowerRename:
                return "PowerRename";
            case SettingsWindow.FileExplorer:
                return "FileExplorer";
            case SettingsWindow.ShortcutGuide:
                return "ShortcutGuide";
            case SettingsWindow.VideoConference:
                return "VideoConference";
            case SettingsWindow.Hosts:
                return "Hosts";
            case SettingsWindow.MeasureTool:
                return "MeasureTool";
            case SettingsWindow.PowerOCR:
                return "PowerOcr";
            case SettingsWindow.RegistryPreview:
                return "RegistryPreview";
            case SettingsWindow.CropAndLock:
                return "CropAndLock";
            case SettingsWindow.EnvironmentVariables:
                return "EnvironmentVariables";
            case SettingsWindow.Dashboard:
                return "Dashboard";
            case SettingsWindow.AdvancedPaste:
                return "AdvancedPaste";
            default:
                {
                    return string.Empty;
                }
        }
    }

    public static void OpenSettings(SettingsWindow window, bool mainExecutableIsOnTheParentFolder)
    {
        try
        {
            var assemblyPath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            var fullPath = new DirectoryInfo(assemblyPath).FullName;
            if (mainExecutableIsOnTheParentFolder)
            {
                // Need to go into parent folder for PowerToys.exe. Likely a WinUI3 App SDK application.
                fullPath = fullPath + "\\..\\PowerToys.exe";
            }
            else
            {
                // PowerToys.exe is in the same path as the application.
                fullPath = fullPath + "\\PowerToys.exe";
            }

            Process.Start(new ProcessStartInfo(fullPath) { Arguments = "--open-settings=" + SettingsWindowNameToString(window) });
        }
        catch
        {
            // TODO(stefan): Log exception once unified logging is implemented
        }
    }
}
