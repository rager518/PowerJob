namespace PowerJob.Core.Settings;
public interface ISettingsUtils
{
    T GetSettings<T>(string powerjob = "", string fileName = "settings.json")
           where T : ISettingsConfig, new();

    T GetSettingsOrDefault<T>(string powerjob = "", string fileName = "settings.json")
        where T : ISettingsConfig, new();

    void SaveSettings(string jsonSettings, string powerjob = "", string fileName = "settings.json");

    bool SettingsExists(string powerjob = "", string fileName = "settings.json");

    void DeleteSettings(string powerjob = "");

    string GetSettingsFilePath(string powerjob = "", string fileName = "settings.json");

    T GetSettingsOrDefault<T, T2>(string powerjob = "", string fileName = "settings.json", Func<object, object> settingsUpgrader = null)
        where T : ISettingsConfig, new()
        where T2 : ISettingsConfig, new();
}

public interface ISettingsConfig
{
    string ToJsonString();

    string GetModuleName();

    bool UpgradeSettingsConfiguration();
}

public interface ISettingsPath
{
    bool SettingsFolderExists(string powertoy);

    void CreateSettingsFolder(string powertoy);

    void DeleteSettings(string powertoy = "");

    string GetSettingsPath(string powertoy, string fileName);
}