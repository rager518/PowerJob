// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using AutoStartupLib.ViewModels;
using CommunityToolkit.Mvvm.Input;
using Microsoft.UI.Xaml.Controls;
using System.Threading.Tasks;
using System.Windows.Input;
using Windows.Storage.Pickers;
using Windows.Storage;
using System;
using AutoStartupLib.Models;
using Microsoft.UI.Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace AutoStartupLib;

/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class AutoStartupMainPage : Page
{
    public MainViewModel ViewModel { get; private set; }

    public nint Hwnd { get; set; }


    public ICommand NewCommand => new AsyncRelayCommand(OpenNewDialogAsync);
    public ICommand DeleteCommand => new RelayCommand(Delete);

    private void Delete()
    {
        ViewModel.DeleteSelected();
    }

    public AutoStartupMainPage(MainViewModel viewModel)
    {
        this.InitializeComponent();
        this.ViewModel = viewModel;
        this.DataContext = ViewModel;
    }

    private async Task OpenNewDialogAsync()
    {
        FileOpenPicker picker = new FileOpenPicker();

        WinRT.Interop.InitializeWithWindow.Initialize(picker, this.Hwnd);

        picker.SuggestedStartLocation = PickerLocationId.DocumentsLibrary;
        picker.FileTypeFilter.Add(".exe");

        StorageFile file = await picker.PickSingleFileAsync();

        if (file != null)
        {
            string fileName = file.Name;
            string path = file.Path;
            this.ViewModel.Add(new Entry(fileName, path));
        }
    }

    private void Page_Loaded(object sender, Microsoft.UI.Xaml.RoutedEventArgs e)
    {
        this.ViewModel.ReadSettings();
    }

    private async void Delete_Click(object sender, Microsoft.UI.Xaml.RoutedEventArgs e)
    {
        if (Entries.SelectedItem is Entry entry)
        {
            ViewModel.Selected = entry;

            DeleteDialog.Title = entry.Name;

            await DeleteDialog.ShowAsync();
        }
    }

    private void Entries_GotFocus(object sender, Microsoft.UI.Xaml.RoutedEventArgs e)
    {
        var element = sender as FrameworkElement;
        var entry = element.DataContext as Entry;

        if (entry != null)
        {
            ViewModel.Selected = entry;
        }
        else if (Entries.SelectedItem == null && Entries.Items.Count > 0)
        {
            Entries.SelectedIndex = 0;
        }
    }

    private void Entries_ItemClick(object sender, ItemClickEventArgs e)
    {
        Entry entry = e.ClickedItem as Entry;
        ViewModel.Selected = entry;
    }
}
