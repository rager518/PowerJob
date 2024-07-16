using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Text.Json.Serialization;
using System.Threading.Tasks;
using Settings.UI.Library.Interfaces;

namespace Settings.UI.Library;
public class HostsSettings : BasePTModuleSettings, ISettingsConfig
{
    public const string ModuleName = "Hosts";

    private static readonly JsonSerializerOptions _serializerOptions = new JsonSerializerOptions
    {
        WriteIndented = true,
    };

    [JsonPropertyName("properties")]
    public HostsProperties Properties
    {
        get; set;
    }

    public HostsSettings()
    {
        Properties = new HostsProperties();
        Version = "1.0";
        Name = ModuleName;
    }

    public virtual void Save(ISettingsUtils settingsUtils)
    {
        // Save settings to file
        var options = _serializerOptions;

        ArgumentNullException.ThrowIfNull(settingsUtils);

        settingsUtils.SaveSettings(JsonSerializer.Serialize(this, options), ModuleName);
    }

    public string GetModuleName() => Name;

    public bool UpgradeSettingsConfiguration() => false;
}