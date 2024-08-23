// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using CommunityToolkit.Mvvm.ComponentModel;

namespace AutoStartupLib.Models;

public partial class Entry : ObservableObject
{
    [ObservableProperty]
    private string _name;
    [ObservableProperty]
    private string _path;

    public Entry(string name, string path)
    {
        Name = name;
        Path = path;
    }
}
