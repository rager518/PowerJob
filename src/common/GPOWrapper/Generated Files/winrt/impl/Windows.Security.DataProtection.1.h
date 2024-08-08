// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_Security_DataProtection_1_H
#define WINRT_Windows_Security_DataProtection_1_H
#include "winrt/impl/Windows.Security.DataProtection.0.h"
WINRT_EXPORT namespace winrt::Windows::Security::DataProtection
{
    struct WINRT_IMPL_EMPTY_BASES IUserDataAvailabilityStateChangedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IUserDataAvailabilityStateChangedEventArgs>
    {
        IUserDataAvailabilityStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataAvailabilityStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IUserDataBufferUnprotectResult :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IUserDataBufferUnprotectResult>
    {
        IUserDataBufferUnprotectResult(std::nullptr_t = nullptr) noexcept {}
        IUserDataBufferUnprotectResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IUserDataProtectionManager :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IUserDataProtectionManager>
    {
        IUserDataProtectionManager(std::nullptr_t = nullptr) noexcept {}
        IUserDataProtectionManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IUserDataProtectionManagerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IUserDataProtectionManagerStatics>
    {
        IUserDataProtectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDataProtectionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IUserDataStorageItemProtectionInfo :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IUserDataStorageItemProtectionInfo>
    {
        IUserDataStorageItemProtectionInfo(std::nullptr_t = nullptr) noexcept {}
        IUserDataStorageItemProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
