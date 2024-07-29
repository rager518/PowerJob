using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.PowerJob.Telemetry;

namespace Microsoft.PowerJob.Telemetry.Events;
public interface IEvent
{
    PartA_PrivTags PartA_PrivTags
    {
        get;
    }
}
