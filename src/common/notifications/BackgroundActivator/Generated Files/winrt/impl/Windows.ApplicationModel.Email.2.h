// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_ApplicationModel_Email_2_H
#define WINRT_Windows_ApplicationModel_Email_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.ApplicationModel.Email.1.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::Email
{
    struct WINRT_IMPL_EMPTY_BASES EmailAttachment : winrt::Windows::ApplicationModel::Email::IEmailAttachment,
        impl::require<EmailAttachment, winrt::Windows::ApplicationModel::Email::IEmailAttachment2>
    {
        EmailAttachment(std::nullptr_t) noexcept {}
        EmailAttachment(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailAttachment(ptr, take_ownership_from_abi) {}
        EmailAttachment();
        EmailAttachment(param::hstring const& fileName, winrt::Windows::Storage::Streams::IRandomAccessStreamReference const& data);
        EmailAttachment(param::hstring const& fileName, winrt::Windows::Storage::Streams::IRandomAccessStreamReference const& data, param::hstring const& mimeType);
    };
    struct WINRT_IMPL_EMPTY_BASES EmailConversation : winrt::Windows::ApplicationModel::Email::IEmailConversation
    {
        EmailConversation(std::nullptr_t) noexcept {}
        EmailConversation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailConversation(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailConversationBatch : winrt::Windows::ApplicationModel::Email::IEmailConversationBatch
    {
        EmailConversationBatch(std::nullptr_t) noexcept {}
        EmailConversationBatch(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailConversationBatch(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailConversationReader : winrt::Windows::ApplicationModel::Email::IEmailConversationReader
    {
        EmailConversationReader(std::nullptr_t) noexcept {}
        EmailConversationReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailConversationReader(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailFolder : winrt::Windows::ApplicationModel::Email::IEmailFolder
    {
        EmailFolder(std::nullptr_t) noexcept {}
        EmailFolder(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailFolder(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailIrmInfo : winrt::Windows::ApplicationModel::Email::IEmailIrmInfo
    {
        EmailIrmInfo(std::nullptr_t) noexcept {}
        EmailIrmInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailIrmInfo(ptr, take_ownership_from_abi) {}
        EmailIrmInfo();
        EmailIrmInfo(winrt::Windows::Foundation::DateTime const& expiration, winrt::Windows::ApplicationModel::Email::EmailIrmTemplate const& irmTemplate);
    };
    struct WINRT_IMPL_EMPTY_BASES EmailIrmTemplate : winrt::Windows::ApplicationModel::Email::IEmailIrmTemplate
    {
        EmailIrmTemplate(std::nullptr_t) noexcept {}
        EmailIrmTemplate(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailIrmTemplate(ptr, take_ownership_from_abi) {}
        EmailIrmTemplate();
        EmailIrmTemplate(param::hstring const& id, param::hstring const& name, param::hstring const& description);
    };
    struct WINRT_IMPL_EMPTY_BASES EmailItemCounts : winrt::Windows::ApplicationModel::Email::IEmailItemCounts
    {
        EmailItemCounts(std::nullptr_t) noexcept {}
        EmailItemCounts(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailItemCounts(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailbox : winrt::Windows::ApplicationModel::Email::IEmailMailbox,
        impl::require<EmailMailbox, winrt::Windows::ApplicationModel::Email::IEmailMailbox2, winrt::Windows::ApplicationModel::Email::IEmailMailbox3, winrt::Windows::ApplicationModel::Email::IEmailMailbox4, winrt::Windows::ApplicationModel::Email::IEmailMailbox5>
    {
        EmailMailbox(std::nullptr_t) noexcept {}
        EmailMailbox(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailbox(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxAction : winrt::Windows::ApplicationModel::Email::IEmailMailboxAction
    {
        EmailMailboxAction(std::nullptr_t) noexcept {}
        EmailMailboxAction(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxAction(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxAutoReply : winrt::Windows::ApplicationModel::Email::IEmailMailboxAutoReply
    {
        EmailMailboxAutoReply(std::nullptr_t) noexcept {}
        EmailMailboxAutoReply(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxAutoReply(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxAutoReplySettings : winrt::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings
    {
        EmailMailboxAutoReplySettings(std::nullptr_t) noexcept {}
        EmailMailboxAutoReplySettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxAutoReplySettings(ptr, take_ownership_from_abi) {}
        EmailMailboxAutoReplySettings();
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxCapabilities : winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities,
        impl::require<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>
    {
        EmailMailboxCapabilities(std::nullptr_t) noexcept {}
        EmailMailboxCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities(ptr, take_ownership_from_abi) {}
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanCreateFolder;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanCreateFolder;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanDeleteFolder;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanDeleteFolder;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanEmptyFolder;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanEmptyFolder;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanForwardMeetings;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanForwardMeetings;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanGetAndSetExternalAutoReplies;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanGetAndSetExternalAutoReplies;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanGetAndSetInternalAutoReplies;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanGetAndSetInternalAutoReplies;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanMoveFolder;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanMoveFolder;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanProposeNewTimeForMeetings;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanProposeNewTimeForMeetings;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanResolveRecipients;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanResolveRecipients;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanServerSearchFolders;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanServerSearchFolders;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanServerSearchMailbox;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanServerSearchMailbox;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanSmartSend;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanSmartSend;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities::CanUpdateMeetingResponses;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanUpdateMeetingResponses;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanValidateCertificates;
        using impl::consume_t<EmailMailboxCapabilities, winrt::Windows::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanValidateCertificates;
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxChange : winrt::Windows::ApplicationModel::Email::IEmailMailboxChange
    {
        EmailMailboxChange(std::nullptr_t) noexcept {}
        EmailMailboxChange(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxChange(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxChangeReader : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangeReader
    {
        EmailMailboxChangeReader(std::nullptr_t) noexcept {}
        EmailMailboxChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangeReader(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxChangeTracker : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker
    {
        EmailMailboxChangeTracker(std::nullptr_t) noexcept {}
        EmailMailboxChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangeTracker(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxChangedDeferral : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral
    {
        EmailMailboxChangedDeferral(std::nullptr_t) noexcept {}
        EmailMailboxChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxChangedEventArgs : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs
    {
        EmailMailboxChangedEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxCreateFolderResult : winrt::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult
    {
        EmailMailboxCreateFolderResult(std::nullptr_t) noexcept {}
        EmailMailboxCreateFolderResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxCreateFolderResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxPolicies : winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies,
        impl::require<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies2, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>
    {
        EmailMailboxPolicies(std::nullptr_t) noexcept {}
        EmailMailboxPolicies(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies(ptr, take_ownership_from_abi) {}
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies::AllowSmimeSoftCertificates;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>::AllowSmimeSoftCertificates;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies::AllowedSmimeEncryptionAlgorithmNegotiation;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>::AllowedSmimeEncryptionAlgorithmNegotiation;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies2>::MustEncryptSmimeMessages;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>::MustEncryptSmimeMessages;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies2>::MustSignSmimeMessages;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>::MustSignSmimeMessages;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies::RequiredSmimeEncryptionAlgorithm;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>::RequiredSmimeEncryptionAlgorithm;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies::RequiredSmimeSigningAlgorithm;
        using impl::consume_t<EmailMailboxPolicies, winrt::Windows::ApplicationModel::Email::IEmailMailboxPolicies3>::RequiredSmimeSigningAlgorithm;
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMailboxSyncManager : winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager,
        impl::require<EmailMailboxSyncManager, winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>
    {
        EmailMailboxSyncManager(std::nullptr_t) noexcept {}
        EmailMailboxSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager(ptr, take_ownership_from_abi) {}
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager::LastAttemptedSyncTime;
        using impl::consume_t<EmailMailboxSyncManager, winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>::LastAttemptedSyncTime;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager::LastSuccessfulSyncTime;
        using impl::consume_t<EmailMailboxSyncManager, winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>::LastSuccessfulSyncTime;
        using winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager::Status;
        using impl::consume_t<EmailMailboxSyncManager, winrt::Windows::ApplicationModel::Email::IEmailMailboxSyncManager2>::Status;
    };
    struct EmailManager
    {
        EmailManager() = delete;
        static auto ShowComposeNewEmailAsync(winrt::Windows::ApplicationModel::Email::EmailMessage const& message);
        static auto RequestStoreAsync(winrt::Windows::ApplicationModel::Email::EmailStoreAccessType const& accessType);
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct WINRT_IMPL_EMPTY_BASES EmailManagerForUser : winrt::Windows::ApplicationModel::Email::IEmailManagerForUser
    {
        EmailManagerForUser(std::nullptr_t) noexcept {}
        EmailManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMeetingInfo : winrt::Windows::ApplicationModel::Email::IEmailMeetingInfo,
        impl::require<EmailMeetingInfo, winrt::Windows::ApplicationModel::Email::IEmailMeetingInfo2>
    {
        EmailMeetingInfo(std::nullptr_t) noexcept {}
        EmailMeetingInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMeetingInfo(ptr, take_ownership_from_abi) {}
        EmailMeetingInfo();
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMessage : winrt::Windows::ApplicationModel::Email::IEmailMessage,
        impl::require<EmailMessage, winrt::Windows::ApplicationModel::Email::IEmailMessage2, winrt::Windows::ApplicationModel::Email::IEmailMessage3, winrt::Windows::ApplicationModel::Email::IEmailMessage4>
    {
        EmailMessage(std::nullptr_t) noexcept {}
        EmailMessage(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMessage(ptr, take_ownership_from_abi) {}
        EmailMessage();
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMessageBatch : winrt::Windows::ApplicationModel::Email::IEmailMessageBatch
    {
        EmailMessageBatch(std::nullptr_t) noexcept {}
        EmailMessageBatch(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMessageBatch(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailMessageReader : winrt::Windows::ApplicationModel::Email::IEmailMessageReader
    {
        EmailMessageReader(std::nullptr_t) noexcept {}
        EmailMessageReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailMessageReader(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailQueryOptions : winrt::Windows::ApplicationModel::Email::IEmailQueryOptions
    {
        EmailQueryOptions(std::nullptr_t) noexcept {}
        EmailQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailQueryOptions(ptr, take_ownership_from_abi) {}
        EmailQueryOptions();
        explicit EmailQueryOptions(param::hstring const& text);
        EmailQueryOptions(param::hstring const& text, winrt::Windows::ApplicationModel::Email::EmailQuerySearchFields const& fields);
    };
    struct WINRT_IMPL_EMPTY_BASES EmailQueryTextSearch : winrt::Windows::ApplicationModel::Email::IEmailQueryTextSearch
    {
        EmailQueryTextSearch(std::nullptr_t) noexcept {}
        EmailQueryTextSearch(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailQueryTextSearch(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailRecipient : winrt::Windows::ApplicationModel::Email::IEmailRecipient
    {
        EmailRecipient(std::nullptr_t) noexcept {}
        EmailRecipient(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailRecipient(ptr, take_ownership_from_abi) {}
        EmailRecipient();
        explicit EmailRecipient(param::hstring const& address);
        EmailRecipient(param::hstring const& address, param::hstring const& name);
    };
    struct WINRT_IMPL_EMPTY_BASES EmailRecipientResolutionResult : winrt::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult,
        impl::require<EmailRecipientResolutionResult, winrt::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>
    {
        EmailRecipientResolutionResult(std::nullptr_t) noexcept {}
        EmailRecipientResolutionResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult(ptr, take_ownership_from_abi) {}
        EmailRecipientResolutionResult();
        using winrt::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult::Status;
        using impl::consume_t<EmailRecipientResolutionResult, winrt::Windows::ApplicationModel::Email::IEmailRecipientResolutionResult2>::Status;
    };
    struct WINRT_IMPL_EMPTY_BASES EmailStore : winrt::Windows::ApplicationModel::Email::IEmailStore
    {
        EmailStore(std::nullptr_t) noexcept {}
        EmailStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailStore(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES EmailStoreNotificationTriggerDetails : winrt::Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails
    {
        EmailStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
        EmailStoreNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
}
#endif
