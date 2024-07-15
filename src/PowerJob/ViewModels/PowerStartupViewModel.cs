using CommunityToolkit.Mvvm.ComponentModel;
using Microsoft.VisualBasic;
using PowerJob.Commands;
using Windows.System;

namespace PowerJob.ViewModels;

public partial class PowerStartupViewModel : ObservableRecipient
{
    public PowerStartupViewModel()
    {
    }
    private bool _enabledStateIsGPOConfigured = true;
    private bool _isEnabled = true;
    private bool _isElevated = true;
    public int _linePosition;

    public ButtonClickCommand LaunchEventHandler => new ButtonClickCommand(Launch);

    public void Launch()
    {
        string eventName = "";
        //string eventName = !_isElevated && LaunchAdministrator
        //    ? Constants.ShowHostsAdminSharedEvent()
        //    : Constants.ShowHostsSharedEvent();

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
        get => _enabledStateIsGPOConfigured;
        set => _enabledStateIsGPOConfigured = value;
    }

    public bool ShowStartupWarning
    {
        get => _enabledStateIsGPOConfigured;
        set => _enabledStateIsGPOConfigured = value;
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
}
