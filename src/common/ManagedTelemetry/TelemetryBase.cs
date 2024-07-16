using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ManagedTelemetry;
/// <summary>
/// Privacy Tag values
/// </summary>
public enum PartA_PrivTags
       : ulong
{
    /// <nodoc/>
    None = 0,

    /// <nodoc/>
    ProductAndServicePerformance = 1,

    /// <nodoc/>
    ProductAndServiceUsage = 2,
}

/// <summary>
/// Base class for telemetry events.
/// </summary>
public class TelemetryBase : EventSource
{
    /// <summary>
    /// The event tag for this event source.
    /// </summary>
    public const EventTags ProjectTelemetryTagProductAndServicePerformance = (EventTags)0x0u;

    /// <summary>
    /// The event keyword for this event source.
    /// </summary>
    public const EventKeywords ProjectKeywordMeasure = (EventKeywords)0x0;

    /// <summary>
    /// Group ID for Powertoys project.
    /// </summary>
    private static readonly string[] PowerToysTelemetryTraits = { "ETW_GROUP", "{42749043-438c-46a2-82be-c6cbeb192ff2}" };

    /// <summary>
    /// Initializes a new instance of the <see cref="TelemetryBase"/> class.
    /// </summary>
    /// <param name="eventSourceName">.</param>
    public TelemetryBase(
        string eventSourceName)
        : base(
        eventSourceName,
        EventSourceSettings.EtwSelfDescribingEventFormat,
        PowerToysTelemetryTraits)
    {
        return;
    }
}
