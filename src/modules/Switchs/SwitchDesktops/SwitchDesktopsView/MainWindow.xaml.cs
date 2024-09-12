// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Microsoft.Graphics.Display;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using SwitchDesktops.SwitchDesktopsView;
using System;
using System.Collections.ObjectModel;
using System.Runtime.InteropServices;
using Windows.Devices.Input;
using WinUIEx;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace SwitchDesktops
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : WindowEx
    {
        public MainWindow()
        {
            this.InitializeComponent();

            this.Title = "Switch";
            this.SetIcon("./Assets/fav.ico");
            this.ExtendsContentIntoTitleBar = true;
            //this.SetTitleBar(MyTitleBar);

            //this.Width = 800;
            this.Height = 100;

            this.IsMinimizable = false;
            this.IsMaximizable = false;
            
            this.IsAlwaysOnTop = true;
            this.IsShownInSwitchers = true;
            this.IsResizable = false;
            this.IsTitleBarVisible = true;

            this.CenterOnScreen();
        }


        private void MainGrid_Loaded(object sender, RoutedEventArgs e)
        {
            MainGrid.Children.Add(new SwitchPage());
        }
    }
}
