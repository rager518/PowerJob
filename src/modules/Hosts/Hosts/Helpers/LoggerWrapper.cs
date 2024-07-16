using System;
using HostsUILib.Helpers;
using ManagedCommon;

namespace Hosts.Helpers;


internal sealed class LoggerWrapper : ILogger
{
    public void LogDebug(string message)
    {
        Logger.LogDebug(message);
    }

    public void LogError(string message)
    {
        Logger.LogError(message);
    }

    public void LogError(string message, Exception ex)
    {
        Logger.LogError(message, ex);
    }

    public void LogInfo(string message)
    {
        Logger.LogInfo(message);
    }

    public void LogTrace()
    {
        Logger.LogTrace();
    }

    public void LogWarning(string message)
    {
        Logger.LogWarning(message);
    }
}