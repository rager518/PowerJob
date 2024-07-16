using System.Text.Json.Serialization;
using PowerJob.Core.Converter;

namespace PowerJob.Core.Settings;
public class HostsProperties
{
    [JsonConverter(typeof(BoolPropertyJsonConverter))]
    public bool ShowStartupWarning
    {
        get; set;
    }

    [JsonConverter(typeof(BoolPropertyJsonConverter))]
    public bool LaunchAdministrator
    {
        get; set;
    }

    [JsonConverter(typeof(BoolPropertyJsonConverter))]
    public bool LoopbackDuplicates
    {
        get; set;
    }

    public HostsAdditionalLinesPosition AdditionalLinesPosition
    {
        get; set;
    }

    public HostsEncoding Encoding
    {
        get; set;
    }

    public HostsProperties()
    {
        ShowStartupWarning = true;
        LaunchAdministrator = true;
        LoopbackDuplicates = false;
        AdditionalLinesPosition = HostsAdditionalLinesPosition.Top;
        Encoding = HostsEncoding.Utf8;
    }
}

public enum HostsEncoding
{
    Utf8 = 0,
    Utf8Bom = 1,
}

public enum HostsAdditionalLinesPosition
{
    Top = 0,
    Bottom = 1,
}