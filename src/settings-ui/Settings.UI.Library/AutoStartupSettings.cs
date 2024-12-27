// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Settings.UI.Library.Interfaces;
using System;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace Settings.UI.Library;

public class AutoStartupSettings : BasePTModuleSettings, ISettingsConfig
{
    public const string ModuleName = "AutoStartups";

    private static readonly JsonSerializerOptions _serializerOptions = new JsonSerializerOptions
    {
        WriteIndented = true,
    };

    public AutoStartupSettings()
    {
        this.Properties = new AutoStartupProperties();
        Version = "1.0";
        Name = ModuleName;
    }

    [JsonPropertyName("properties")]
    public AutoStartupProperties Properties
    {
        get; set;
    }

    public virtual void Save(ISettingsUtils settingsUtils)
    {
        // Save settings to file
        var options = _serializerOptions;

        ArgumentNullException.ThrowIfNull(settingsUtils);

        settingsUtils.SaveSettings(JsonSerializer.Serialize(this, options), ModuleName);
    }

    public string GetModuleName() => ModuleName;

    public bool UpgradeSettingsConfiguration() => false;
}
