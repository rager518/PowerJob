#include "pch.h"
#include "context_menu.h"

#include <windows.h>
#include <tchar.h>
#include <iostream>

// ����Ҽ��˵���ĺ���
void addRightClickMenuItemFile() {
	HKEY hKey;
	HKEY hCommandKey;
	LONG result;

	// ����ע����HKEY_CLASSES_ROOT\*\shell\StartRightClick
	result = RegCreateKeyEx(
		HKEY_CLASSES_ROOT,
		TEXT("*\\shell\\StartRightClick"),  // Ϊ�����ļ����������Ĳ˵�
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WRITE,
		NULL,
		&hKey,
		NULL
	);

	if (result == ERROR_SUCCESS) {
		std::wcout << L"�ɹ����������ע������\n";

		// ������ʾ�Ĳ˵�����Ϊ "��ʼ�Ҽ�"
		const TCHAR* menuName = TEXT("Start Right Test");
		result = RegSetValueEx(
			hKey,
			NULL,               // Ĭ��ֵ
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(menuName),  // ʹ�� C++ ��������ת��
			static_cast<DWORD>((_tcslen(menuName) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"�ɹ����ò˵����ơ�\n";
		}
		else {
			std::wcerr << L"���ò˵�����ʧ�ܡ�\n";
		}

		// �����Ҽ��˵����ͼ�꣺���� notepad.exe �ĵ�һ��ͼ��
		const TCHAR* iconPath = TEXT("notepad.exe,0");
		result = RegSetValueEx(
			hKey,
			TEXT("Icon"),       // ���� Icon ��
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(iconPath),  // ʹ�� C++ ��������ת��
			static_cast<DWORD>((_tcslen(iconPath) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"�ɹ����ò˵�ͼ�ꡣ\n";
		}
		else {
			std::wcerr << L"���ò˵�ͼ��ʧ�ܡ�\n";
		}

		// �����������HKEY_CLASSES_ROOT\*\shell\StartRightClick\command
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
			std::wcout << L"�ɹ�����������������\n";

			// ����Ҫִ�еĳ���·�� (���磺notepad.exe)
			const char* command = "notepad.exe";  // ���Ի�������Ҫִ�еĳ���·��
			result = RegSetValueEx(
				hCommandKey,
				NULL,               // Ĭ��ֵ
				0,
				REG_SZ,
				reinterpret_cast<const BYTE*>(command),  // ʹ�� C++ ��������ת��
				static_cast<DWORD>(strlen(command) + 1)
			);

			if (result == ERROR_SUCCESS) {
				std::wcout << L"�ɹ��������\n";
			}
			else {
				std::wcerr << L"��������ʧ�ܡ�\n";
			}

			RegCloseKey(hCommandKey);
		}
		else {
			std::wcerr << L"���������ʧ�ܡ�\n";
		}

		RegCloseKey(hKey);
	}
	else {
		std::wcerr << L"�������ע����ʧ�ܡ�\n";
	}
}

void addRightClickMenuItemEmpty() {
	HKEY hKey;
	HKEY hCommandKey;
	LONG result;

	// ����ע����HKEY_CLASSES_ROOT\*\shell\StartRightClick
	result = RegCreateKeyEx(
		HKEY_CLASSES_ROOT,
		TEXT("Directory\\Background\\shell\\StartRightClick"),  // Ϊ�����ļ����������Ĳ˵�
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_WRITE,
		NULL,
		&hKey,
		NULL
	);

	if (result == ERROR_SUCCESS) {
		std::wcout << L"�ɹ����������ע������\n";

		// ������ʾ�Ĳ˵�����Ϊ "��ʼ�Ҽ�"
		const TCHAR* menuName = TEXT("Auto StartUp");
		result = RegSetValueEx(
			hKey,
			NULL,               // Ĭ��ֵ
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(menuName),  // ʹ�� C++ ��������ת��
			static_cast<DWORD>((_tcslen(menuName) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"�ɹ����ò˵����ơ�\n";
		}
		else {
			std::wcerr << L"���ò˵�����ʧ�ܡ�\n";
		}

		// �����Ҽ��˵����ͼ�꣺���� notepad.exe �ĵ�һ��ͼ��
		const TCHAR* iconPath = TEXT("notepad.exe,0");
		result = RegSetValueEx(
			hKey,
			TEXT("Icon"),       // ���� Icon ��
			0,
			REG_SZ,
			reinterpret_cast<const BYTE*>(iconPath),  // ʹ�� C++ ��������ת��
			static_cast<DWORD>((_tcslen(iconPath) + 1) * sizeof(TCHAR))
		);

		if (result == ERROR_SUCCESS) {
			std::wcout << L"�ɹ����ò˵�ͼ�ꡣ\n";
		}
		else {
			std::wcerr << L"���ò˵�ͼ��ʧ�ܡ�\n";
		}

		// �����������HKEY_CLASSES_ROOT\*\shell\StartRightClick\command
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
			std::wcout << L"�ɹ�����������������\n";

			// ����Ҫִ�еĳ���·�� (���磺notepad.exe)
			const wchar_t* command = L"E:\\github\\PowerJob\\x64\\Debug\\WinUI3Apps\\PowerJob.AutoStartups.exe";
			result = RegSetValueExW(
				hCommandKey,
				NULL,               // Ĭ��ֵ
				0,
				REG_SZ,
				reinterpret_cast<const BYTE*>(command),
				static_cast<DWORD>((wcslen(command) + 1) * sizeof(wchar_t))
			);

			if (result == ERROR_SUCCESS) {
				std::wcout << L"�ɹ��������\n";
			}
			else {
				std::wcerr << L"��������ʧ�ܡ�\n";
			}

			RegCloseKey(hCommandKey);
		}
		else {
			std::wcerr << L"���������ʧ�ܡ�\n";
		}

		RegCloseKey(hKey);
	}
	else {
		std::wcerr << L"�������ע����ʧ�ܡ�\n";
	}
}

