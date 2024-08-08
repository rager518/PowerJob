#include "pch.h"
#include "GPOWrapper.h"
#include "GPOWrapper.g.cpp"

namespace winrt::PowerToys::GPOWrapper::implementation
{
    GpoRuleConfigured GPOWrapper::GetConfiguredAlwaysOnTopEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredAlwaysOnTopEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredAwakeEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredAwakeEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredCmdNotFoundEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredCmdNotFoundEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredColorPickerEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredColorPickerEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredCropAndLockEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredCropAndLockEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredFancyZonesEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredFancyZonesEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredFileLocksmithEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredFileLocksmithEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredSvgPreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredSvgPreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMarkdownPreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMarkdownPreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMonacoPreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMonacoPreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredPdfPreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredPdfPreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredGcodePreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredGcodePreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredSvgThumbnailsEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredSvgThumbnailsEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredPdfThumbnailsEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredPdfThumbnailsEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredGcodeThumbnailsEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredGcodeThumbnailsEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredStlThumbnailsEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredStlThumbnailsEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredHostsFileEditorEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredHostsFileEditorEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredImageResizerEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredImageResizerEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredKeyboardManagerEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredKeyboardManagerEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredFindMyMouseEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredFindMyMouseEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMouseHighlighterEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMouseHighlighterEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMouseJumpEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMouseJumpEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMousePointerCrosshairsEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMousePointerCrosshairsEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredPowerRenameEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredPowerRenameEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredPowerLauncherEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredPowerLauncherEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredQuickAccentEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredQuickAccentEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredRegistryPreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredRegistryPreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredScreenRulerEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredScreenRulerEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredShortcutGuideEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredShortcutGuideEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredTextExtractorEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredTextExtractorEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredAdvancedPasteEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredAdvancedPasteEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredVideoConferenceMuteEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredVideoConferenceMuteEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMouseWithoutBordersEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMouseWithoutBordersEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredPeekEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredPeekEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetDisableNewUpdateToastValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getDisableNewUpdateToastValue());
    }
    GpoRuleConfigured GPOWrapper::GetDisableAutomaticUpdateDownloadValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getDisableAutomaticUpdateDownloadValue());
    }
    GpoRuleConfigured GPOWrapper::GetDisableShowWhatsNewAfterUpdatesValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getDisableShowWhatsNewAfterUpdatesValue());
    }
    GpoRuleConfigured GPOWrapper::GetAllowExperimentationValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getAllowExperimentationValue());
    }
    GpoRuleConfigured GPOWrapper::GetRunPluginEnabledValue(winrt::hstring const& pluginID)
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getRunPluginEnabledValue(winrt::to_string(pluginID)));
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredEnvironmentVariablesEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredEnvironmentVariablesEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredQoiPreviewEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredQoiPreviewEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredQoiThumbnailsEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredQoiThumbnailsEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetAllowedAdvancedPasteOnlineAIModelsValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getAllowedAdvancedPasteOnlineAIModelsValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbClipboardSharingEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbClipboardSharingEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbFileTransferEnabledValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbFileTransferEnabledValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbUseOriginalUserInterfaceValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbUseOriginalUserInterfaceValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbDisallowBlockingScreensaverValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbDisallowBlockingScreensaverValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbSameSubnetOnlyValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbSameSubnetOnlyValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbValidateRemoteIpValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbValidateRemoteIpValue());
    }
    GpoRuleConfigured GPOWrapper::GetConfiguredMwbDisableUserDefinedIpMappingRulesValue()
    {
        return static_cast<GpoRuleConfigured>(PowerJob_gpo::getConfiguredMwbDisableUserDefinedIpMappingRulesValue());
    }
    winrt::hstring GPOWrapper::GetConfiguredMwbPolicyDefinedIpMappingRules()
    {
        // Assuming PowerJob_gpo::getConfiguredMwbPolicyDefinedIpMappingRules() returns a std::wstring
        std::wstring rules = PowerJob_gpo::getConfiguredMwbPolicyDefinedIpMappingRules();

        // Convert std::wstring to winrt::hstring
        return to_hstring(rules.c_str());
    }
}
