#include "win32.h"
#include "strenc.h"

windows32_t g_win32;

typedef FARPROC(win_api* getprocaddress_t)(HMODULE hModule, LPCSTR lpProcName);
typedef HMODULE(win_api* loadlibrary_t)(LPCSTR lpLibFileName);

typedef HMODULE(win_api* getmodulehandle_t)(LPCSTR lpModuleName);
typedef DWORD(win_api* getmodulefilename_t)(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
typedef DWORD(win_api* getenvironmentvariable_t)(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize);
typedef BOOL(win_api* blockinput_t)(BOOL fBlockIt);
typedef VOID(win_api* sleepingmode_t)(DWORD dwMilliseconds);
typedef BOOL(win_api* showwindow_t)(HWND hWnd, int nCmdShow);
typedef HWND(win_api* getconsolewindow_t)(VOID);
typedef HINSTANCE(win_api* shellexecute_t)(HWND hwnd, LPCSTR lpOperation,
	LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);

FARPROC win_api windows32_t::get_proc_address(HMODULE hModule, LPCSTR lpProcName) {
	LPVOID func_address = GetProcAddress(LoadLibraryA(strenc("Kernel32.dll")), strenc("GetProcAddress"));
	getprocaddress_t getprocaddress = (getprocaddress_t)func_address;
	return getprocaddress(hModule, lpProcName);
}

HMODULE win_api windows32_t::load_library(LPCSTR lpLibFileName) {
	LPVOID func_address = GetProcAddress(LoadLibraryA(strenc("Kernel32.dll")), strenc("LoadLibraryA"));
	loadlibrary_t loadlibrary = (loadlibrary_t)func_address;
	return loadlibrary(lpLibFileName);
}

HMODULE win_api windows32_t::get_module_handle(LPCSTR lpModuleName) {
	LPVOID to_addr = get_proc_address(load_library(strenc("Kernel32.dll")), strenc("GetModuleHandleA"));
	getmodulehandle_t getmodulehandle = (getmodulehandle_t)to_addr;
	return getmodulehandle(lpModuleName);
}

DWORD win_api windows32_t::get_module_file_name(HMODULE hModule, LPSTR lpFilename, DWORD nSize) {
	LPVOID to_addr = get_proc_address(load_library(strenc("Kernel32.dll")), strenc("GetModuleFileNameA"));
	getmodulefilename_t getmodulefilename = (getmodulefilename_t)to_addr;
	return getmodulefilename(hModule, lpFilename, nSize);
}

DWORD win_api windows32_t::get_environment_variable(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize) {
	LPVOID to_addr = get_proc_address(load_library(strenc("Kernel32.dll")), strenc("GetEnvironmentVariableA"));
	getenvironmentvariable_t getenvironmentvariable = (getenvironmentvariable_t)to_addr;
	return getenvironmentvariable(lpName, lpBuffer, nSize);
}

BOOL win_api windows32_t::block_input(BOOL parameter) {
	LPVOID to_addr = get_proc_address(load_library(strenc("User32.dll")), strenc("BlockInput"));
	blockinput_t block_input = (blockinput_t)to_addr;
	return block_input(parameter);
}

VOID win_api windows32_t::sleeping_mode(DWORD dwMilliseconds) {
	LPVOID to_addr = get_proc_address(load_library(strenc("Kernel32.dll")), strenc("Sleep"));
	sleepingmode_t sleepingmode = (sleepingmode_t)to_addr;
	return sleepingmode(dwMilliseconds);
}

BOOL win_api windows32_t::show_window(HWND hWnd, int nCmdShow) {
	LPVOID to_addr = get_proc_address(load_library(strenc("User32.dll")), strenc("ShowWindow"));
	showwindow_t showwindow = (showwindow_t)to_addr;
	return showwindow(hWnd, nCmdShow);
}

HWND win_api windows32_t::get_console_window(VOID) {
	LPVOID to_addr = get_proc_address(load_library(strenc("Kernel32.dll")), strenc("GetConsoleWindow"));
	getconsolewindow_t getconsolewindow = (getconsolewindow_t)to_addr;
	return getconsolewindow();
}

HINSTANCE win_api windows32_t::shell_execute(HWND hwnd, LPCSTR lpOperation,
	LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd) {
	LPVOID to_addr = get_proc_address(load_library(strenc("Shell32.dll")), strenc("ShellExecuteA"));
	shellexecute_t shellexecute = (shellexecute_t)to_addr;
	return shellexecute(hwnd, lpOperation,
		lpFile, lpParameters, lpDirectory, nShowCmd);
}