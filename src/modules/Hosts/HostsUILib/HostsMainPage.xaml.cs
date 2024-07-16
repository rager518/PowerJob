using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Threading.Tasks;
using System.Windows.Input;
using CommunityToolkit.Mvvm.Input;
using HostsUILib.Helpers;
using HostsUILib.Models;
using HostsUILib.ViewModels;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Controls.Primitives;
using Microsoft.UI.Xaml.Data;
using Microsoft.UI.Xaml.Input;
using Microsoft.UI.Xaml.Media;
using Microsoft.UI.Xaml.Navigation;
using Windows.Foundation;
using Windows.Foundation.Collections;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace HostsUILib;
/// <summary>
/// An empty page that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class HostsMainPage : Page
{
    public MainViewModel ViewModel
    {
        get; private set;
    }
    public ICommand NewDialogCommand => new AsyncRelayCommand(OpenNewDialogAsync);

    public ICommand AdditionalLinesDialogCommand => new AsyncRelayCommand(OpenAdditionalLinesDialogAsync);

    public ICommand AddCommand => new RelayCommand(Add);

    public ICommand UpdateCommand => new RelayCommand(Update);

    public ICommand DeleteCommand => new RelayCommand(Delete);

    public ICommand UpdateAdditionalLinesCommand => new RelayCommand(UpdateAdditionalLines);

    public ICommand ExitCommand => new RelayCommand(() => { Microsoft.UI.Dispatching.DispatcherQueue.GetForCurrentThread().TryEnqueue(Application.Current.Exit); });
    public HostsMainPage()
    {
        this.InitializeComponent();
    }

    private async Task OpenNewDialogAsync()
    {
        await ShowAddDialogAsync();
    }

    private async Task ShowAddDialogAsync(Entry template = null)
    {
        var resourceLoader = ResourceLoaderInstance.ResourceLoader;
        //EntryDialog.Title = resourceLoader.GetString("AddNewEntryDialog_Title");
        //EntryDialog.PrimaryButtonText = resourceLoader.GetString("AddBtn");
        //EntryDialog.PrimaryButtonCommand = AddCommand;

        //EntryDialog.DataContext = template == null
        //    ? new Entry(ViewModel.NextId, string.Empty, string.Empty, string.Empty, true)
        //    : new Entry(ViewModel.NextId, template.Address, template.Hosts, template.Comment, template.Active);

        //await EntryDialog.ShowAsync();
    }

    private async Task OpenAdditionalLinesDialogAsync()
    {
        //AdditionalLines.Text = ViewModel.AdditionalLines;
        //await AdditionalLinesDialog.ShowAsync();
    }

    private void Add()
    {
        //ViewModel.Add(EntryDialog.DataContext as Entry);
    }

    private void Update()
    {
       // ViewModel.Update(Entries.SelectedIndex, EntryDialog.DataContext as Entry);
    }

    private void Delete()
    {
        ViewModel.DeleteSelected();
    }

    private void UpdateAdditionalLines()
    {
        //ViewModel.UpdateAdditionalLines(AdditionalLines.Text);
    }
}
