// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_Graphics_DirectX_Direct3D11_1_H
#define WINRT_Windows_Graphics_DirectX_Direct3D11_1_H
#include "winrt/impl/Windows.Foundation.0.h"
#include "winrt/impl/Windows.Graphics.DirectX.Direct3D11.0.h"
WINRT_EXPORT namespace winrt::Windows::Graphics::DirectX::Direct3D11
{
    struct WINRT_IMPL_EMPTY_BASES IDirect3DDevice :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDirect3DDevice>,
        impl::require<winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice, winrt::Windows::Foundation::IClosable>
    {
        IDirect3DDevice(std::nullptr_t = nullptr) noexcept {}
        IDirect3DDevice(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES IDirect3DSurface :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IDirect3DSurface>,
        impl::require<winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface, winrt::Windows::Foundation::IClosable>
    {
        IDirect3DSurface(std::nullptr_t = nullptr) noexcept {}
        IDirect3DSurface(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
