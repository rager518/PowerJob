// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_Storage_BulkAccess_1_H
#define WINRT_Windows_Storage_BulkAccess_1_H
#include "winrt/impl/Windows.Storage.BulkAccess.0.h"
WINRT_EXPORT namespace winrt::Windows::Storage::BulkAccess
{
    struct WINRT_IMPL_EMPTY_BASES IFileInformationFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFileInformationFactory>
    {
        IFileInformationFactory(std::nullptr_t = nullptr) noexcept {}
        IFileInformationFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IFileInformationFactoryFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IFileInformationFactoryFactory>
    {
        IFileInformationFactoryFactory(std::nullptr_t = nullptr) noexcept {}
        IFileInformationFactoryFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IStorageItemInformation :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IStorageItemInformation>
    {
        IStorageItemInformation(std::nullptr_t = nullptr) noexcept {}
        IStorageItemInformation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
