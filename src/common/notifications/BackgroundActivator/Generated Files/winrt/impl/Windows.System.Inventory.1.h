// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_System_Inventory_1_H
#define WINRT_Windows_System_Inventory_1_H
#include "winrt/impl/Windows.System.Inventory.0.h"
WINRT_EXPORT namespace winrt::Windows::System::Inventory
{
    struct WINRT_IMPL_EMPTY_BASES IInstalledDesktopApp :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IInstalledDesktopApp>
    {
        IInstalledDesktopApp(std::nullptr_t = nullptr) noexcept {}
        IInstalledDesktopApp(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IInstalledDesktopAppStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IInstalledDesktopAppStatics>
    {
        IInstalledDesktopAppStatics(std::nullptr_t = nullptr) noexcept {}
        IInstalledDesktopAppStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
