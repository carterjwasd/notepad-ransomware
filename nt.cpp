#include "nt.h"
#include "win32.h"
#include "strenc.h"

typedef NTSTATUS ntstatus;

typedef NTSTATUS(NTAPI* pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI* pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

nt g_nt;

uintptr_t nt::jmp_raise(ULONG set_privilege, DWORD faults) {
	BOOLEAN enabled; ULONG resp;

	LPVOID func_address = g_win32.get_proc_address(g_win32.load_library(strenc("ntdll.dll")), strenc("RtlAdjustPrivilege"));
	LPVOID func_address2 = g_win32.get_proc_address(g_win32.get_module_handle(strenc("ntdll.dll")), strenc("NtRaiseHardError"));

	pdef_RtlAdjustPrivilege nt_call_rtl_adjust_privilege = (pdef_RtlAdjustPrivilege)func_address;
	pdef_NtRaiseHardError nt_call_raise_hard_error = (pdef_NtRaiseHardError)func_address2;

	ntstatus status = nt_call_rtl_adjust_privilege(19, TRUE, FALSE, &enabled);

	if (!nt_call_raise_hard_error(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &resp))
		return 0;
}