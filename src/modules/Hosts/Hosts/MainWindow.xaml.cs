using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Hosts.Helpers;
using HostsUILib;
using HostsUILib.Helpers;
using ManagedCommon;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Microsoft.Windows.ApplicationModel.Resources;
using Windows.Foundation;
using Windows.Foundation.Collections;
using WinUIEx;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace Hosts;
/// <summary>
/// An empty window that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class MainWindow : WindowEx
{
    private HostsMainPage MainPage
    {
        get;
    }

    public MainWindow()
    {
        InitializeComponent();

        ExtendsContentIntoTitleBar = true;
        SetTitleBar(titleBar);
        AppWindow.SetIcon("Assets/Hosts/Hosts.ico");

        //var loader = new ResourceLoader("PowerToys.HostsUILib.pri", "PowerToys.HostsUILib/Resources");

        //var title = Host.GetService<IElevationHelper>().IsElevated ? loader.GetString("WindowAdminTitle") : loader.GetString("WindowTitle");
        //Title = title;
        //AppTitleTextBlock.Text = title;

        //var handle = this.GetWindowHandle();

        //WindowHelpers.BringToForeground(handle);
        //Activated += MainWindow_Activated;

        MainPage = Host.GetService<HostsMainPage>();
    }

    private void MainWindow_Activated(object sender, WindowActivatedEventArgs args)
    {
        if (args.WindowActivationState == WindowActivationState.Deactivated)
        {
            AppTitleTextBlock.Foreground = (SolidColorBrush)App.Current.Resources["WindowCaptionForegroundDisabled"];
        }
        else
        {
            AppTitleTextBlock.Foreground = (SolidColorBrush)App.Current.Resources["WindowCaptionForeground"];
        }
    }

    private void myButton_Click(object sender, RoutedEventArgs e)
    {
        //myButton.Content = "Clicked";
    }

    private void Grid_Loaded(object sender, RoutedEventArgs e)
    {
        MainGrid.Children.Add(MainPage);
        Grid.SetRow(MainPage, 1);
    }
}
