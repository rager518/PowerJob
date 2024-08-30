using ManagedCommon;
using Microsoft.UI.Xaml.Controls;
using PowerJob.Helpers;
using PowerJob.Views;
using Windows.Data.Json;
using Windows.UI.ViewManagement;

namespace PowerJob;

public sealed partial class MainWindow : WindowEx
{
    private Microsoft.UI.Dispatching.DispatcherQueue dispatcherQueue;

    private UISettings settings;


    public MainWindow(string title)
    {
        InitializeComponent();

        AppWindow.SetIcon(Path.Combine(AppContext.BaseDirectory, "Assets/WindowIcon.ico"));
        Content = null;
        Title = title ?? "AppDisplayName".GetLocalized();

        Logger.LogError("Failed to parse JSON from IPC message.");

        // Theme change code picked from https://github.com/microsoft/WinUI-Gallery/pull/1239
        dispatcherQueue = Microsoft.UI.Dispatching.DispatcherQueue.GetForCurrentThread();
        settings = new UISettings();
        settings.ColorValuesChanged += Settings_ColorValuesChanged; // cannot use FrameworkElement.ActualThemeChanged event

        // send IPC Message
        ShellPage.SetDefaultSndMessageCallback(msg =>
        {
            // IPC Manager is null when launching runner directly
            App.GetTwoWayIPCManager()?.Send(msg);
        });


        ShellPage.SetUpdatingGeneralSettingsCallback((ModuleType moduleType, bool isEnabled) =>
        {
            //SettingsRepository<GeneralSettings> repository = SettingsRepository<GeneralSettings>.GetInstance(new SettingsUtils());
            //GeneralSettings generalSettingsConfig = repository.SettingsConfig;
            bool needToUpdate = false; // ModuleHelper.GetIsModuleEnabled(generalSettingsConfig, moduleType) != isEnabled;

            //if (needToUpdate)
            //{
            //    ModuleHelper.SetIsModuleEnabled(generalSettingsConfig, moduleType, isEnabled);
            //    var outgoing = new OutGoingGeneralSettings(generalSettingsConfig);
            //    this.DispatcherQueue.TryEnqueue(Microsoft.UI.Dispatching.DispatcherQueuePriority.Normal, () =>
            //    {
            //        ShellPage.SendDefaultIPCMessage(outgoing.ToString());
            //        ShellPage.ShellHandler?.SignalGeneralDataUpdate();
            //    });
            //}

            return needToUpdate;
        });


        // receive IPC Message
        App.IPCMessageReceivedCallback = (string msg) =>
        {
            if (ShellPage.ShellHandler.IPCResponseHandleList != null)
            {
                var success = JsonObject.TryParse(msg, out JsonObject json);
                if (success)
                {
                    foreach (Action<JsonObject> handle in ShellPage.ShellHandler.IPCResponseHandleList)
                    {
                        handle(json);
                    }
                }
                else
                {
                    Logger.LogError("Failed to parse JSON from IPC message.");
                }
            }
        };

    }

    // this handles updating the caption button colors correctly when indows system theme is changed
    // while the app is open
    private void Settings_ColorValuesChanged(UISettings sender, object args)
    {
        // This calls comes off-thread, hence we will need to dispatch it to current app's thread
        dispatcherQueue.TryEnqueue(() =>
        {
            TitleBarHelper.ApplySystemThemeToCaptionButtons();
        });
    }
}
