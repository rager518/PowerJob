// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using CommunityToolkit.Mvvm.Input;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using SwitchDesktops.Helpers;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Threading.Tasks;
using System.Windows.Input;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace SwitchDesktops.SwitchDesktopsView;

/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class SwitchPage : Page
{
    public IVirtualDManager VDAPI { get; set; }
    public ICommand SwitchCommand => new AsyncRelayCommand(SwitchDesktop);

    public IReadOnlyList<(Guid, string)> Desktops { get; set; }
    public ObservableCollection<int> Numbers { get; set; }

    public SwitchPage()
    {
        this.InitializeComponent();

        this.Desktops = VirtualDesktopManager.GetWindowDesktops();
        this.VDAPI = new VirtualDesktopWin11_23H2_2921();

        Numbers = new ObservableCollection<int>();

        for (int i = 0; i < Desktops.Count; i++)
        {
            Numbers.Add(i);
        }

        NumbersControl.DataContext = this;
    }


    private async Task SwitchDesktop()
    {
        await Task.Delay(0);
    }

    private void Button_Click(object sender, RoutedEventArgs e)
    {
        var index = ((Microsoft.UI.Xaml.FrameworkElement)(sender as Button).Content).DataContext;
        var d = (int)index;

        var virtualDesktopManager = new VirtualDesktopManager();
        var currentProcess = Process.GetCurrentProcess();
        var processlist = Process.GetProcessesByName(currentProcess.ProcessName);

        var (id, name) = this.Desktops[d];


        foreach (Process process in processlist)
        {
            //if (process.Id == currentProcess.Id)
            //    continue;

            if (process.MainWindowHandle != IntPtr.Zero)
            {
                if (virtualDesktopManager.IsWindowOnCurrentVirtualDesktop(process.MainWindowHandle))
                {
                    virtualDesktopManager.MoveWindowToDesktop(process.MainWindowHandle, id);

                    this.VDAPI.SwitchToDesktop(d, id);
                }

                return;
            }
        }

        return;
    }
}
