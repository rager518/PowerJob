// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_UI_UIAutomation_Core_2_H
#define WINRT_Windows_UI_UIAutomation_Core_2_H
#include "winrt/impl/Windows.UI.UIAutomation.Core.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::UIAutomation::Core
{
    struct AutomationRemoteOperationOperandId
    {
        int32_t Value;
    };
    inline bool operator==(AutomationRemoteOperationOperandId const& left, AutomationRemoteOperationOperandId const& right) noexcept
    {
        return left.Value == right.Value;
    }
    inline bool operator!=(AutomationRemoteOperationOperandId const& left, AutomationRemoteOperationOperandId const& right) noexcept
    {
        return !(left == right);
    }
    struct WINRT_IMPL_EMPTY_BASES AutomationRemoteOperationResult : winrt::Windows::UI::UIAutomation::Core::IAutomationRemoteOperationResult
    {
        AutomationRemoteOperationResult(std::nullptr_t) noexcept {}
        AutomationRemoteOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::IAutomationRemoteOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CoreAutomationRemoteOperation : winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperation
    {
        CoreAutomationRemoteOperation(std::nullptr_t) noexcept {}
        CoreAutomationRemoteOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperation(ptr, take_ownership_from_abi) {}
        CoreAutomationRemoteOperation();
    };
}
#endif
