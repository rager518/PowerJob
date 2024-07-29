using Microsoft.UI.Xaml.Controls;
using PowerJob.ViewModels;
using Settings.UI.Library;

namespace PowerJob.Views;

public sealed partial class PowerStartupPage : Page
{
    public PowerStartupViewModel ViewModel
    {
        get;
    }

    public PowerStartupPage()
    {
        //ViewModel = App.GetService<PowerStartupViewModel>();
        var settingsUtils = new SettingsUtils();
        ViewModel = new PowerStartupViewModel(settingsUtils, SettingsRepository<GeneralSettings>.GetInstance(settingsUtils), SettingsRepository<HostsSettings>.GetInstance(settingsUtils), ShellPage.SendDefaultIPCMessage, App.IsElevated);
        InitializeComponent();
    }
}
