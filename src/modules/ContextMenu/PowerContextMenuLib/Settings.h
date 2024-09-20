#pragma once

#include "pch.h"


class CSettings
{
public:
	CSettings();

	inline bool GetEnabled()
	{
		return true;
	}

	inline bool GetShowIconOnMenu() const
	{
		return settings.showIconOnMenu;
	}
	inline bool GetExtendedContextMenuOnly() const
	{
		return settings.extendedContextMenuOnly;
	}

	void Save();
	void Load();

private:
	struct Settings
	{
		bool enabled{ true };
		bool showIconOnMenu{ true };
		bool extendedContextMenuOnly{ false }; // Disabled by default.
		bool persistState{ true };
		bool useBoostLib{ false }; // Disabled by default.
		bool MRUEnabled{ true };
		unsigned int maxMRUSize{ 10 };
		unsigned int flags{ 0 };
	};

	void RefreshEnabledState();

	Settings settings;
	std::wstring  generalJsonFilePath;
	/*std::wstring moduleJsonFilePath;
	std::wstring UIFlagsFilePath;*/
};


CSettings& CSettingsInstance();
