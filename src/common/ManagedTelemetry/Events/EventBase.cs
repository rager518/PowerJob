using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace Microsoft.PowerJob.Telemetry.Events;

[EventData]
public class EventBase
{
    public bool UTCReplace_AppSessionGuid => true;

    public string EventName
    {
        get; set;
    }

    private string _version;

    public string Version
    {
        get
        {
            if (string.IsNullOrEmpty(_version))
            {
                _version = GetVersionFromAssembly();
            }

            return _version;
        }
    }

    private string GetVersionFromAssembly()
    {
        // For consistency this should be formatted the same way as
        var version = Assembly.GetExecutingAssembly()?.GetName()?.Version ?? new Version();
        return $"v{version.Major}.{version.Minor}.{version.Build}";
    }
}
