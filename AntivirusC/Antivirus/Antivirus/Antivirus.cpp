// Antivirus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "ru-RU");
    HANDLE mailAntivirusServer;
    HANDLE mailAntivirusClient;

    DWORD msgSize, msgQuantity, read;
    bool retCode;
    char msgBuf[512];

    mailAntivirusServer = CreateMailslot(L"\\\\.\\Mailslot\\mailServer", 0, MAILSLOT_WAIT_FOREVER, NULL);

    while (true) {
        retCode = GetMailslotInfo(mailAntivirusServer, NULL, &msgSize, &msgQuantity, NULL);
        if (retCode = false) {
            fprintf(stdout, "GetMailslotInfo: Error %ld\n", GetLastError());
            break;
        }
        if (msgQuantity != 0) {
            if (ReadFile(mailAntivirusServer, msgBuf, 512, &read, NULL)) {
                printf("Сообщение получено: %s\n", msgBuf);
            }
            else {
                fprintf(stdout, "ReadFile: Error %ld\n", GetLastError());
                break;
            }
        }
    }

}