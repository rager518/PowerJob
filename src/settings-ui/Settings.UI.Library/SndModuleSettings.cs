// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Text.Json;
using System.Threading.Tasks;

namespace Settings.UI.Library
{
    public class SndModuleSettings<T>
    {
        [JsonPropertyName("powerjob")]
        public T PowertoysSetting { get; set; }

        public SndModuleSettings()
        {
        }

        public SndModuleSettings(T settings)
        {
            PowertoysSetting = settings;
        }

        public string ToJsonString()
        {
            return JsonSerializer.Serialize(this);
        }
    }
}