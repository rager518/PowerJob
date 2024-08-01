// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_UI_Input_Inking_Core_2_H
#define WINRT_Windows_UI_Input_Inking_Core_2_H
#include "winrt/impl/Windows.Foundation.Numerics.1.h"
#include "winrt/impl/Windows.UI.Input.Inking.1.h"
#include "winrt/impl/Windows.UI.Input.Inking.Core.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::Input::Inking::Core
{
    struct WINRT_IMPL_EMPTY_BASES CoreIncrementalInkStroke : winrt::Windows::UI::Input::Inking::Core::ICoreIncrementalInkStroke
    {
        CoreIncrementalInkStroke(std::nullptr_t) noexcept {}
        CoreIncrementalInkStroke(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Input::Inking::Core::ICoreIncrementalInkStroke(ptr, take_ownership_from_abi) {}
        CoreIncrementalInkStroke(winrt::Windows::UI::Input::Inking::InkDrawingAttributes const& drawingAttributes, winrt::Windows::Foundation::Numerics::float3x2 const& pointTransform);
    };
    struct WINRT_IMPL_EMPTY_BASES CoreInkIndependentInputSource : winrt::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource
    {
        CoreInkIndependentInputSource(std::nullptr_t) noexcept {}
        CoreInkIndependentInputSource(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource(ptr, take_ownership_from_abi) {}
        static auto Create(winrt::Windows::UI::Input::Inking::InkPresenter const& inkPresenter);
    };
    struct WINRT_IMPL_EMPTY_BASES CoreInkPresenterHost : winrt::Windows::UI::Input::Inking::Core::ICoreInkPresenterHost
    {
        CoreInkPresenterHost(std::nullptr_t) noexcept {}
        CoreInkPresenterHost(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Input::Inking::Core::ICoreInkPresenterHost(ptr, take_ownership_from_abi) {}
        CoreInkPresenterHost();
    };
    struct WINRT_IMPL_EMPTY_BASES CoreWetStrokeUpdateEventArgs : winrt::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs
    {
        CoreWetStrokeUpdateEventArgs(std::nullptr_t) noexcept {}
        CoreWetStrokeUpdateEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CoreWetStrokeUpdateSource : winrt::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource
    {
        CoreWetStrokeUpdateSource(std::nullptr_t) noexcept {}
        CoreWetStrokeUpdateSource(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource(ptr, take_ownership_from_abi) {}
        static auto Create(winrt::Windows::UI::Input::Inking::InkPresenter const& inkPresenter);
    };
}
#endif
