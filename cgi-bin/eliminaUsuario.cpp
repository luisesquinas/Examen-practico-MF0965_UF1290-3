#include <iostream>
#include <windows.h>
#include <lm.h>

#pragma comment(lib, "Netapi32.lib")

int main() {
    USER_INFO_1 ui;
    DWORD dwLevel = 1;
    DWORD dwError = 0;

    LPWSTR usuario = (LPWSTR)L"ejemploJuan"; // Nombre del usuario

    // Llama a NetUserAdd para crear el usuario
    NET_API_STATUS nStatus = NetUserDel(NULL, usuario);


    if (nStatus == NERR_Success) {
        std::wcout << L"Usuario eliminado con éxito" << std::endl;
    } else {
        std::wcout << L"Error al eliminar el usuario. Código de error: " << nStatus << std::endl;
    }

    return 0;
}
