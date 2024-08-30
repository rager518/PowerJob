// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Settings.UI.Library.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Text.Json;
using System.Threading.Tasks;

namespace Settings.UI.Library;

public class DataSetting : ISettingsConfig
{
    public const string ModuleName = "StartupData";
    public const string DataPath = "data.json";

    public string GetModuleName() => ModuleName;

    [JsonPropertyName("data-properties")]
    public List<FileInf> Files { get; set; }

    public string ToJsonString()
    {
        return JsonSerializer.Serialize(this, GetType());
    }

    public bool UpgradeSettingsConfiguration() => false;
}

public record FileInf(string name, string path);
