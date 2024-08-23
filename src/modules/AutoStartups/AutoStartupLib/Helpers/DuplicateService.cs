// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using AutoStartupLib.Models;
using Microsoft.UI.Dispatching;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace AutoStartupLib.Helpers;

public class DuplicateService : IDuplicateService, IDisposable
{
    private readonly DispatcherQueue _dispatcherQueue;
    private record struct Check(string Name, string Path);
    private readonly Queue<Check> _checkQueue;
    private readonly ManualResetEvent _checkEvent;
    private readonly Thread _queueThread;


    private ReadOnlyCollection<Entry> _entries;
    private bool _disposed;

    public DuplicateService()
    {
        _dispatcherQueue = DispatcherQueue.GetForCurrentThread();
        _checkQueue = new Queue<Check>();
        _checkEvent = new ManualResetEvent(false);

        _queueThread = new Thread(ProcessQueue);
        _queueThread.IsBackground = true;
        _queueThread.Start();
    }

    public void Dispose()
    {
        Dispose(disposing: true);
        GC.SuppressFinalize(this);
    }

    void IDuplicateService.CheckDuplicates(string name, string path)
    {
        _checkQueue.Enqueue(new Check(name, path));
        _checkEvent.Set();
    }

    void IDuplicateService.Initialize(IList<Entry> entries)
    {
        _entries = entries.AsReadOnly();

        if (_checkQueue.Count > 0)
        {
            _checkQueue.Clear();
        }

        foreach (var entry in _entries)
        {
            _checkQueue.Enqueue(new Check(entry.Name, entry.Path));
        }

        _checkEvent.Set();
    }

    private void ProcessQueue()
    {
        while (true)
        {
            _checkEvent.WaitOne();

            while (_checkQueue.Count > 0)
            {
                var check = _checkQueue.Dequeue();
                FindDuplicates(check.Name, check.Path);
            }

            _checkEvent.Reset();
        }
    }

    private void FindDuplicates(string name, string path)
    {
        if (_entries == null) return;

        var entries = _entries.Where(e => String.Equals(e.Path, path, StringComparison.OrdinalIgnoreCase));

        foreach (var entry in entries)
        {
            SetDuplicate(entry);
        }
    }

    private void SetDuplicate(Entry entry)
    {
        _dispatcherQueue.TryEnqueue(() => entry.Path = entry.Path);
    }

    protected virtual void Dispose(bool disposing)
    {
        if (!_disposed)
        {
            if (disposing)
            {
                _checkEvent?.Dispose();
                _disposed = true;
            }
        }
    }
}
