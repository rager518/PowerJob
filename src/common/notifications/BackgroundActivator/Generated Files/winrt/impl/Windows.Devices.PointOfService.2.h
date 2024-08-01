// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.240111.5

#pragma once
#ifndef WINRT_Windows_Devices_PointOfService_2_H
#define WINRT_Windows_Devices_PointOfService_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Devices.PointOfService.1.h"
WINRT_EXPORT namespace winrt::Windows::Devices::PointOfService
{
    struct SizeUInt32
    {
        uint32_t Width;
        uint32_t Height;
    };
    inline bool operator==(SizeUInt32 const& left, SizeUInt32 const& right) noexcept
    {
        return left.Width == right.Width && left.Height == right.Height;
    }
    inline bool operator!=(SizeUInt32 const& left, SizeUInt32 const& right) noexcept
    {
        return !(left == right);
    }
    struct WINRT_IMPL_EMPTY_BASES BarcodeScanner : winrt::Windows::Devices::PointOfService::IBarcodeScanner,
        impl::require<BarcodeScanner, winrt::Windows::Devices::PointOfService::IBarcodeScanner2, winrt::Windows::Foundation::IClosable>
    {
        BarcodeScanner(std::nullptr_t) noexcept {}
        BarcodeScanner(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScanner(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(winrt::Windows::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeScannerCapabilities : winrt::Windows::Devices::PointOfService::IBarcodeScannerCapabilities,
        impl::require<BarcodeScannerCapabilities, winrt::Windows::Devices::PointOfService::IBarcodeScannerCapabilities1, winrt::Windows::Devices::PointOfService::IBarcodeScannerCapabilities2>
    {
        BarcodeScannerCapabilities(std::nullptr_t) noexcept {}
        BarcodeScannerCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScannerCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeScannerDataReceivedEventArgs : winrt::Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs
    {
        BarcodeScannerDataReceivedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeScannerErrorOccurredEventArgs : winrt::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs
    {
        BarcodeScannerErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeScannerImagePreviewReceivedEventArgs : winrt::Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs
    {
        BarcodeScannerImagePreviewReceivedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerImagePreviewReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeScannerReport : winrt::Windows::Devices::PointOfService::IBarcodeScannerReport
    {
        BarcodeScannerReport(std::nullptr_t) noexcept {}
        BarcodeScannerReport(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScannerReport(ptr, take_ownership_from_abi) {}
        BarcodeScannerReport(uint32_t scanDataType, winrt::Windows::Storage::Streams::IBuffer const& scanData, winrt::Windows::Storage::Streams::IBuffer const& scanDataLabel);
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeScannerStatusUpdatedEventArgs : winrt::Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs
    {
        BarcodeScannerStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct BarcodeSymbologies
    {
        BarcodeSymbologies() = delete;
        [[nodiscard]] static auto Unknown();
        [[nodiscard]] static auto Ean8();
        [[nodiscard]] static auto Ean8Add2();
        [[nodiscard]] static auto Ean8Add5();
        [[nodiscard]] static auto Eanv();
        [[nodiscard]] static auto EanvAdd2();
        [[nodiscard]] static auto EanvAdd5();
        [[nodiscard]] static auto Ean13();
        [[nodiscard]] static auto Ean13Add2();
        [[nodiscard]] static auto Ean13Add5();
        [[nodiscard]] static auto Isbn();
        [[nodiscard]] static auto IsbnAdd5();
        [[nodiscard]] static auto Ismn();
        [[nodiscard]] static auto IsmnAdd2();
        [[nodiscard]] static auto IsmnAdd5();
        [[nodiscard]] static auto Issn();
        [[nodiscard]] static auto IssnAdd2();
        [[nodiscard]] static auto IssnAdd5();
        [[nodiscard]] static auto Ean99();
        [[nodiscard]] static auto Ean99Add2();
        [[nodiscard]] static auto Ean99Add5();
        [[nodiscard]] static auto Upca();
        [[nodiscard]] static auto UpcaAdd2();
        [[nodiscard]] static auto UpcaAdd5();
        [[nodiscard]] static auto Upce();
        [[nodiscard]] static auto UpceAdd2();
        [[nodiscard]] static auto UpceAdd5();
        [[nodiscard]] static auto UpcCoupon();
        [[nodiscard]] static auto TfStd();
        [[nodiscard]] static auto TfDis();
        [[nodiscard]] static auto TfInt();
        [[nodiscard]] static auto TfInd();
        [[nodiscard]] static auto TfMat();
        [[nodiscard]] static auto TfIata();
        [[nodiscard]] static auto Gs1DatabarType1();
        [[nodiscard]] static auto Gs1DatabarType2();
        [[nodiscard]] static auto Gs1DatabarType3();
        [[nodiscard]] static auto Code39();
        [[nodiscard]] static auto Code39Ex();
        [[nodiscard]] static auto Trioptic39();
        [[nodiscard]] static auto Code32();
        [[nodiscard]] static auto Pzn();
        [[nodiscard]] static auto Code93();
        [[nodiscard]] static auto Code93Ex();
        [[nodiscard]] static auto Code128();
        [[nodiscard]] static auto Gs1128();
        [[nodiscard]] static auto Gs1128Coupon();
        [[nodiscard]] static auto UccEan128();
        [[nodiscard]] static auto Sisac();
        [[nodiscard]] static auto Isbt();
        [[nodiscard]] static auto Codabar();
        [[nodiscard]] static auto Code11();
        [[nodiscard]] static auto Msi();
        [[nodiscard]] static auto Plessey();
        [[nodiscard]] static auto Telepen();
        [[nodiscard]] static auto Code16k();
        [[nodiscard]] static auto CodablockA();
        [[nodiscard]] static auto CodablockF();
        [[nodiscard]] static auto Codablock128();
        [[nodiscard]] static auto Code49();
        [[nodiscard]] static auto Aztec();
        [[nodiscard]] static auto DataCode();
        [[nodiscard]] static auto DataMatrix();
        [[nodiscard]] static auto HanXin();
        [[nodiscard]] static auto Maxicode();
        [[nodiscard]] static auto MicroPdf417();
        [[nodiscard]] static auto MicroQr();
        [[nodiscard]] static auto Pdf417();
        [[nodiscard]] static auto Qr();
        [[nodiscard]] static auto MsTag();
        [[nodiscard]] static auto Ccab();
        [[nodiscard]] static auto Ccc();
        [[nodiscard]] static auto Tlc39();
        [[nodiscard]] static auto AusPost();
        [[nodiscard]] static auto CanPost();
        [[nodiscard]] static auto ChinaPost();
        [[nodiscard]] static auto DutchKix();
        [[nodiscard]] static auto InfoMail();
        [[nodiscard]] static auto ItalianPost25();
        [[nodiscard]] static auto ItalianPost39();
        [[nodiscard]] static auto JapanPost();
        [[nodiscard]] static auto KoreanPost();
        [[nodiscard]] static auto SwedenPost();
        [[nodiscard]] static auto UkPost();
        [[nodiscard]] static auto UsIntelligent();
        [[nodiscard]] static auto UsIntelligentPkg();
        [[nodiscard]] static auto UsPlanet();
        [[nodiscard]] static auto UsPostNet();
        [[nodiscard]] static auto Us4StateFics();
        [[nodiscard]] static auto OcrA();
        [[nodiscard]] static auto OcrB();
        [[nodiscard]] static auto Micr();
        [[nodiscard]] static auto ExtendedBase();
        static auto GetName(uint32_t scanDataType);
        [[nodiscard]] static auto Gs1DWCode();
    };
    struct WINRT_IMPL_EMPTY_BASES BarcodeSymbologyAttributes : winrt::Windows::Devices::PointOfService::IBarcodeSymbologyAttributes
    {
        BarcodeSymbologyAttributes(std::nullptr_t) noexcept {}
        BarcodeSymbologyAttributes(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IBarcodeSymbologyAttributes(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawer : winrt::Windows::Devices::PointOfService::ICashDrawer,
        impl::require<CashDrawer, winrt::Windows::Foundation::IClosable>
    {
        CashDrawer(std::nullptr_t) noexcept {}
        CashDrawer(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawer(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(winrt::Windows::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerCapabilities : winrt::Windows::Devices::PointOfService::ICashDrawerCapabilities
    {
        CashDrawerCapabilities(std::nullptr_t) noexcept {}
        CashDrawerCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerCloseAlarm : winrt::Windows::Devices::PointOfService::ICashDrawerCloseAlarm
    {
        CashDrawerCloseAlarm(std::nullptr_t) noexcept {}
        CashDrawerCloseAlarm(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerCloseAlarm(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerClosedEventArgs : winrt::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs
    {
        CashDrawerClosedEventArgs(std::nullptr_t) noexcept {}
        CashDrawerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerEventSource : winrt::Windows::Devices::PointOfService::ICashDrawerEventSource
    {
        CashDrawerEventSource(std::nullptr_t) noexcept {}
        CashDrawerEventSource(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerEventSource(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerOpenedEventArgs : winrt::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs
    {
        CashDrawerOpenedEventArgs(std::nullptr_t) noexcept {}
        CashDrawerOpenedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerStatus : winrt::Windows::Devices::PointOfService::ICashDrawerStatus
    {
        CashDrawerStatus(std::nullptr_t) noexcept {}
        CashDrawerStatus(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerStatus(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES CashDrawerStatusUpdatedEventArgs : winrt::Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs
    {
        CashDrawerStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        CashDrawerStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedBarcodeScanner : winrt::Windows::Devices::PointOfService::IClaimedBarcodeScanner,
        impl::require<ClaimedBarcodeScanner, winrt::Windows::Devices::PointOfService::IClaimedBarcodeScanner1, winrt::Windows::Devices::PointOfService::IClaimedBarcodeScanner2, winrt::Windows::Devices::PointOfService::IClaimedBarcodeScanner3, winrt::Windows::Devices::PointOfService::IClaimedBarcodeScanner4, winrt::Windows::Foundation::IClosable>
    {
        ClaimedBarcodeScanner(std::nullptr_t) noexcept {}
        ClaimedBarcodeScanner(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedBarcodeScanner(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedBarcodeScannerClosedEventArgs : winrt::Windows::Devices::PointOfService::IClaimedBarcodeScannerClosedEventArgs
    {
        ClaimedBarcodeScannerClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedBarcodeScannerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedBarcodeScannerClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedCashDrawer : winrt::Windows::Devices::PointOfService::IClaimedCashDrawer,
        impl::require<ClaimedCashDrawer, winrt::Windows::Devices::PointOfService::IClaimedCashDrawer2, winrt::Windows::Foundation::IClosable>
    {
        ClaimedCashDrawer(std::nullptr_t) noexcept {}
        ClaimedCashDrawer(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedCashDrawer(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedCashDrawerClosedEventArgs : winrt::Windows::Devices::PointOfService::IClaimedCashDrawerClosedEventArgs
    {
        ClaimedCashDrawerClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedCashDrawerClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedCashDrawerClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedJournalPrinter : winrt::Windows::Devices::PointOfService::IClaimedJournalPrinter,
        impl::require<ClaimedJournalPrinter, winrt::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>
    {
        ClaimedJournalPrinter(std::nullptr_t) noexcept {}
        ClaimedJournalPrinter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedJournalPrinter(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedLineDisplay : winrt::Windows::Devices::PointOfService::IClaimedLineDisplay,
        impl::require<ClaimedLineDisplay, winrt::Windows::Devices::PointOfService::IClaimedLineDisplay2, winrt::Windows::Devices::PointOfService::IClaimedLineDisplay3, winrt::Windows::Foundation::IClosable>
    {
        ClaimedLineDisplay(std::nullptr_t) noexcept {}
        ClaimedLineDisplay(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedLineDisplay(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(winrt::Windows::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedLineDisplayClosedEventArgs : winrt::Windows::Devices::PointOfService::IClaimedLineDisplayClosedEventArgs
    {
        ClaimedLineDisplayClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedLineDisplayClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedLineDisplayClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedMagneticStripeReader : winrt::Windows::Devices::PointOfService::IClaimedMagneticStripeReader,
        impl::require<ClaimedMagneticStripeReader, winrt::Windows::Devices::PointOfService::IClaimedMagneticStripeReader2, winrt::Windows::Foundation::IClosable>
    {
        ClaimedMagneticStripeReader(std::nullptr_t) noexcept {}
        ClaimedMagneticStripeReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedMagneticStripeReader(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedMagneticStripeReaderClosedEventArgs : winrt::Windows::Devices::PointOfService::IClaimedMagneticStripeReaderClosedEventArgs
    {
        ClaimedMagneticStripeReaderClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedMagneticStripeReaderClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedMagneticStripeReaderClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedPosPrinter : winrt::Windows::Devices::PointOfService::IClaimedPosPrinter,
        impl::require<ClaimedPosPrinter, winrt::Windows::Devices::PointOfService::IClaimedPosPrinter2, winrt::Windows::Foundation::IClosable>
    {
        ClaimedPosPrinter(std::nullptr_t) noexcept {}
        ClaimedPosPrinter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedPosPrinter(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedPosPrinterClosedEventArgs : winrt::Windows::Devices::PointOfService::IClaimedPosPrinterClosedEventArgs
    {
        ClaimedPosPrinterClosedEventArgs(std::nullptr_t) noexcept {}
        ClaimedPosPrinterClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedPosPrinterClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedReceiptPrinter : winrt::Windows::Devices::PointOfService::IClaimedReceiptPrinter,
        impl::require<ClaimedReceiptPrinter, winrt::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>
    {
        ClaimedReceiptPrinter(std::nullptr_t) noexcept {}
        ClaimedReceiptPrinter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedReceiptPrinter(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ClaimedSlipPrinter : winrt::Windows::Devices::PointOfService::IClaimedSlipPrinter,
        impl::require<ClaimedSlipPrinter, winrt::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>
    {
        ClaimedSlipPrinter(std::nullptr_t) noexcept {}
        ClaimedSlipPrinter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IClaimedSlipPrinter(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES JournalPrintJob : winrt::Windows::Devices::PointOfService::IPosPrinterJob,
        impl::require<JournalPrintJob, winrt::Windows::Devices::PointOfService::IJournalPrintJob>
    {
        JournalPrintJob(std::nullptr_t) noexcept {}
        JournalPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterJob(ptr, take_ownership_from_abi) {}
        using impl::consume_t<JournalPrintJob, winrt::Windows::Devices::PointOfService::IJournalPrintJob>::Print;
        using winrt::Windows::Devices::PointOfService::IPosPrinterJob::Print;
    };
    struct WINRT_IMPL_EMPTY_BASES JournalPrinterCapabilities : winrt::Windows::Devices::PointOfService::IJournalPrinterCapabilities,
        impl::require<JournalPrinterCapabilities, winrt::Windows::Devices::PointOfService::IJournalPrinterCapabilities2, winrt::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>
    {
        JournalPrinterCapabilities(std::nullptr_t) noexcept {}
        JournalPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IJournalPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplay : winrt::Windows::Devices::PointOfService::ILineDisplay,
        impl::require<LineDisplay, winrt::Windows::Devices::PointOfService::ILineDisplay2, winrt::Windows::Foundation::IClosable>
    {
        LineDisplay(std::nullptr_t) noexcept {}
        LineDisplay(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplay(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(winrt::Windows::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
        [[nodiscard]] static auto StatisticsCategorySelector();
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayAttributes : winrt::Windows::Devices::PointOfService::ILineDisplayAttributes
    {
        LineDisplayAttributes(std::nullptr_t) noexcept {}
        LineDisplayAttributes(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayAttributes(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayCapabilities : winrt::Windows::Devices::PointOfService::ILineDisplayCapabilities
    {
        LineDisplayCapabilities(std::nullptr_t) noexcept {}
        LineDisplayCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayCursor : winrt::Windows::Devices::PointOfService::ILineDisplayCursor
    {
        LineDisplayCursor(std::nullptr_t) noexcept {}
        LineDisplayCursor(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayCursor(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayCursorAttributes : winrt::Windows::Devices::PointOfService::ILineDisplayCursorAttributes
    {
        LineDisplayCursorAttributes(std::nullptr_t) noexcept {}
        LineDisplayCursorAttributes(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayCursorAttributes(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayCustomGlyphs : winrt::Windows::Devices::PointOfService::ILineDisplayCustomGlyphs
    {
        LineDisplayCustomGlyphs(std::nullptr_t) noexcept {}
        LineDisplayCustomGlyphs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayCustomGlyphs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayMarquee : winrt::Windows::Devices::PointOfService::ILineDisplayMarquee
    {
        LineDisplayMarquee(std::nullptr_t) noexcept {}
        LineDisplayMarquee(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayMarquee(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayStatisticsCategorySelector : winrt::Windows::Devices::PointOfService::ILineDisplayStatisticsCategorySelector
    {
        LineDisplayStatisticsCategorySelector(std::nullptr_t) noexcept {}
        LineDisplayStatisticsCategorySelector(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayStatisticsCategorySelector(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayStatusUpdatedEventArgs : winrt::Windows::Devices::PointOfService::ILineDisplayStatusUpdatedEventArgs
    {
        LineDisplayStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        LineDisplayStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayStoredBitmap : winrt::Windows::Devices::PointOfService::ILineDisplayStoredBitmap
    {
        LineDisplayStoredBitmap(std::nullptr_t) noexcept {}
        LineDisplayStoredBitmap(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayStoredBitmap(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LineDisplayWindow : winrt::Windows::Devices::PointOfService::ILineDisplayWindow,
        impl::require<LineDisplayWindow, winrt::Windows::Devices::PointOfService::ILineDisplayWindow2, winrt::Windows::Foundation::IClosable>
    {
        LineDisplayWindow(std::nullptr_t) noexcept {}
        LineDisplayWindow(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ILineDisplayWindow(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReader : winrt::Windows::Devices::PointOfService::IMagneticStripeReader,
        impl::require<MagneticStripeReader, winrt::Windows::Foundation::IClosable>
    {
        MagneticStripeReader(std::nullptr_t) noexcept {}
        MagneticStripeReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReader(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(winrt::Windows::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderAamvaCardDataReceivedEventArgs : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs
    {
        MagneticStripeReaderAamvaCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderAamvaCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderBankCardDataReceivedEventArgs : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs
    {
        MagneticStripeReaderBankCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderBankCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderCapabilities : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities
    {
        MagneticStripeReaderCapabilities(std::nullptr_t) noexcept {}
        MagneticStripeReaderCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct MagneticStripeReaderCardTypes
    {
        MagneticStripeReaderCardTypes() = delete;
        [[nodiscard]] static auto Unknown();
        [[nodiscard]] static auto Bank();
        [[nodiscard]] static auto Aamva();
        [[nodiscard]] static auto ExtendedBase();
    };
    struct MagneticStripeReaderEncryptionAlgorithms
    {
        MagneticStripeReaderEncryptionAlgorithms() = delete;
        [[nodiscard]] static auto None();
        [[nodiscard]] static auto TripleDesDukpt();
        [[nodiscard]] static auto ExtendedBase();
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderErrorOccurredEventArgs : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs
    {
        MagneticStripeReaderErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderReport : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderReport
    {
        MagneticStripeReaderReport(std::nullptr_t) noexcept {}
        MagneticStripeReaderReport(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderReport(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderStatusUpdatedEventArgs : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs
    {
        MagneticStripeReaderStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderTrackData : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData
    {
        MagneticStripeReaderTrackData(std::nullptr_t) noexcept {}
        MagneticStripeReaderTrackData(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs
    {
        MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
        MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinter : winrt::Windows::Devices::PointOfService::IPosPrinter,
        impl::require<PosPrinter, winrt::Windows::Devices::PointOfService::IPosPrinter2, winrt::Windows::Foundation::IClosable>
    {
        PosPrinter(std::nullptr_t) noexcept {}
        PosPrinter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinter(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(winrt::Windows::Devices::PointOfService::PosConnectionTypes const& connectionTypes);
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinterCapabilities : winrt::Windows::Devices::PointOfService::IPosPrinterCapabilities
    {
        PosPrinterCapabilities(std::nullptr_t) noexcept {}
        PosPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct PosPrinterCharacterSetIds
    {
        PosPrinterCharacterSetIds() = delete;
        [[nodiscard]] static auto Utf16LE();
        [[nodiscard]] static auto Ascii();
        [[nodiscard]] static auto Ansi();
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinterFontProperty : winrt::Windows::Devices::PointOfService::IPosPrinterFontProperty
    {
        PosPrinterFontProperty(std::nullptr_t) noexcept {}
        PosPrinterFontProperty(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterFontProperty(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinterPrintOptions : winrt::Windows::Devices::PointOfService::IPosPrinterPrintOptions
    {
        PosPrinterPrintOptions(std::nullptr_t) noexcept {}
        PosPrinterPrintOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterPrintOptions(ptr, take_ownership_from_abi) {}
        PosPrinterPrintOptions();
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinterReleaseDeviceRequestedEventArgs : winrt::Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs
    {
        PosPrinterReleaseDeviceRequestedEventArgs(std::nullptr_t) noexcept {}
        PosPrinterReleaseDeviceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinterStatus : winrt::Windows::Devices::PointOfService::IPosPrinterStatus
    {
        PosPrinterStatus(std::nullptr_t) noexcept {}
        PosPrinterStatus(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterStatus(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PosPrinterStatusUpdatedEventArgs : winrt::Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs
    {
        PosPrinterStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
        PosPrinterStatusUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES ReceiptPrintJob : winrt::Windows::Devices::PointOfService::IReceiptPrintJob,
        impl::require<ReceiptPrintJob, winrt::Windows::Devices::PointOfService::IReceiptPrintJob2, winrt::Windows::Devices::PointOfService::IPosPrinterJob, winrt::Windows::Devices::PointOfService::IReceiptOrSlipJob>
    {
        ReceiptPrintJob(std::nullptr_t) noexcept {}
        ReceiptPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IReceiptPrintJob(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ReceiptPrintJob, winrt::Windows::Devices::PointOfService::IPosPrinterJob>::Print;
        using impl::consume_t<ReceiptPrintJob, winrt::Windows::Devices::PointOfService::IReceiptPrintJob2>::Print;
    };
    struct WINRT_IMPL_EMPTY_BASES ReceiptPrinterCapabilities : winrt::Windows::Devices::PointOfService::IReceiptPrinterCapabilities,
        impl::require<ReceiptPrinterCapabilities, winrt::Windows::Devices::PointOfService::IReceiptPrinterCapabilities2, winrt::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities, winrt::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>
    {
        ReceiptPrinterCapabilities(std::nullptr_t) noexcept {}
        ReceiptPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IReceiptPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES SlipPrintJob : winrt::Windows::Devices::PointOfService::IReceiptOrSlipJob,
        impl::require<SlipPrintJob, winrt::Windows::Devices::PointOfService::ISlipPrintJob>
    {
        SlipPrintJob(std::nullptr_t) noexcept {}
        SlipPrintJob(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IReceiptOrSlipJob(ptr, take_ownership_from_abi) {}
        using winrt::Windows::Devices::PointOfService::IReceiptOrSlipJob::Print;
        using impl::consume_t<SlipPrintJob, winrt::Windows::Devices::PointOfService::ISlipPrintJob>::Print;
    };
    struct WINRT_IMPL_EMPTY_BASES SlipPrinterCapabilities : winrt::Windows::Devices::PointOfService::ISlipPrinterCapabilities,
        impl::require<SlipPrinterCapabilities, winrt::Windows::Devices::PointOfService::ISlipPrinterCapabilities2, winrt::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities, winrt::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>
    {
        SlipPrinterCapabilities(std::nullptr_t) noexcept {}
        SlipPrinterCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::ISlipPrinterCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES UnifiedPosErrorData : winrt::Windows::Devices::PointOfService::IUnifiedPosErrorData
    {
        UnifiedPosErrorData(std::nullptr_t) noexcept {}
        UnifiedPosErrorData(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::PointOfService::IUnifiedPosErrorData(ptr, take_ownership_from_abi) {}
        UnifiedPosErrorData(param::hstring const& message, winrt::Windows::Devices::PointOfService::UnifiedPosErrorSeverity const& severity, winrt::Windows::Devices::PointOfService::UnifiedPosErrorReason const& reason, uint32_t extendedReason);
    };
}
#endif
