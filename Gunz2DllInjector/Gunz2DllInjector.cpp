//DllInjector.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

int main()
{
    HWND gunz = FindWindowA(NULL, "Gunz the Second Duel 1.0.0.55354");
    unsigned long PID = 0;
    GetWindowThreadProcessId(gunz, &PID);
    char currentDirectory[MAX_PATH];
    GetCurrentDirectoryA(MAX_PATH, currentDirectory);
    std::string directory = std::string(currentDirectory) + "\\cheekybreekyhax.dll" ;
    HANDLE h = OpenProcess(PROCESS_ALL_ACCESS,false,PID);
    if (void* loadLibrary = (void*)GetProcAddress(GetModuleHandleA((char*)"kernel32.dll"), (char*)"LoadLibraryA"))
    {

        if (void* allocatedString = VirtualAllocEx(h, NULL, directory.length(), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE))
        {
            WriteProcessMemory(h, allocatedString, directory.c_str(), directory.length(), nullptr);
            CreateRemoteThread(h,NULL, 0, (LPTHREAD_START_ROUTINE)loadLibrary,allocatedString,0,NULL);
        }

    }
    return 0;
}
