// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System.Text.Json.Serialization;

namespace Settings.UI.Library;

public class AutoStartupProperties
{
    public AutoStartupProperties()
    {
        LaunchAS = true;
    }

    [JsonConverter(typeof(BoolPropertyJsonConverter))]
    public bool LaunchAS
    {
        get; set;
    }
}
