using interop;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;
using Microsoft.UI.Xaml;
using PowerJob.Activation;
using PowerJob.Contracts.Services;
using PowerJob.Core.Contracts.Services;
using PowerJob.Core.Services;
using PowerJob.Helpers;
using PowerJob.Models;
using PowerJob.Notifications;
using PowerJob.Services;
using PowerJob.ViewModels;
using PowerJob.Views;
using Windows.UI.Popups;
using WinRT.Interop;

namespace PowerJob;

// To learn more about WinUI 3, see https://docs.microsoft.com/windows/apps/winui/winui3/.
public partial class App : Application
{
    private enum Arguments
    {
        PTPipeName = 1,
        SettingsPipeName,
        PTPid,
        Theme, // used in the old settings
        ElevatedStatus,
        IsUserAdmin,
        ShowOobeWindow,
        ShowScoobeWindow,
        ShowFlyout,
        ContainsSettingsWindow,
        ContainsFlyoutPosition,
    }

    private const int RequiredArgumentsLaunchedFromRunnerQty = 12;

    // The .NET Generic Host provides dependency injection, configuration, logging, and other services.
    // https://docs.microsoft.com/dotnet/core/extensions/generic-host
    // https://docs.microsoft.com/dotnet/core/extensions/dependency-injection
    // https://docs.microsoft.com/dotnet/core/extensions/configuration
    // https://docs.microsoft.com/dotnet/core/extensions/logging
    public IHost Host
    {
        get;
    }

    public static T GetService<T>()
        where T : class
    {
        if ((App.Current as App)!.Host.Services.GetService(typeof(T)) is not T service)
        {
            throw new ArgumentException($"{typeof(T)} needs to be registered in ConfigureServices within App.xaml.cs.");
        }

        return service;
    }

    public static bool IsElevated
    {
        get; set;
    }
    public static MainWindow MainWindow { get; set; }

    public static UIElement AppTitlebar { get; set; }

    public App()
    {
        InitializeComponent();

        Host = Microsoft.Extensions.Hosting.Host.
        CreateDefaultBuilder().
        UseContentRoot(AppContext.BaseDirectory).
        ConfigureServices((context, services) =>
        {
            // Default Activation Handler
            services.AddTransient<ActivationHandler<LaunchActivatedEventArgs>, DefaultActivationHandler>();

            // Other Activation Handlers
            services.AddTransient<IActivationHandler, AppNotificationActivationHandler>();

            // Services
            services.AddSingleton<IAppNotificationService, AppNotificationService>();
            services.AddSingleton<ILocalSettingsService, LocalSettingsService>();
            services.AddSingleton<IThemeSelectorService, ThemeSelectorService>();
            services.AddTransient<IWebViewService, WebViewService>();
            services.AddTransient<INavigationViewService, NavigationViewService>();

            services.AddSingleton<IActivationService, ActivationService>();
            services.AddSingleton<IPageService, PageService>();
            services.AddSingleton<INavigationService, NavigationService>();

            // Core Services
            services.AddSingleton<ISampleDataService, SampleDataService>();
            services.AddSingleton<IFileService, FileService>();

            // Views and ViewModels
            services.AddTransient<PowerStartupViewModel>();
            services.AddTransient<PowerStartupPage>();
            services.AddTransient<SettingsViewModel>();
            services.AddTransient<SettingsPage>();
            services.AddTransient<ContentGridDetailViewModel>();
            services.AddTransient<ContentGridDetailPage>();
            services.AddTransient<ContentGridViewModel>();
            services.AddTransient<ContentGridPage>();
            services.AddTransient<ListViewViewModel>();
            services.AddTransient<ListViewPage>();
            services.AddTransient<WebViewViewModel>();
            services.AddTransient<WebViewPage>();
            services.AddTransient<MainViewModel>();
            services.AddTransient<MainPage>();
            services.AddTransient<ShellPage>();
            services.AddTransient<ShellViewModel>();
            services.AddTransient<AutoStartupPage>();
            services.AddTransient<AutoStartupViewModel>();

            // Configuration
            services.Configure<LocalSettingsOptions>(context.Configuration.GetSection(nameof(LocalSettingsOptions)));
        }).
        Build();

        App.GetService<IAppNotificationService>().Initialize();

        UnhandledException += App_UnhandledException;
    }

    private static TwoWayPipeMessageIPCManaged ipcmanager;
    public static TwoWayPipeMessageIPCManaged GetTwoWayIPCManager()
    {
        return ipcmanager;
    }

    public static Action<string> IPCMessageReceivedCallback { get; set; }

    private void App_UnhandledException(object sender, Microsoft.UI.Xaml.UnhandledExceptionEventArgs e)
    {
        // TODO: Log and handle exceptions as appropriate.
        // https://docs.microsoft.com/windows/windows-app-sdk/api/winrt/microsoft.ui.xaml.application.unhandledexception.
    }

    private async void ShowMessageDialog(string content, string title = null)
    {
        await ShowDialogAsync(content, title);
    }

    public static Task<IUICommand> ShowDialogAsync(string content, string title = null)
    {
        var dialog = new MessageDialog(content, title ?? string.Empty);
        var handle = NativeMethods.GetActiveWindow();
        if (handle == IntPtr.Zero)
        {
            throw new InvalidOperationException();
        }

        InitializeWithWindow.Initialize(dialog, handle);
        return dialog.ShowAsync().AsTask<IUICommand>();
    }


    protected async override void OnLaunched(LaunchActivatedEventArgs args)
    {
        base.OnLaunched(args);
        var cmdArgs = Environment.GetCommandLineArgs();

        var title = "";


        if (cmdArgs.Length >= RequiredArgumentsLaunchedFromRunnerQty)
        {
            // \\.\pipe\powerjob_runner_03f36e16-43cf-460a-9945-fb2d613a551d
            // \\.\pipe\powerjob_settings_

            ipcmanager = new TwoWayPipeMessageIPCManaged(cmdArgs[(int)Arguments.SettingsPipeName], cmdArgs[(int)Arguments.PTPipeName], (string message) =>
            {
                if (IPCMessageReceivedCallback != null && message.Length > 0)
                {
                    IPCMessageReceivedCallback(message);
                }
            });
            ipcmanager.Start();

            title = "Pro Mode";
        }
        else
        {
            //var guid = Guid.NewGuid();
            //var pipeName = $"\\\\.\\pipe\\powerjob_runner_{guid}";
            //var settingName = $"\\\\.\\pipe\\powerjob_settings_{guid}";

            //ipcmanager = new TwoWayPipeMessageIPCManaged(settingName, pipeName, (string message) =>
            //{
            //    if (IPCMessageReceivedCallback != null && message.Length > 0)
            //    {
            //        IPCMessageReceivedCallback(message);
            //    }
            //});
            //ipcmanager.Start();

            title = "Debug Mode";
        }


        // title = cmdArgs.Length.ToString();

        MainWindow = new MainWindow(title);

        App.GetService<IAppNotificationService>().Show(string.Format("AppNotificationSamplePayload".GetLocalized(), AppContext.BaseDirectory));

        await App.GetService<IActivationService>().ActivateAsync(args);
    }

    //private static MainWindow settingsWindow;
    public static MainWindow GetSettingsWindow()
    {
        return MainWindow;
    }
}
