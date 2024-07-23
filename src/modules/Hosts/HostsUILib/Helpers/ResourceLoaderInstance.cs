using Microsoft.Windows.ApplicationModel.Resources;

namespace HostsUILib.Helpers;
internal static class ResourceLoaderInstance
{
    internal static ResourceLoader ResourceLoader
    {
        get; private set;
    }

    static ResourceLoaderInstance()
    {
        ResourceLoader = new Microsoft.Windows.ApplicationModel.Resources.ResourceLoader("PowerJob.HostsUILib.pri", "PowerJob.HostsUILib/Resources");
    }
}