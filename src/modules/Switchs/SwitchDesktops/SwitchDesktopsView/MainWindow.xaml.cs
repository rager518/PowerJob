// Copyright (c) Microsoft Corporation
// The Microsoft Corporation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.

using Microsoft.UI.Dispatching;
using Microsoft.UI.Xaml;
using SwitchDesktops.SwitchDesktopsView;
using Vanara.PInvoke;
using WinUIEx;
using static Vanara.PInvoke.User32;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace SwitchDesktops;

/// <summary>
/// An empty window that can be used on its own or navigated to within a Frame.
/// </summary>
public sealed partial class MainWindow : WindowEx
{
    private readonly DispatcherQueue _dispatcherQueue = DispatcherQueue.GetForCurrentThread();
    public MainWindow()
    {
        this.InitializeComponent();

        //this.Title = "Switch";
        this.SetIcon("./Assets/fav.ico");
        this.ExtendsContentIntoTitleBar = true;
        this.SetTitleBar(null);

        this.Height = 100;

        this.IsMinimizable = false;
        this.IsMaximizable = false;

        this.IsAlwaysOnTop = true;
        this.IsShownInSwitchers = true;
        this.IsResizable = false;
        //this.IsTitleBarVisible = true;


        this.CenterOnScreen();

        WindowStyle style = this.GetWindowStyle();
        style &= ~(WindowStyle.Caption | WindowStyle.Border | WindowStyle.ThickFrame);
        this.SetWindowStyle(style);

        this.Move(4250, 50);

        //RemoveBorder();

        //Task.Run(async () =>
        //{
        //    await _dispatcherQueue.EnqueueAsync(() =>
        //    {
        //        RemoveBorder();
        //    });
        //});
    }

    private void RemoveBorder()
    {
        //var hWnd = WinRT.Interop.WindowNative.GetWindowHandle(this);
        var hWnd = this.GetWindowHandle();

        WindowStyles style = (WindowStyles)User32.GetWindowLong(hWnd, WindowLongFlags.GWL_STYLE);

        // Remove WS_BORDER and WS_THICKFRAME to remove the border
        style &= ~(User32.WindowStyles.WS_SYSMENU | User32.WindowStyles.WS_CAPTION | User32.WindowStyles.WS_CLIPSIBLINGS | User32.WindowStyles.WS_BORDER | User32.WindowStyles.WS_THICKFRAME);

        // Apply the new style
        User32.SetWindowLong(hWnd, WindowLongFlags.GWL_STYLE, (int)style);
    }

    private void MainGrid_Loaded(object sender, RoutedEventArgs e)
    {
        MainGrid.Children.Add(new SwitchPage());
    }
}
