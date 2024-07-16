using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ManagedTelemetry;
using ManagedTelemetry.Events;

namespace Hosts.Telemetry;

[EventData]
public class HostsFileEditorOpenedEvent : EventBase, IEvent
{
    public PartA_PrivTags PartA_PrivTags => PartA_PrivTags.ProductAndServiceUsage;
}
