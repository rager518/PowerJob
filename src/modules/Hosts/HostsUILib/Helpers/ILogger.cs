using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HostsUILib.Helpers;
public interface ILogger
{
    public void LogError(string message);

    public void LogError(string message, Exception ex);

    public void LogWarning(string message);

    public void LogInfo(string message);

    public void LogDebug(string message);

    public void LogTrace();
}