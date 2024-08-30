﻿// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace PowerJob.Helpers;

[Serializable]
[StructLayout(LayoutKind.Sequential)]
public struct POINT
{
    public int X { get; set; }

    public int Y { get; set; }

    public POINT(int x, int y)
    {
        X = x;
        Y = y;
    }
}
