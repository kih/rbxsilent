#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

static BOOL CALLBACK windcallback(HWND hWnd, LPARAM lparam) {
    int length = GetWindowTextLengthA(hWnd) + 1;
    char* buffer = new char[length];
    GetWindowTextA(hWnd, buffer, length);
    std::string title(buffer);

    if (title == "Roblox" && IsWindowVisible(hWnd)) {
        ShowWindow(hWnd, SW_HIDE);
        PostMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, 0);
        cout << "Found roblox window " << hWnd << endl;
    }

    delete[] buffer;
    return true;
}

int main(int argc, char** argv) {
    cout << "[kih] All ROBLOX clients will now be hidden." << endl;
    while (true) {
        EnumWindows(windcallback, 0);
        Sleep(1);
    }
    return 0;
}