#include <iostream>
#include <windows.h>
#include <lm.h>

#pragma comment(lib, "Netapi32.lib")

int main() {
    USER_INFO_1003 ui;
    DWORD dwLevel = 1003;
    DWORD dwError = 0;

    LPWSTR usuario = (LPWSTR)L"ejemploJuan"; // Nombre del usuario
    ui.usri1003_password = (LPWSTR)L"contraseña2"; // Contraseña


    // Llama a NetUserAdd para crear el usuario
    NET_API_STATUS nStatus = NetUserSetInfo(NULL, usuario, dwLevel, (LPBYTE)&ui, &dwError);


    if (nStatus == NERR_Success) {
        std::wcout << "Contraseña cambiada con éxito" << std::endl;
    } else {
        std::wcout << L"Error al cambiar contraseña. Código de error: " << nStatus << std::endl;
    }

    return 0;
}
