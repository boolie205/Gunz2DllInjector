// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

bool __stdcall DllMain( HMODULE hModule, unsigned long ul_reason_for_call, void* lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MessageBoxA(NULL,"injected","its a title",MB_OK);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return true;
}

