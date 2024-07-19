using System;
using System.IO.Abstractions;
using System.Threading;
using Common.UI;
using Hosts.Helpers;
using HostsUILib;
using HostsUILib.Helpers;
using HostsUILib.Settings;
using HostsUILib.ViewModels;
using ManagedCommon;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.UI.Xaml;
using static HostsUILib.Settings.IUserSettings;
using Host = Hosts.Helpers.Host;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace Hosts;
/// <summary>
/// Provides application-specific behavior to supplement the default Application class.
/// </summary>
public partial class App : Application
{
    /// <summary>
    /// Initializes the singleton application object.  This is the first line of authored code
    /// executed, and as such is the logical equivalent of main() or WinMain().
    /// </summary>
    public App()
    {
        Host.HostInstance = Microsoft.Extensions.Hosting.Host.
              CreateDefaultBuilder().
              UseContentRoot(AppContext.BaseDirectory).
              ConfigureServices((context, services) =>
              {
                  // Core Services
                  services.AddSingleton<IFileSystem, FileSystem>();
                  services.AddSingleton<IHostsService, HostsService>();
                  services.AddSingleton<IUserSettings, Hosts.Settings.UserSettings>();
                  services.AddSingleton<IElevationHelper, ElevationHelper>();
                  services.AddSingleton<IDuplicateService, DuplicateService>();

                  // Views and ViewModels
                  services.AddSingleton<ILogger, LoggerWrapper>();
                  services.AddSingleton<IElevationHelper, ElevationHelper>();
                  services.AddSingleton<OpenSettingsFunction>(() =>
                  {
                      SettingsDeepLink.OpenSettings(SettingsDeepLink.SettingsWindow.Hosts, true);
                  });

                  services.AddSingleton<MainViewModel, MainViewModel>();
                  services.AddSingleton<HostsMainPage, HostsMainPage>();
              }).
              Build();

        var cleanupBackupThread = new Thread(() =>
        {
            // Delete old backups only if running elevated
            if (!Host.GetService<IElevationHelper>().IsElevated)
            {
                return;
            }

            try
            {
                Host.GetService<IHostsService>().CleanupBackup();
            }
            catch (Exception ex)
            {
                Logger.LogError("Failed to delete backup", ex);
            }
        });

        cleanupBackupThread.IsBackground = true;
        cleanupBackupThread.Start();


        this.InitializeComponent();
    }

    /// <summary>
    /// Invoked when the application is launched.
    /// </summary>
    /// <param name="args">Details about the launch request and process.</param>
    protected override void OnLaunched(Microsoft.UI.Xaml.LaunchActivatedEventArgs args)
    {
        m_window = new MainWindow();
        m_window.Activate();
    }

    private Window m_window;
}
