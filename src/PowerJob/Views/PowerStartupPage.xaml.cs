using Microsoft.UI.Xaml.Controls;

using PowerJob.ViewModels;

namespace PowerJob.Views;

public sealed partial class PowerStartupPage : Page
{
    public PowerStartupViewModel ViewModel
    {
        get;
    }

    public PowerStartupPage()
    {
        ViewModel = App.GetService<PowerStartupViewModel>();
        InitializeComponent();
    }
}
