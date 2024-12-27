#include "pch.h"

#include "trace.h"
#include <common/logger/logger.h>
#include <common/utils/logger_helper.h>
#include <interface/powertoy_module_interface.h>
#include "Generated Files/resource.h"

#include <shellapi.h>
#include <common/interop/shared_constants.h>
#include <common/utils/EventWaiter.h>
#include <common/utils/resources.h>
#include <common/utils/winapi_error.h>
#include <common/SettingsAPI/settings_objects.h>
#include <string>

extern "C" IMAGE_DOS_HEADER __ImageBase;

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD ul_reason_for_call, LPVOID /*lpReserved*/)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Trace::RegisterProvider();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        Trace::UnregisterProvider();
        break;
    }
    return TRUE;
}

namespace
{
    // Name of the powertoy module.
    inline const std::wstring ModuleKey = L"AutoStartups";
}

class AutoStartupsModuleInterface : public PowertoyModuleIface
{
private:
    bool m_enabled = false;

    std::wstring app_name;

    //contains the non localized key of the powertoy
    std::wstring app_key;

    HANDLE m_hProcess = nullptr;

    HANDLE m_hShowEvent{};

    HANDLE m_hShowAdminEvent{};

    // Hotkey to invoke the module
    HotkeyEx m_hotkey;

    const UINT DEFAULT_MILLISECONDS_WIN_KEY_PRESS_TIME_FOR_GLOBAL_WINDOWS_SHORTCUTS = 900;
    const UINT DEFAULT_MILLISECONDS_WIN_KEY_PRESS_TIME_FOR_TASKBAR_ICON_SHORTCUTS = 900;
    bool m_shouldReactToPressedWinKey = false;
    UINT m_millisecondsWinKeyPressTimeForGlobalWindowsShortcuts = DEFAULT_MILLISECONDS_WIN_KEY_PRESS_TIME_FOR_GLOBAL_WINDOWS_SHORTCUTS;
    UINT m_millisecondsWinKeyPressTimeForTaskbarIconShortcuts = DEFAULT_MILLISECONDS_WIN_KEY_PRESS_TIME_FOR_TASKBAR_ICON_SHORTCUTS;

    HANDLE triggerEvent;
    HANDLE exitEvent;
    EventWaiter triggerEventWaiter;

    bool is_process_running()
    {
        return WaitForSingleObject(m_hProcess, 0) == WAIT_TIMEOUT;
    }

    void bring_process_to_front()
    {
        auto enum_windows = [](HWND hwnd, LPARAM param) -> BOOL {
            HANDLE process_handle = reinterpret_cast<HANDLE>(param);
            DWORD window_process_id = 0;

            GetWindowThreadProcessId(hwnd, &window_process_id);
            if (GetProcessId(process_handle) == window_process_id)
            {
                SetForegroundWindow(hwnd);
                return FALSE;
            }
            return TRUE;
        };

        EnumWindows(enum_windows, (LPARAM)m_hProcess);
    }

    void launch_process(bool runas)
    {
        Logger::trace(L"Starting AutoStarts process");
        unsigned long powerjob_pid = GetCurrentProcessId();

        std::wstring executable_args = L"";
        executable_args.append(std::to_wstring(powerjob_pid));

        SHELLEXECUTEINFOW sei{ sizeof(sei) };
        sei.fMask = { SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI };
        sei.lpFile = L"WinUI3Apps\\PowerJob.AutoStartups.exe";
        sei.nShow = SW_SHOWNORMAL;
        sei.lpParameters = executable_args.data();

        if (runas)
        {
            sei.lpVerb = L"runas";
        }

        if (ShellExecuteExW(&sei))
        {
            Logger::trace("Successfully started the AutoStartups process");
        }
        else
        {
            Logger::error(L"AutoStartups failed to start. {}", get_last_error_or_default(GetLastError()));
        }

        m_hProcess = sei.hProcess;
    }

public:
    EventWaiter m_showEventWaiter;

    EventWaiter m_showAdminEventWaiter;

    AutoStartupsModuleInterface()
    {
        app_name = GET_RESOURCE_STRING(IDS_HOSTS_NAME);
        app_key = ModuleKey;
        LoggerHelpers::init_logger(app_key, L"ModuleInterface", LogSettings::autostartsLoggerName);

        m_hShowEvent = CreateDefaultEvent(CommonSharedConstants::SHOW_AUTOSTARTUPS_EVENT);
        if (!m_hShowEvent)
        {
            Logger::error(L"Failed to create show autostarts event");
            auto message = get_last_error_message(GetLastError());
            if (message.has_value())
            {
                Logger::error(message.value());
            }
        }

        //m_hShowAdminEvent = CreateDefaultEvent(CommonSharedConstants::SHOW_HOSTS_ADMIN_EVENT);
        //if (!m_hShowAdminEvent)
        //{
        //    Logger::error(L"Failed to create show hosts admin event");
        //    auto message = get_last_error_message(GetLastError());
        //    if (message.has_value())
        //    {
        //        Logger::error(message.value());
        //    }
        //}

        m_showEventWaiter = EventWaiter(CommonSharedConstants::SHOW_AUTOSTARTUPS_EVENT, [&](int err)
        {
            if (m_enabled && err == ERROR_SUCCESS)
            {
                Logger::trace(L"{} event was signaled", CommonSharedConstants::SHOW_AUTOSTARTUPS_EVENT);

                if (is_process_running())
                {
                    bring_process_to_front();
                }
                else
                {
                    launch_process(false);
                }

                Trace::ActivateEditor();
            }
        });

        //m_showAdminEventWaiter = EventWaiter(CommonSharedConstants::SHOW_HOSTS_ADMIN_EVENT, [&](int err)
        //{
        //    if (m_enabled && err == ERROR_SUCCESS)
        //    {
        //        Logger::trace(L"{} event was signaled", CommonSharedConstants::SHOW_HOSTS_ADMIN_EVENT);
        //        
        //        if (is_process_running())
        //        {
        //            bring_process_to_front();
        //        }
        //        else
        //        {
        //            launch_process(true);
        //        }

        //        Trace::ActivateEditor();
        //    }
        //});

        triggerEvent = CreateEvent(nullptr, false, false, CommonSharedConstants::SHORTCUT_GUIDE_TRIGGER_EVENT);
        triggerEventWaiter = EventWaiter(CommonSharedConstants::SHORTCUT_GUIDE_TRIGGER_EVENT, [this](int) {
            OnHotkeyEx();
            });

        InitSettings();
    }

    ~AutoStartupsModuleInterface()
    {
        m_enabled = false;
    }

    // Destroy the powertoy and free memory
    virtual void destroy() override
    {
        Logger::trace("AutoStartupsModuleInterface::destroy()");

        if (m_hShowEvent)
        {
            CloseHandle(m_hShowEvent);
            m_hShowEvent = nullptr;
        }

        if (m_hShowAdminEvent)
        {
            CloseHandle(m_hShowAdminEvent);
            m_hShowAdminEvent = nullptr;
        }

        delete this;
    }

    // Return the localized display name of the powertoy
    virtual const wchar_t* get_name() override
    {
        return app_name.c_str();
    }

    // Return the non localized key of the powertoy, this will be cached by the runner
    virtual const wchar_t* get_key() override
    {
        return app_key.c_str();
    }

    // Return the configured status for the gpo policy for the module
    virtual PowerJob_gpo::gpo_rule_configured_t gpo_policy_enabled_configuration() override
    {
        return PowerJob_gpo::getConfiguredHostsFileEditorEnabledValue();
    }

    virtual bool get_config(wchar_t* buffer, int* buffer_size) override
    {
        HINSTANCE hinstance = reinterpret_cast<HINSTANCE>(&__ImageBase);
        PowerJobSettings::Settings settings(hinstance, get_name());
        return settings.serialize_to_buffer(buffer, buffer_size);
    }

    virtual void call_custom_action(const wchar_t* /*action*/) override
    {
    }

    virtual void set_config(const wchar_t* config) override
    {
        Logger::trace("set_config()");
        try
        {
            // Parse the input JSON string.
            PowerJobSettings::PowerToyValues values =
                PowerJobSettings::PowerToyValues::from_json_string(config, get_key());

            ParseSettings(values);
        }
        catch (std::exception& ex)
        {
            Logger::error("Failed to parse settings. {}", ex.what());
        }
    }

    virtual bool is_enabled() override
    {
        return m_enabled;
    }

    virtual void enable()
    {
        Logger::trace("AutoStartupsModuleInterface::enable()");
        m_enabled = true;
        Trace::EnableHostsFileEditor(true);
    };

    virtual void disable()
    {
        Logger::trace("AutoStartupsModuleInterface::disable()");
        if (m_enabled)
        {
            if (m_hShowEvent)
            {
                ResetEvent(m_hShowEvent);
            }

            if (m_hShowAdminEvent)
            {
                ResetEvent(m_hShowAdminEvent);
            }

            //TerminateProcess(m_hProcess, 1);
            TerminateProcess();
        }

        m_enabled = false;
        Trace::EnableHostsFileEditor(false);
    }

    virtual std::optional<HotkeyEx> GetHotkeyEx() override
    {
        Logger::trace("GetHotkeyEx()");
        if (m_shouldReactToPressedWinKey)
        {
            return std::nullopt;
        }
        return m_hotkey;
    }

    virtual void OnHotkeyEx() override
    {
        Logger::trace("OnHotkeyEx()");
        if (!m_enabled)
        {
            return;
        }

        if (IsProcessActive())
        {
            TerminateProcess();
            return;
        }

        if (m_hProcess)
        {
            CloseHandle(m_hProcess);
            m_hProcess = nullptr;
        }

        //StartProcess();
        launch_process(false);
    }

    void TerminateProcess()
    {
        if (m_hProcess)
        {
            if (WaitForSingleObject(m_hProcess, 0) != WAIT_OBJECT_0)
            {
                if (exitEvent && SetEvent(exitEvent))
                {
                    Logger::trace(L"Signaled {}", CommonSharedConstants::SHORTCUT_GUIDE_EXIT_EVENT);
                }
                else
                {
                    Logger::warn(L"Failed to signal {}", CommonSharedConstants::SHORTCUT_GUIDE_EXIT_EVENT);
                }
            }
            else
            {
                CloseHandle(m_hProcess);
                m_hProcess = nullptr;
                Logger::trace("SG process was already terminated");
            }
        }
    }

    bool IsProcessActive()
    {
        return m_hProcess && WaitForSingleObject(m_hProcess, 0) != WAIT_OBJECT_0;
    }

    void InitSettings()
    {
        try
        {
            PowerJobSettings::PowerToyValues settings =
                PowerJobSettings::PowerToyValues::load_from_settings_file(app_key);

            ParseSettings(settings);
        }
        catch (std::exception& ex)
        {
            Logger::error("Failed to init settings. {}", ex.what());
        }
        catch (...)
        {
            Logger::error("Failed to init settings");
        }
    }

    void ParseSettings(PowerJobSettings::PowerToyValues& settings)
    {
        m_shouldReactToPressedWinKey = false;
        m_millisecondsWinKeyPressTimeForGlobalWindowsShortcuts = DEFAULT_MILLISECONDS_WIN_KEY_PRESS_TIME_FOR_GLOBAL_WINDOWS_SHORTCUTS;
        m_millisecondsWinKeyPressTimeForTaskbarIconShortcuts = DEFAULT_MILLISECONDS_WIN_KEY_PRESS_TIME_FOR_TASKBAR_ICON_SHORTCUTS;

        auto settingsObject = settings.get_raw_json();

        Logger::info(settingsObject.Stringify().c_str());

        if (settingsObject.GetView().Size())
        {
            try
            {
                // Parse HotKey
                auto jsonHotkeyObject = settingsObject.GetNamedObject(L"properties").GetNamedObject(L"open_shortcutguide");
                auto hotkey = PowerJobSettings::HotkeyObject::from_json(jsonHotkeyObject);
                m_hotkey = HotkeyEx();
                if (hotkey.win_pressed())
                {
                    m_hotkey.modifiersMask |= MOD_WIN;
                }

                if (hotkey.ctrl_pressed())
                {
                    m_hotkey.modifiersMask |= MOD_CONTROL;
                }

                if (hotkey.shift_pressed())
                {
                    m_hotkey.modifiersMask |= MOD_SHIFT;
                }

                if (hotkey.alt_pressed())
                {
                    m_hotkey.modifiersMask |= MOD_ALT;
                }

                m_hotkey.vkCode = static_cast<WORD>(hotkey.get_code());
            }
            catch (...)
            {
                Logger::warn("Failed to initialize Shortcut Guide start shortcut");
            }
            try
            {
                // Parse Legacy windows key press behavior settings
          /*      auto jsonUseLegacyWinKeyBehaviorObject = settingsObject.GetNamedObject(L"properties").GetNamedObject(L"use_legacy_press_win_key_behavior");
                m_shouldReactToPressedWinKey = jsonUseLegacyWinKeyBehaviorObject.GetNamedBoolean(L"value");
                auto jsonPressTimeForGlobalWindowsShortcutsObject = settingsObject.GetNamedObject(L"properties").GetNamedObject(L"press_time");
                auto jsonPressTimeForTaskbarIconShortcutsObject = settingsObject.GetNamedObject(L"properties").GetNamedObject(L"press_time_for_taskbar_icon_shortcuts");
                int value = static_cast<int>(jsonPressTimeForGlobalWindowsShortcutsObject.GetNamedNumber(L"value"));
                if (value >= 0)
                {
                    m_millisecondsWinKeyPressTimeForGlobalWindowsShortcuts = value;
                }

                else
                {
                    throw std::runtime_error("Invalid Press Time Windows Shortcuts value");
                }
                value = static_cast<int>(jsonPressTimeForTaskbarIconShortcutsObject.GetNamedNumber(L"value"));
                if (value >= 0)
                {
                    m_millisecondsWinKeyPressTimeForTaskbarIconShortcuts = value;
                }
                else
                {
                    throw std::runtime_error("Invalid Press Time Taskbar Shortcuts value");
                }*/
            }
            catch (...)
            {
                Logger::warn("Failed to get legacy win key behavior settings");
            }
        }
        else
        {
            Logger::info("Shortcut Guide settings are empty");
        }

        if (!m_hotkey.modifiersMask)
        {
            Logger::info("Shortcut Guide is going to use default shortcut");
            m_hotkey.modifiersMask = MOD_SHIFT | MOD_WIN;
            m_hotkey.vkCode = VK_OEM_2;
        }
    }
};

extern "C" __declspec(dllexport) PowertoyModuleIface* __cdecl powertoy_create()
{
    return new AutoStartupsModuleInterface();
}