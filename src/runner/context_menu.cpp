#include "pch.h"
#include "context_menu.h"

#include <windows.h>
#include <tchar.h>
#include <iostream>

// 添加右键菜单项的函数
void addRightClickMenuItemFile() {
	HKEY hKey;
	HKEY hCommandKey;
	LONG result;

	// 创建注册表项：HKEY_CLASSES_ROOT\*\shell\StartRightClick
	result = RegCreateKeyEx(
		HKEY_CLASSES_ROOT,
		TEXT("*\\shell\\StartRightClick"),  // 为所有文件创建上下文菜单
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WRITE,
		NULL,
		&hKey,
		NULL
	);

	if (result == ERROR_SUCCESS) {
		std::wcout << L"成功创建或打开了注册表键。\n";

		// 设置显示的菜单名称为 "开始右键"
		const TCHAR* menuName = TEXT("Start Right Test");
		result = RegSetValueEx(
			hKey,
			NULL,               // 默认值
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(menuName),  // 使用 C++ 风格的类型转换
			static_cast<DWORD>((_tcslen(menuName) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"成功设置菜单名称。\n";
		}
		else {
			std::wcerr << L"设置菜单名称失败。\n";
		}

		// 设置右键菜单项的图标：例如 notepad.exe 的第一个图标
		const TCHAR* iconPath = TEXT("notepad.exe,0");
		result = RegSetValueEx(
			hKey,
			TEXT("Icon"),       // 设置 Icon 键
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(iconPath),  // 使用 C++ 风格的类型转换
			static_cast<DWORD>((_tcslen(iconPath) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"成功设置菜单图标。\n";
		}
		else {
			std::wcerr << L"设置菜单图标失败。\n";
		}

		// 创建命令子项：HKEY_CLASSES_ROOT\*\shell\StartRightClick\command
		result = RegCreateKeyEx(
			hKey,
			TEXT("command"),
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_WRITE,
			NULL,
			&hCommandKey,
			NULL
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"成功创建或打开了命令键。\n";

			// 设置要执行的程序路径 (例如：notepad.exe)
			const char* command = "notepad.exe";  // 可以换成你想要执行的程序路径
			result = RegSetValueEx(
				hCommandKey,
				NULL,               // 默认值
				0,
				REG_SZ,
				reinterpret_cast<const BYTE*>(command),  // 使用 C++ 风格的类型转换
				static_cast<DWORD>(strlen(command) + 1)
			);

			if (result == ERROR_SUCCESS) {
				std::wcout << L"成功设置命令。\n";
			}
			else {
				std::wcerr << L"设置命令失败。\n";
			}

			RegCloseKey(hCommandKey);
		}
		else {
			std::wcerr << L"创建命令键失败。\n";
		}

		RegCloseKey(hKey);
	}
	else {
		std::wcerr << L"创建或打开注册表键失败。\n";
	}
}

void addRightClickMenuItemEmpty() {
	HKEY hKey;
	HKEY hCommandKey;
	LONG result;

	// 创建注册表项：HKEY_CLASSES_ROOT\*\shell\StartRightClick
	result = RegCreateKeyEx(
		HKEY_CLASSES_ROOT,
		TEXT("Directory\\Background\\shell\\StartRightClick"),  // 为所有文件创建上下文菜单
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WRITE,
		NULL,
		&hKey,
		NULL
	);

	if (result == ERROR_SUCCESS) {
		std::wcout << L"成功创建或打开了注册表键。\n";

		// 设置显示的菜单名称为 "开始右键"
		const TCHAR* menuName = TEXT("Auto StartUp");
		result = RegSetValueEx(
			hKey,
			NULL,               // 默认值
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(menuName),  // 使用 C++ 风格的类型转换
			static_cast<DWORD>((_tcslen(menuName) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"成功设置菜单名称。\n";
		}
		else {
			std::wcerr << L"设置菜单名称失败。\n";
		}

		// 设置右键菜单项的图标：例如 notepad.exe 的第一个图标
		const TCHAR* iconPath = TEXT("notepad.exe,0");
		result = RegSetValueEx(
			hKey,
			TEXT("Icon"),       // 设置 Icon 键
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(iconPath),  // 使用 C++ 风格的类型转换
			static_cast<DWORD>((_tcslen(iconPath) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"成功设置菜单图标。\n";
		}
		else {
			std::wcerr << L"设置菜单图标失败。\n";
		}

		// 创建命令子项：HKEY_CLASSES_ROOT\*\shell\StartRightClick\command
		result = RegCreateKeyEx(
			hKey,
			TEXT("command"),
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_WRITE,
			NULL,
			&hCommandKey,
			NULL
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"成功创建或打开了命令键。\n";

			// 设置要执行的程序路径 (例如：notepad.exe)
			const wchar_t* command = L"E:\\github\\PowerJob\\x64\\Debug\\WinUI3Apps\\PowerJob.AutoStartups.exe";
			result = RegSetValueExW(
				hCommandKey,
				NULL,               // 默认值
				0,
				REG_SZ,
				reinterpret_cast<const BYTE*>(command),
				static_cast<DWORD>((wcslen(command) + 1) * sizeof(wchar_t))
			);

			if (result == ERROR_SUCCESS) {
				std::wcout << L"成功设置命令。\n";
			}
			else {
				std::wcerr << L"设置命令失败。\n";
			}

			RegCloseKey(hCommandKey);
		}
		else {
			std::wcerr << L"创建命令键失败。\n";
		}

		RegCloseKey(hKey);
	}
	else {
		std::wcerr << L"创建或打开注册表键失败。\n";
	}
}

