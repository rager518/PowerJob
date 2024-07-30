// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using System.Diagnostics.Tracing;
using Microsoft.PowerJob.Telemetry.Events;

namespace Microsoft.PowerJob.Telemetry
{
    /// <summary>
    /// Telemetry helper class for PowerJob.
    /// </summary>
    public class PowerJobTelemetry : TelemetryBase
    {
        /// <summary>
        /// Name for ETW event.
        /// </summary>
        private const string EventSourceName = "Microsoft.PowerJob";

        /// <summary>
        /// Initializes a new instance of the <see cref="PowerJobTelemetry"/> class.
        /// </summary>
        public PowerJobTelemetry()
            : base(EventSourceName)
        {
        }

        /// <summary>
        /// Gets an instance of the <see cref="PowerLauncherTelemetry"/> class.
        /// </summary>
        public static PowerJobTelemetry Log { get; } = new PowerJobTelemetry();

        /// <summary>
        /// Publishes ETW event when an action is triggered on
        /// </summary>
        public void WriteEvent<T>(T telemetryEvent)
            where T : EventBase, IEvent
        {
            this.Write<T>(
                telemetryEvent.EventName,
                new EventSourceOptions()
                {
                    Keywords = ProjectKeywordMeasure,
                    Tags = ProjectTelemetryTagProductAndServicePerformance,
                },
                telemetryEvent);
        }
    }
}
