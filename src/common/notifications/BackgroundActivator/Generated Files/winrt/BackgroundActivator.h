// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_BackgroundActivator_H
#define WINRT_BackgroundActivator_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.240111.5"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.240111.5"
#include "winrt/impl/Windows.ApplicationModel.Background.2.h"
#include "winrt/impl/BackgroundActivator.2.h"
namespace winrt::impl
{
    template <typename D> auto consume_BackgroundActivator_IBackgroundHandler<D>::Run(winrt::Windows::ApplicationModel::Background::IBackgroundTaskInstance const& taskInstance) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::BackgroundActivator::IBackgroundHandler)->Run(*(void**)(&taskInstance)));
    }
    template <typename D>
    struct produce<D, winrt::BackgroundActivator::IBackgroundHandler> : produce_base<D, winrt::BackgroundActivator::IBackgroundHandler>
    {
        int32_t __stdcall Run(void* taskInstance) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Run(*reinterpret_cast<winrt::Windows::ApplicationModel::Background::IBackgroundTaskInstance const*>(&taskInstance));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
WINRT_EXPORT namespace winrt::BackgroundActivator
{
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::BackgroundActivator::IBackgroundHandler> : winrt::impl::hash_base {};
    template<> struct hash<winrt::BackgroundActivator::BackgroundHandler> : winrt::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
