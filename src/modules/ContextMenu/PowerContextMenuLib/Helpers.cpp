#include "pch.h"
#include "Helpers.h"

bool ShellItemArrayContainsRenamableItem(IShellItemArray* shellItemArray)
{
    bool hasRenamable = false;
    IEnumShellItems* spesi;
    if (SUCCEEDED(shellItemArray->EnumItems(&spesi)))
    {
        ULONG celtFetched;
        IShellItem* spsi;
        while ((S_OK == spesi->Next(1, &spsi, &celtFetched)))
        {
            SFGAOF attrs;
            if (SUCCEEDED(spsi->GetAttributes(SFGAO_CANRENAME, &attrs)) &&
                attrs & SFGAO_CANRENAME)
            {
                hasRenamable = true;
                break;
            }
        }
    }

    return hasRenamable;
}
