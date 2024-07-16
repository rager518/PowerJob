using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ManagedTelemetry.Events;

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
        // https://github.com/microsoft/PowerToys/blob/710f92d99965109fd788d85ebf8b6b9e0ba1524a/src/common/common.cpp#L635
        var version = Assembly.GetExecutingAssembly()?.GetName()?.Version ?? new Version();
        return $"v{version.Major}.{version.Minor}.{version.Build}";
    }
}
