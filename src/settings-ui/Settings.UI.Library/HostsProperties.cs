using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;
using Settings.UI.Library.Enumerations;

namespace Settings.UI.Library;
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