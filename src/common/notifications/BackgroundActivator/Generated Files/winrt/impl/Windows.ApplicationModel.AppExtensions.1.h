// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_ApplicationModel_AppExtensions_1_H
#define WINRT_Windows_ApplicationModel_AppExtensions_1_H
#include "winrt/impl/Windows.ApplicationModel.AppExtensions.0.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::AppExtensions
{
    struct WINRT_IMPL_EMPTY_BASES IAppExtension :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtension>
    {
        IAppExtension(std::nullptr_t = nullptr) noexcept {}
        IAppExtension(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionCatalog :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionCatalog>
    {
        IAppExtensionCatalog(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionCatalog(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionCatalogStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionCatalogStatics>
    {
        IAppExtensionCatalogStatics(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionCatalogStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionPackageInstalledEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageInstalledEventArgs>
    {
        IAppExtensionPackageInstalledEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageInstalledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionPackageStatusChangedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageStatusChangedEventArgs>
    {
        IAppExtensionPackageStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionPackageUninstallingEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageUninstallingEventArgs>
    {
        IAppExtensionPackageUninstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionPackageUpdatedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageUpdatedEventArgs>
    {
        IAppExtensionPackageUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IAppExtensionPackageUpdatingEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IAppExtensionPackageUpdatingEventArgs>
    {
        IAppExtensionPackageUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppExtensionPackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif