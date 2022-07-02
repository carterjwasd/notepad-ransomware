#include <windows.h>

struct nt {
public:
	uintptr_t jmp_raise(ULONG set_privilege, DWORD faults);
};

extern nt g_nt;