// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_PowerToys_GPOWrapper_2_H
#define WINRT_PowerToys_GPOWrapper_2_H
#include "winrt/impl/PowerToys.GPOWrapper.1.h"
WINRT_EXPORT namespace winrt::PowerToys::GPOWrapper
{
    struct WINRT_IMPL_EMPTY_BASES GPOWrapper : winrt::PowerToys::GPOWrapper::IGPOWrapper
    {
        GPOWrapper(std::nullptr_t) noexcept {}
        GPOWrapper(void* ptr, take_ownership_from_abi_t) noexcept : winrt::PowerToys::GPOWrapper::IGPOWrapper(ptr, take_ownership_from_abi) {}
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredAlwaysOnTopEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredAwakeEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredCmdNotFoundEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredColorPickerEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredCropAndLockEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredFancyZonesEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredFileLocksmithEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredSvgPreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMarkdownPreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMonacoPreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredPdfPreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredGcodePreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredSvgThumbnailsEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredPdfThumbnailsEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredGcodeThumbnailsEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredStlThumbnailsEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredHostsFileEditorEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredImageResizerEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredKeyboardManagerEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredFindMyMouseEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMouseHighlighterEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMouseJumpEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMousePointerCrosshairsEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMouseWithoutBordersEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredPowerRenameEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredPowerLauncherEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredQuickAccentEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredRegistryPreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredScreenRulerEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredShortcutGuideEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredTextExtractorEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredAdvancedPasteEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredVideoConferenceMuteEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredPeekEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetDisableNewUpdateToastValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetDisableAutomaticUpdateDownloadValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetDisableShowWhatsNewAfterUpdatesValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetAllowExperimentationValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetRunPluginEnabledValue(param::hstring const& pluginID);
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredEnvironmentVariablesEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredQoiPreviewEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredQoiThumbnailsEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetAllowedAdvancedPasteOnlineAIModelsValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbClipboardSharingEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbFileTransferEnabledValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbUseOriginalUserInterfaceValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbDisallowBlockingScreensaverValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbSameSubnetOnlyValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbValidateRemoteIpValue();
        static winrt::PowerToys::GPOWrapper::GpoRuleConfigured GetConfiguredMwbDisableUserDefinedIpMappingRulesValue();
        static hstring GetConfiguredMwbPolicyDefinedIpMappingRules();
    };
}
#endif
