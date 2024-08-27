// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Microsoft.PowerJob.Telemetry.Events;
using Microsoft.PowerJob.Telemetry;
using System.Diagnostics.Tracing;

namespace Microsoft.PowerJob.Telemetry.Events
{
    [EventData]
    public class DebugEvent : EventBase, IEvent
    {
        public string Message { get; set; }

        public PartA_PrivTags PartA_PrivTags => PartA_PrivTags.ProductAndServicePerformance;
    }
}
