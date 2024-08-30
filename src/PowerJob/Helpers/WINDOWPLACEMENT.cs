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
public struct WINDOWPLACEMENT
{
    public int Length { get; set; }

    public int Flags { get; set; }

    public int ShowCmd { get; set; }

    public POINT MinPosition { get; set; }

    public POINT MaxPosition { get; set; }

    public RECT NormalPosition { get; set; }
}
