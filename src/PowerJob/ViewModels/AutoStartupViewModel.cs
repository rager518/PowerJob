// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using CommunityToolkit.Mvvm.ComponentModel;
using interop;
using PowerJob.Commands;
//using PowerToys.GPOWrapper;

//using PowerToys.GPOWrapper;
using Settings.UI.Library;
using Settings.UI.Library.Interfaces;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using Windows.ApplicationModel.Store.Preview.InstallControl;

namespace PowerJob.ViewModels;

public partial class AutoStartupViewModel : ObservableRecipient
{
    private bool _enabledStateIsGPOConfigured;
    private bool _isEnabled;
    //private GpoRuleConfigured _enabledGpoRuleConfiguration;

    private ISettingsUtils SettingsUtils { get; set; }
    // private bool _isEnabled = true;
    private GeneralSettings GeneralSettingsConfig { get; set; }
    private AutoStartupSettings Settings { get; set; }
    private Func<string, int> SendConfigMSG { get; }

    public AutoStartupViewModel(ISettingsUtils settingsUtils, ISettingsRepository<GeneralSettings> settingsRepository,
        ISettingsRepository<AutoStartupSettings> moduleSettingsRepository, Func<string, int> ipcMSGCallBackFunc)
    {
        SettingsUtils = settingsUtils;
        GeneralSettingsConfig = settingsRepository.SettingsConfig;
        Settings = moduleSettingsRepository.SettingsConfig;
        SendConfigMSG = ipcMSGCallBackFunc;

        InitializeEnabledValue();

        _enabledStateIsGPOConfigured = true;
    }

    private void InitializeEnabledValue()
    {
        //_enabledGpoRuleConfiguration = GPOWrapper.GetConfiguredHostsFileEditorEnabledValue();
        //if (_enabledGpoRuleConfiguration == GpoRuleConfigured.Disabled || _enabledGpoRuleConfiguration == GpoRuleConfigured.Enabled)
        //{
        //    // Get the enabled state from GPO.
        //    _enabledStateIsGPOConfigured = true;
        //    _isEnabled = _enabledGpoRuleConfiguration == GpoRuleConfigured.Enabled;
        //}
        //else
        {
            _isEnabled = GeneralSettingsConfig.Enabled.AutoStarts;
        }
    }

    public bool IsEnabled
    {
        get => _isEnabled;

        set
        {
            //if (_enabledStateIsGPOConfigured)
            //{
            //    // If it's GPO configured, shouldn't be able to change this state.
            //    return;
            //}

            if (value != _isEnabled)
            {
                _isEnabled = value;

                // Set the status in the general settings configuration
                GeneralSettingsConfig.Enabled.AutoStarts = value;
                OutGoingGeneralSettings snd = new OutGoingGeneralSettings(GeneralSettingsConfig);

                SendConfigMSG(snd.ToString());
                OnPropertyChanged(nameof(IsEnabled));
            }
        }
    }

    public bool IsEnabledGpoConfigured
    {
        get => _enabledStateIsGPOConfigured;
    }

    public bool LanuchAS
    {
        get => Settings.Properties.LaunchAS;
        set
        {
            if (value != Settings.Properties.LaunchAS)
            {
                Settings.Properties.LaunchAS = value;
                NotifyPropertyChanged();
            }
        }
    }

    public void NotifyPropertyChanged([CallerMemberName] string propertyName = null)
    {
        OnPropertyChanged(propertyName);
        SettingsUtils.SaveSettings(Settings.ToJsonString(), AutoStartupSettings.ModuleName);
    }

    public ButtonClickCommand LaunchEventHandler => new ButtonClickCommand(Launch);
    public ButtonClickCommand GoEventHandler => new ButtonClickCommand(Go);

    public void Launch()
    {
        string eventName = Constants.ShowAutoStartupsShareEvent();

        using (var eventHandle = new EventWaitHandle(false, EventResetMode.AutoReset, eventName))
        {
            eventHandle.Set();
        }
    }


    public void Go()
    {
        var settingsUtils = new SettingsUtils();

        var config = settingsUtils.GetSettingsOrDefault<DataSetting>(DataSetting.ModuleName, DataSetting.DataPath);

        foreach (var (name, path) in config.Files)
        {
            Process.Start(path);
        }
    }
}
