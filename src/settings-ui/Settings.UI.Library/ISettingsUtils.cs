using System;
using Settings.UI.Library.Interfaces;

namespace Settings.UI.Library;
public interface ISettingsUtils
{
    T GetSettings<T>(string powertoy = "", string fileName = "settings.json")
        where T : ISettingsConfig, new();

    T GetSettingsOrDefault<T>(string powertoy = "", string fileName = "settings.json")
        where T : ISettingsConfig, new();

    void SaveSettings(string jsonSettings, string powertoy = "", string fileName = "settings.json");

    bool SettingsExists(string powertoy = "", string fileName = "settings.json");

    void DeleteSettings(string powertoy = "");

    string GetSettingsFilePath(string powertoy = "", string fileName = "settings.json");

    T GetSettingsOrDefault<T, T2>(string powertoy = "", string fileName = "settings.json", Func<object, object> settingsUpgrader = null)
        where T : ISettingsConfig, new()
        where T2 : ISettingsConfig, new();
}