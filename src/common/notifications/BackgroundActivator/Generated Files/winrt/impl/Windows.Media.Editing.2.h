// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_Media_Editing_2_H
#define WINRT_Windows_Media_Editing_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Graphics.DirectX.Direct3D11.1.h"
#include "winrt/impl/Windows.Media.Effects.1.h"
#include "winrt/impl/Windows.Storage.1.h"
#include "winrt/impl/Windows.UI.1.h"
#include "winrt/impl/Windows.Media.Editing.1.h"
WINRT_EXPORT namespace winrt::Windows::Media::Editing
{
    struct WINRT_IMPL_EMPTY_BASES BackgroundAudioTrack : winrt::Windows::Media::Editing::IBackgroundAudioTrack
    {
        BackgroundAudioTrack(std::nullptr_t) noexcept {}
        BackgroundAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Media::Editing::IBackgroundAudioTrack(ptr, take_ownership_from_abi) {}
        static auto CreateFromEmbeddedAudioTrack(winrt::Windows::Media::Editing::EmbeddedAudioTrack const& embeddedAudioTrack);
        static auto CreateFromFileAsync(winrt::Windows::Storage::IStorageFile const& file);
    };
    struct WINRT_IMPL_EMPTY_BASES EmbeddedAudioTrack : winrt::Windows::Media::Editing::IEmbeddedAudioTrack
    {
        EmbeddedAudioTrack(std::nullptr_t) noexcept {}
        EmbeddedAudioTrack(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Media::Editing::IEmbeddedAudioTrack(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MediaClip : winrt::Windows::Media::Editing::IMediaClip
    {
        MediaClip(std::nullptr_t) noexcept {}
        MediaClip(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Media::Editing::IMediaClip(ptr, take_ownership_from_abi) {}
        static auto CreateFromColor(winrt::Windows::UI::Color const& color, winrt::Windows::Foundation::TimeSpan const& originalDuration);
        static auto CreateFromFileAsync(winrt::Windows::Storage::IStorageFile const& file);
        static auto CreateFromImageFileAsync(winrt::Windows::Storage::IStorageFile const& file, winrt::Windows::Foundation::TimeSpan const& originalDuration);
        static auto CreateFromSurface(winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface const& surface, winrt::Windows::Foundation::TimeSpan const& originalDuration);
    };
    struct WINRT_IMPL_EMPTY_BASES MediaComposition : winrt::Windows::Media::Editing::IMediaComposition,
        impl::require<MediaComposition, winrt::Windows::Media::Editing::IMediaComposition2>
    {
        MediaComposition(std::nullptr_t) noexcept {}
        MediaComposition(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Media::Editing::IMediaComposition(ptr, take_ownership_from_abi) {}
        MediaComposition();
        static auto LoadAsync(winrt::Windows::Storage::StorageFile const& file);
    };
    struct WINRT_IMPL_EMPTY_BASES MediaOverlay : winrt::Windows::Media::Editing::IMediaOverlay
    {
        MediaOverlay(std::nullptr_t) noexcept {}
        MediaOverlay(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Media::Editing::IMediaOverlay(ptr, take_ownership_from_abi) {}
        explicit MediaOverlay(winrt::Windows::Media::Editing::MediaClip const& clip);
        MediaOverlay(winrt::Windows::Media::Editing::MediaClip const& clip, winrt::Windows::Foundation::Rect const& position, double opacity);
    };
    struct WINRT_IMPL_EMPTY_BASES MediaOverlayLayer : winrt::Windows::Media::Editing::IMediaOverlayLayer
    {
        MediaOverlayLayer(std::nullptr_t) noexcept {}
        MediaOverlayLayer(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Media::Editing::IMediaOverlayLayer(ptr, take_ownership_from_abi) {}
        MediaOverlayLayer();
        explicit MediaOverlayLayer(winrt::Windows::Media::Effects::IVideoCompositorDefinition const& compositorDefinition);
    };
}
#endif
