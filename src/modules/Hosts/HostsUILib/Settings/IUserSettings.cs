using System;

namespace HostsUILib.Settings;
public interface IUserSettings
{
    public bool ShowStartupWarning
    {
        get;
    }

    public bool LoopbackDuplicates
    {
        get;
    }

    public HostsAdditionalLinesPosition AdditionalLinesPosition
    {
        get;
    }

    public HostsEncoding Encoding
    {
        get;
    }

    event EventHandler LoopbackDuplicatesChanged;

    public delegate void OpenSettingsFunction();
}