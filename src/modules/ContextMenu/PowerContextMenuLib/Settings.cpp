#include "pch.h"
#include "Settings.h"
#include "PowerConstants.h"

#include <common/SettingsAPI/settings_helpers.h>

namespace {
	const wchar_t c_powerRenameDataFilePath[] = L"\\power-rename-settings.json";
	const wchar_t c_powerRenameUIFlagsFilePath[] = L"\\power-rename-ui-flags";
}


CSettings::CSettings() {
	/*generalJsonFilePath = PTSettingsHelper::get_PowerJob_general_save_file_location();
	std::wstring result = PTSettingsHelper::get_module_save_folder_location(PowerConstants::ModuleKey);
	moduleJsonFilePath = result + std::wstring(c_powerRenameDataFilePath);
	UIFlagsFilePath = result + std::wstring(c_powerRenameUIFlagsFilePath);
	RefreshEnabledState();
	Load();*/
}

void CSettings::Save()
{
}

void CSettings::Load()
{
}

void CSettings::RefreshEnabledState()
{
}

CSettings& CSettingsInstance()
{
	static CSettings instance;
	return instance;
}
