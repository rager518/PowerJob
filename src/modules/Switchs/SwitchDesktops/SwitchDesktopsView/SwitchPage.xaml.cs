// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using CommunityToolkit.Mvvm.Input;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Threading.Tasks;
using System.Windows.Input;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace SwitchDesktops.SwitchDesktopsView
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class SwitchPage : Page
    {
        public ICommand SwitchCommand => new AsyncRelayCommand(SwitchDesktop);

        public ObservableCollection<int> Numbers { get; set; }
        public SwitchPage()
        {
            this.InitializeComponent();

            Numbers = new ObservableCollection<int>() { 1, 2, 3 };
            NumbersControl.DataContext = this;
        }

        //private void ButtonBrush_Click(object sender, Microsoft.UI.Xaml.RoutedEventArgs e)
        //{
        //    VisualStateManager.GoToState(sender as Control, "Pressed", true);
        //}

        private async Task SwitchDesktop()
        {
            await Task.Delay(0);

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var index = ((Microsoft.UI.Xaml.FrameworkElement)(sender as Button).Content).DataContext;
            var d = (int)index - 1;

            string scriptPath = @"E:\ps\Switch.ps1";

            // Create a new process to run PowerShell
            using (Process process = new Process())
            {
                // -ExecutionPolicy Bypas
                process.StartInfo.FileName = "powershell.exe";
                process.StartInfo.Arguments = $" -ExecutionPolicy Bypass  -File \"{scriptPath}\" -d {d}";
                process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.RedirectStandardError = true;
                process.StartInfo.UseShellExecute = false;
                process.StartInfo.CreateNoWindow = true;

                process.StartInfo.Verb = "runas";
                // Start the process
                process.Start();

                // Read output and error
                string output = process.StandardOutput.ReadToEnd();
                string error = process.StandardError.ReadToEnd();

                // Wait for the process to exit
                process.WaitForExit();

                // Handle output and error
                if (!string.IsNullOrEmpty(output))
                {
                    Debug.WriteLine("Output: " + output);
                }

                if (!string.IsNullOrEmpty(error))
                {
                    Debug.WriteLine("Error: " + error);
                }
            }
        }
    }
}
