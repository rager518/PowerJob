using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.PowerJob.Telemetry;
using Microsoft.PowerJob.Telemetry.Events;

namespace Hosts.Telemetry;

[EventData]
public class HostsFileEditorOpenedEvent : EventBase, IEvent
{
    public PartA_PrivTags PartA_PrivTags => PartA_PrivTags.ProductAndServiceUsage;
}
