// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using AutoStartupLib.Models;
using System.Collections.Generic;

namespace AutoStartupLib.Helpers;

public interface IDuplicateService
{
    void Initialize(IList<Entry> entries);
    void CheckDuplicates(string name, string path);
}
