namespace HostsUILib.Helpers;

public static class StringHelper
{
    public static string GetHostsWithComment(string hosts, string comment)
    {
        return string.IsNullOrWhiteSpace(comment) ? hosts : string.Concat(hosts, " - ", comment);
    }
}
