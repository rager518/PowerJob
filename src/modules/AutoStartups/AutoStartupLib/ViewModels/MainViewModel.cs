// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using AutoStartupLib.Helpers;
using AutoStartupLib.Models;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using CommunityToolkit.WinUI;
using CommunityToolkit.WinUI.Collections;
using Microsoft.UI.Dispatching;
using Settings.UI.Library;
using System;
using System.Collections.ObjectModel;
using System.Globalization;
using System.Linq;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace AutoStartupLib.ViewModels;

public partial class MainViewModel : ObservableObject
{
    private readonly DispatcherQueue _dispatcherQueue = DispatcherQueue.GetForCurrentThread();
    private readonly IDuplicateService _duplicateService;

    [ObservableProperty]
    private Entry _selected;

    public MainViewModel(IDuplicateService duplicateService)
    {
        _duplicateService = duplicateService;
    }

    private ObservableCollection<Entry> _entries;
    public AdvancedCollectionView Entries { get; set; }

    public void Add(Entry entry)
    {
        //if (_entries == null) _entries = new ObservableCollection<Entry>();

    

        //if (this.Entries == null || this.Entries.Count == 0)
        //{
        //    Entries = new AdvancedCollectionView(_entries, true);
        //    OnPropertyChanged(nameof(Entries));
        //}

        if (!_entries.Any(e => String.Equals(e.Path, entry.Path, StringComparison.OrdinalIgnoreCase)))
        {
            entry.PropertyChanged += Entry_PropertyChanged;
            _entries.Add(entry);
        }

        //_duplicateService.CheckDuplicates(entry.Name, entry.Path);
    }

    public void DeleteSelected()
    {
        _entries.Remove(Selected);
    }

    [RelayCommand]
    public void ReadSettings()
    {
        var settingsUtils = new SettingsUtils();

        Task.Run(async () =>
        {
            await _dispatcherQueue.EnqueueAsync(() =>
            {
                _entries = new ObservableCollection<Entry>();

                var config = settingsUtils.GetSettingsOrDefault<DataSetting>(DataSetting.ModuleName, DataSetting.DataPath);
                if (config.Files != null)
                {
                    foreach (var entry in config.Files)
                    {
                        var e = new Entry(entry.name, entry.path);
                        this.Add(e);
                    }
                }

                _entries.CollectionChanged += Entries_CollectionChanged;
                Entries = new AdvancedCollectionView(_entries, true);
                OnPropertyChanged(nameof(Entries));
            });

            _duplicateService.Initialize(_entries);
        });
    }

    private void Entries_CollectionChanged(object sender, System.Collections.Specialized.NotifyCollectionChangedEventArgs e)
    {
        _ = Task.Run(SaveAsync);
    }

    public void Entry_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
    {
        _ = Task.Run(SaveAsync);
    }

    private async Task SaveAsync()
    {
        bool error = true;
        string errorMessage = string.Empty;
        bool isReadOnly = false;

        await Task.Delay(1);

        try
        {
            error = false;
            isReadOnly = true;
            var settingsUtils = new SettingsUtils();

            var config = settingsUtils.GetSettingsOrDefault<DataSetting>(DataSetting.ModuleName, DataSetting.DataPath);
            config.Files = new System.Collections.Generic.List<FileInf>();
            foreach (var entry in _entries)
            {
                config.Files.Add(new FileInf(entry.Name, entry.Path));
            }

            settingsUtils.SaveSettings(config.ToJsonString(), DataSetting.ModuleName, DataSetting.DataPath);

            if (isReadOnly && error)
            {

            }
        }
        catch (Exception ex)
        {
            errorMessage = ex.Message;
        }

        await _dispatcherQueue.EnqueueAsync(() =>
        {

        });
    }
}
