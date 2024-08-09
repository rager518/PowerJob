// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using AutoStartupLib.Models;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CommunityToolkit.WinUI;
using CommunityToolkit.WinUI.Collections;
using Microsoft.UI.Dispatching;
using System.Collections.ObjectModel;
using System.Threading.Tasks;

namespace AutoStartupLib.ViewModels;

public partial class MainViewModel : ObservableObject
{
    private readonly DispatcherQueue _dispatcherQueue = DispatcherQueue.GetForCurrentThread();

    [ObservableProperty]
    private Entry _selected;

    public MainViewModel()
    {
    }

    private ObservableCollection<Entry> _entries;
    public AdvancedCollectionView Entries { get; set; }

    public void Add(Entry entry)
    {
        if (_entries == null) _entries = new ObservableCollection<Entry>();

        _entries.Add(entry);
    }

    public void DeleteSelected()
    {
        _entries.Remove(Selected);
    }


    [RelayCommand]
    public void ReadSettings()
    {

        Task.Run(async () =>
        {
            await _dispatcherQueue.EnqueueAsync(() =>
            {
                this.Add(new Entry("name", "path"));

                Entries = new AdvancedCollectionView(_entries, true);
                OnPropertyChanged(nameof(Entries));
            });
        });
    }

}
