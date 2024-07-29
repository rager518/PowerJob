using System.Runtime.CompilerServices;
using CommunityToolkit.Mvvm.ComponentModel;
using PowerJob.Commands;
using interop;
using Settings.UI.Library;
using Settings.UI.Library.Interfaces;

namespace PowerJob.ViewModels;

public partial class PowerStartupViewModel : ObservableRecipient
{
    //public PowerStartupViewModel()
    //{
    //    Settings = new HostsSettings();
    //    GeneralSettingsConfig = new GeneralSettings();
    //}

    public PowerStartupViewModel(ISettingsUtils settingsUtils, ISettingsRepository<GeneralSettings> settingsRepository, ISettingsRepository<HostsSettings> moduleSettingsRepository, Func<string, int> ipcMSGCallBackFunc, bool isElevated)
    {
        SettingsUtils = settingsUtils;
        GeneralSettingsConfig = settingsRepository.SettingsConfig;
        Settings = moduleSettingsRepository.SettingsConfig;
        SendConfigMSG = ipcMSGCallBackFunc;

        _isElevated = isElevated;

        //InitializeEnabledValue();
    }


    private bool _enabledStateIsGPOConfigured = true;
    private bool _isEnabled = true;
    private bool _isElevated = true;
    public int _linePosition;

    private ISettingsUtils SettingsUtils
    {
        get; set;
    }
    private GeneralSettings GeneralSettingsConfig
    {
        get; set;
    }

    private HostsSettings Settings
    {
        get; set;
    }

    private Func<string, int> SendConfigMSG
    {
        get;
    }


    public ButtonClickCommand LaunchEventHandler => new ButtonClickCommand(Launch);

    public void Launch()
    {
        string eventName = !_isElevated && LaunchAdministrator
            ? Constants.ShowHostsAdminSharedEvent()
            : Constants.ShowHostsSharedEvent();

        using (var eventHandle = new EventWaitHandle(false, EventResetMode.AutoReset, eventName))
        {
            eventHandle.Set();
        }
    }

    public bool IsEnabledGpoConfigured => false;

    public bool LaunchAdministratorEnabled => IsEnabled && !_isElevated;

    public bool IsEnabled
    {
        get => _isEnabled;

        set
        {
            if (_enabledStateIsGPOConfigured)
            {
                // If it's GPO configured, shouldn't be able to change this state.
                return;
            }

            if (value != _isEnabled)
            {
                _isEnabled = value;
                OnPropertyChanged(nameof(IsEnabled));
            }
        }
    }

    public bool LaunchAdministrator
    {
        get => Settings.Properties.LaunchAdministrator;
        set
        {
            if (value != Settings.Properties.LaunchAdministrator)
            {
                Settings.Properties.LaunchAdministrator = value;
                NotifyPropertyChanged();
            }
        }
    }

    public bool ShowStartupWarning
    {
        get => Settings.Properties.ShowStartupWarning;
        set
        {
            if (value != Settings.Properties.ShowStartupWarning)
            {
                Settings.Properties.ShowStartupWarning = value;
                NotifyPropertyChanged();
            }
        }
    }

    public bool LoopbackDuplicates
    {
        get => _enabledStateIsGPOConfigured;
        set => _enabledStateIsGPOConfigured = value;
    }


    public int AdditionalLinesPosition
    {
        get => _linePosition;
        set => _linePosition = value;
    }

    public int Encoding
    {
        get => _linePosition;
        set => _linePosition = value;
    }

    public void NotifyPropertyChanged([CallerMemberName] string? propertyName = null)
    {
        OnPropertyChanged(propertyName);
        SettingsUtils.SaveSettings(Settings.ToJsonString(), HostsSettings.ModuleName);
    }
}
