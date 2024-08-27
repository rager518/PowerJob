// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.
using AutoStartupLib;
using AutoStartups.Helpers;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using WinUIEx;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace AutoStartups;
/// <summary>
/// An empty window that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class MainWindow : WindowEx
{
    private AutoStartupMainPage MainPage { get; set; }

    public MainWindow()
    {
        InitializeComponent();

        ExtendsContentIntoTitleBar = true;
        SetTitleBar(titleBar);
        //AppWindow.SetIcon("Assets/Hosts/Hosts.ico");
        AppTitleTextBlock.Text = "Startups";

        MainPage = Host.GetService<AutoStartupMainPage>();
        MainPage.Hwnd = WinRT.Interop.WindowNative.GetWindowHandle(this);
    }

    private void MainGrid_Loaded(object sender, RoutedEventArgs e)
    {
        MainGrid.Children.Add(MainPage);
        Grid.SetRow(MainPage, 1);
    }
}
