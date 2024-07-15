using CommunityToolkit.WinUI.UI.Controls;

using Microsoft.UI.Xaml.Controls;

using PowerJob.ViewModels;

namespace PowerJob.Views;

public sealed partial class ListViewPage : Page
{
    public ListViewViewModel ViewModel
    {
        get;
    }

    public ListViewPage()
    {
        ViewModel = App.GetService<ListViewViewModel>();
        InitializeComponent();
    }

    private void OnViewStateChanged(object sender, ListDetailsViewState e)
    {
        if (e == ListDetailsViewState.Both)
        {
            ViewModel.EnsureItemSelected();
        }
    }
}
