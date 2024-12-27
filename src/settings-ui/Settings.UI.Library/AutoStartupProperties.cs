// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Settings.UI.Library.Attributes;
using System.Text.Json.Serialization;

namespace Settings.UI.Library;

public class AutoStartupProperties
{
    [CmdConfigureIgnore]
    public HotkeySettings DefaultOpenShortcutGuide => new HotkeySettings(true, false, false, true, 0xBF);

    public AutoStartupProperties()
    {
        LaunchAS = true;
        UseLegacyPressWinKeyBehavior = new BoolProperty(true);
        OpenShortcutGuide = DefaultOpenShortcutGuide;
    }

    [JsonConverter(typeof(BoolPropertyJsonConverter))]
    public bool LaunchAS
    {
        get; set;
    }

    [JsonPropertyName("use_legacy_press_win_key_behavior")]
    public BoolProperty UseLegacyPressWinKeyBehavior { get; set; }


    [JsonPropertyName("open_shortcutguide")]
    public HotkeySettings OpenShortcutGuide { get; set; }

}
