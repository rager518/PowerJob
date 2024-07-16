using System;
using Microsoft.Extensions.Hosting;

namespace Hosts.Helpers;
public static class Host
{
    public static IHost HostInstance
    {
        get; set;
    }

    public static T GetService<T>()
        where T : class
    {
        if (HostInstance!.Services.GetService(typeof(T)) is not T service)
        {
            throw new ArgumentException($"{typeof(T)} needs to be registered in ConfigureServices within App.xaml.cs.");
        }

        return service;
    }
}