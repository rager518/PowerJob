// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include "resource.h"

//#include <atlfile.h>
//#include <atlstr.h>
#include <shobjidl_core.h>
//#include <string>
//#include <filesystem>
//#include <sstream>
//#include <Shlwapi.h>
//#include <vector>
//#include <wil\resource.h>
//#include <wil\win32_helpers.h>
#include <wil/stl.h>
#include <wrl/module.h>
#include <wrl/implements.h>
#include <string>
#include <Shlwapi.h>
#include <common/utils/resources.h>
#include <common/utils/process_path.h>
#include <PowerContextMenuLib/Settings.h>
#include <PowerContextMenuLib/Helpers.h>

//#include <wrl/client.h>

//
//#include <mutex>
//#include <thread>
//#include <shellapi.h>

using namespace Microsoft::WRL;

HINSTANCE g_hInst = 0;


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		g_hInst = hModule;
		//Trace
		break;
	//case DLL_THREAD_ATTACH:
	//case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:

		break;
	}
	return TRUE;
}

class _declspec(uuid("2861E28B-A1F0-4EF4-A1FE-4C8CA88E2174"))  PowerContextMenuCommand final :public RuntimeClass<RuntimeClassFlags<ClassicCom>, IExplorerCommand, IObjectWithSite>
{
public:
	virtual const wchar_t* Title() { return L"PowerJob"; }
	virtual const EXPCMDFLAGS Flags() { return ECF_DEFAULT; }
	virtual const EXPCMDSTATE State(_In_opt_ IShellItemArray* selection) { return ECS_ENABLED; }

	// IExplorerCommand
	IFACEMETHODIMP GetTitle(_In_opt_ IShellItemArray* items, _Outptr_result_nullonfailure_ PWSTR* name)
	{
		return SHStrDup(context_menu_caption.c_str(), name);
	}

	IFACEMETHODIMP GetIcon(_In_opt_ IShellItemArray*, _Outptr_result_nullonfailure_ PWSTR* icon)
	{
		if (!CSettingsInstance().GetShowIconOnMenu())
		{
			*icon = nullptr;
			return E_NOTIMPL;
		}

		std::wstring iconResourcePath = get_module_folderpath(g_hInst);
		iconResourcePath += L"\\Assets\\";
		iconResourcePath += L"fav.ico";
		return SHStrDup(iconResourcePath.c_str(), icon);
	}

	IFACEMETHODIMP GetToolTip(_In_opt_ IShellItemArray*, _Outptr_result_nullonfailure_ PWSTR* infoTip)
	{
		*infoTip = nullptr;
		return E_NOTIMPL;
	}

	IFACEMETHODIMP GetState(_In_opt_ IShellItemArray* selection, _In_ BOOL okToBeSlow, _Out_ EXPCMDSTATE* cmdState)
	{
		*cmdState = ECS_ENABLED;

		if (!CSettingsInstance().GetEnabled())
		{
			*cmdState = ECS_HIDDEN;
			return S_OK;
		}

		// Check if we should only be on the extended context menu
		if (CSettingsInstance().GetExtendedContextMenuOnly())
		{
			*cmdState = ECS_HIDDEN;
			return S_OK;
		}

		// When right clicking directory background, selection is empty. This prevents checking if there
		// are renamable items, but internal PowerRename logic will prevent renaming non-renamable items anyway.
		if (nullptr == selection) {
			return S_OK;
		}

		// Check if at least one of the selected items is actually renamable.
		if (!ShellItemArrayContainsRenamableItem(selection))
		{
			*cmdState = ECS_HIDDEN;
			return S_OK;
		}

		return S_OK;
	}

	IFACEMETHODIMP GetCanonicalName(_Out_ GUID* guidCommandName)
	{
		*guidCommandName = __uuidof(this);
		return S_OK;
	}

	IFACEMETHODIMP Invoke(_In_opt_ IShellItemArray* selection, _In_opt_ IBindCtx*) noexcept
		try
	{
		if (selection)
		{
			//RunPowerRename(selection);
		}

		return S_OK;
	}
	CATCH_RETURN();

	IFACEMETHODIMP GetFlags(_Out_ EXPCMDFLAGS* flags)
	{
		*flags = Flags();
		return S_OK;
	}
	IFACEMETHODIMP EnumSubCommands(_COM_Outptr_ IEnumExplorerCommand** enumCommands)
	{
		*enumCommands = nullptr;
		return E_NOTIMPL;
	}

	// IObjectWithSite
	IFACEMETHODIMP SetSite(_In_ IUnknown* site) noexcept
	{
		m_site = site;
		return S_OK;
	}
	IFACEMETHODIMP GetSite(_In_ REFIID riid, _COM_Outptr_ void** site) noexcept { return m_site.CopyTo(riid, site); }

protected:
	ComPtr<IUnknown> m_site;
private:
	std::wstring context_menu_caption = GET_RESOURCE_STRING_FALLBACK(IDS_POWERJOB_CONTEXT_MENU_ENTRY, L"Rename with PowerJob");
};

CoCreatableClass(PowerContextMenuCommand)
CoCreatableClassWrlCreatorMapInclude(PowerContextMenuCommand)

STDAPI DllGetActivationFactory(_In_ HSTRING activatableClassId, _COM_Outptr_ IActivationFactory** factory)
{
	return Module<ModuleType::InProc>::GetModule().GetActivationFactory(activatableClassId, factory);
}

STDAPI DllCanUnloadNow()
{
	return Module<InProc>::GetModule().GetObjectCount() == 0 ? S_OK : S_FALSE;
}

STDAPI DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _COM_Outptr_ void** instance)
{
	return Module<InProc>::GetModule().GetClassObject(rclsid, riid, instance);
}