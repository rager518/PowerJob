// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_Devices_Background_1_H
#define WINRT_Windows_Devices_Background_1_H
#include "winrt/impl/Windows.Devices.Background.0.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Background
{
    struct WINRT_IMPL_EMPTY_BASES IDeviceServicingDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDeviceServicingDetails>
    {
        IDeviceServicingDetails(std::nullptr_t = nullptr) noexcept {}
        IDeviceServicingDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IDeviceUseDetails :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDeviceUseDetails>
    {
        IDeviceUseDetails(std::nullptr_t = nullptr) noexcept {}
        IDeviceUseDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
