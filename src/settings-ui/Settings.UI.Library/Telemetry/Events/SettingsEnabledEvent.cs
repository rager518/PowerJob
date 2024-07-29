// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Microsoft.PowerJob.Telemetry.Events;
using Microsoft.PowerJob.Telemetry;
using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Settings.UI.Library.Telemetry.Events
{
    [EventData]
    public class SettingsEnabledEvent : EventBase, IEvent
    {
        public string Name { get; set; }

        public bool Value { get; set; }

        public PartA_PrivTags PartA_PrivTags => PartA_PrivTags.ProductAndServiceUsage;
    }
}
