// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_UI_Xaml_Hosting_0_H
#define WINRT_Windows_UI_Xaml_Hosting_0_H
WINRT_EXPORT namespace winrt::Windows::UI::Composition
{
    struct CompositionPropertySet;
    struct ICompositionAnimationBase;
    struct Visual;
}
WINRT_EXPORT namespace winrt::Windows::UI::WindowManagement
{
    struct AppWindow;
}
WINRT_EXPORT namespace winrt::Windows::UI::Xaml
{
    struct UIElement;
}
WINRT_EXPORT namespace winrt::Windows::UI::Xaml::Controls
{
    struct ScrollViewer;
}
WINRT_EXPORT namespace winrt::Windows::UI::Xaml::Hosting
{
    struct IElementCompositionPreview;
    struct IElementCompositionPreviewStatics;
    struct IElementCompositionPreviewStatics2;
    struct IElementCompositionPreviewStatics3;
    struct ElementCompositionPreview;
}
namespace winrt::impl
{
    template <> struct category<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3>{ using type = interface_category; };
    template <> struct category<winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview> = L"Windows.UI.Xaml.Hosting.ElementCompositionPreview";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview> = L"Windows.UI.Xaml.Hosting.IElementCompositionPreview";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> = L"Windows.UI.Xaml.Hosting.IElementCompositionPreviewStatics";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2> = L"Windows.UI.Xaml.Hosting.IElementCompositionPreviewStatics2";
    template <> inline constexpr auto& name_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3> = L"Windows.UI.Xaml.Hosting.IElementCompositionPreviewStatics3";
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview>{ 0xB6F1A676,0xCFE6,0x46AC,{ 0xAC,0xF6,0xC4,0x68,0x7B,0xB6,0x5E,0x60 } }; // B6F1A676-CFE6-46AC-ACF6-C4687BB65E60
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>{ 0x08C92B38,0xEC99,0x4C55,{ 0xBC,0x85,0xA1,0xC1,0x80,0xB2,0x76,0x46 } }; // 08C92B38-EC99-4C55-BC85-A1C180B27646
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2>{ 0x24148FBB,0x23D6,0x4F37,{ 0xBA,0x0C,0x07,0x33,0xE7,0x99,0x72,0x2D } }; // 24148FBB-23D6-4F37-BA0C-0733E799722D
    template <> inline constexpr guid guid_v<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3>{ 0x843BC4C3,0xC105,0x59FE,{ 0xA3,0xD1,0x37,0x3C,0x1D,0x3E,0x6F,0xBC } }; // 843BC4C3-C105-59FE-A3D1-373C1D3E6FBC
    template <> struct default_interface<winrt::Windows::UI::Xaml::Hosting::ElementCompositionPreview>{ using type = winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview; };
    template <> struct abi<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
        };
    };
    template <> struct abi<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall GetElementVisual(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetElementChildVisual(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetElementChildVisual(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GetScrollViewerManipulationPropertySet(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall SetImplicitShowAnimation(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetImplicitHideAnimation(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetIsTranslationEnabled(void*, bool) noexcept = 0;
            virtual int32_t __stdcall GetPointerPositionPropertySet(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall SetAppWindowContent(void*, void*) noexcept = 0;
            virtual int32_t __stdcall GetAppWindowContent(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Hosting_IElementCompositionPreview
    {
    };
    template <> struct consume<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Hosting_IElementCompositionPreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics
    {
        auto GetElementVisual(winrt::Windows::UI::Xaml::UIElement const& element) const;
        auto GetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element) const;
        auto SetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::Visual const& visual) const;
        auto GetScrollViewerManipulationPropertySet(winrt::Windows::UI::Xaml::Controls::ScrollViewer const& scrollViewer) const;
    };
    template <> struct consume<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics2
    {
        auto SetImplicitShowAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation) const;
        auto SetImplicitHideAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation) const;
        auto SetIsTranslationEnabled(winrt::Windows::UI::Xaml::UIElement const& element, bool value) const;
        auto GetPointerPositionPropertySet(winrt::Windows::UI::Xaml::UIElement const& targetElement) const;
    };
    template <> struct consume<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics3
    {
        auto SetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow, winrt::Windows::UI::Xaml::UIElement const& xamlContent) const;
        auto GetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow) const;
    };
    template <> struct consume<winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics3>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Hosting_IElementCompositionPreviewStatics3<D>;
    };
}
#endif
