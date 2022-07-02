#pragma once
#include <windows.h>

#include <iphlpapi.h>
#include <wininet.h>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "wininet.lib")

#define win_api WINAPI

struct windows32_t {
public:
	FARPROC win_api get_proc_address(HMODULE hModule, LPCSTR lpProcName);
	HMODULE win_api load_library(LPCSTR lpLibFileName);
public:
	HMODULE win_api get_module_handle(LPCSTR lpModuleName);
	DWORD win_api get_module_file_name(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
	DWORD win_api get_environment_variable(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize);
	BOOL win_api block_input(BOOL parameter);
	VOID win_api sleeping_mode(DWORD dwMilliseconds);
	BOOL win_api show_window(HWND hWnd, int nCmdShow);
	HWND win_api get_console_window(VOID);
	HINSTANCE win_api shell_execute(HWND hwnd, LPCSTR lpOperation, 
		LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
};

extern windows32_t g_win32;