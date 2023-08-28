// Autoclicker.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <windows.h>
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Macro.h"
void Nadupiaj()
{

    INPUT inputs[4] = {};
    ZeroMemory(inputs, sizeof(inputs));

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_MENU;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = VK_TAB;

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_MENU;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = VK_TAB;
    inputs[3].ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

    Sleep(500);

    INPUT inputs2[4] = {};

    inputs2[0].type = INPUT_KEYBOARD;
    inputs2[0].ki.wVk = VK_SHIFT;

    inputs2[1].type = INPUT_KEYBOARD;
    inputs2[1].ki.wVk = 0x53;

    inputs2[2].type = INPUT_KEYBOARD;
    inputs2[2].ki.wVk = VK_SHIFT;
    inputs2[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs2[3].type = INPUT_KEYBOARD;
    inputs2[3].ki.wVk = 0x53;
    inputs2[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputs2), inputs2, sizeof(INPUT));

    Sleep(500);

    INPUT inputss[2] = {};

    inputss[0].type = INPUT_KEYBOARD;
    inputss[0].ki.wVk = VK_RIGHT;

    inputss[1].type = INPUT_KEYBOARD;
    inputss[1].ki.wVk = VK_RIGHT;
    inputss[1].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputss), inputss, sizeof(INPUT));

    Sleep(500);

    SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

    Sleep(500);

    INPUT inputs3[4] = {};

    inputs3[0].type = INPUT_KEYBOARD;
    inputs3[0].ki.wVk = VK_CONTROL;

    inputs3[1].type = INPUT_KEYBOARD;
    inputs3[1].ki.wVk = 0x56;

    inputs3[2].type = INPUT_KEYBOARD;
    inputs3[2].ki.wVk = VK_CONTROL;
    inputs3[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs3[3].type = INPUT_KEYBOARD;
    inputs3[3].ki.wVk = 0x56;
    inputs3[3].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(ARRAYSIZE(inputs3), inputs3, sizeof(INPUT));

    Sleep(500);


}


void test() {
    while (!GetAsyncKeyState(VK_NUMPAD0)) {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD1)) { //my old version
            INPUT input = { 0 };
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = VkKeyScan('w');
            SendInput(1, &input, sizeof(input));
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) { //new version (King Gore)
            SHORT key;
            UINT mappedkey;
            INPUT input = { 0 };
            key = VkKeyScan('w');
            mappedkey = MapVirtualKey(LOBYTE(key), 0);
            input.type = INPUT_KEYBOARD;
            input.ki.dwFlags = KEYEVENTF_SCANCODE;
            input.ki.wScan = mappedkey;
            SendInput(1, &input, sizeof(input));
            Sleep(10);
            input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
            SendInput(1, &input, sizeof(input));
        }
    }
}

int main() {
    while (!GetAsyncKeyState(VK_NUMPAD0)) {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            std::vector<CHAR> keys = { VK_RETURN,'V', VK_RETURN};
            std::vector<DWORD> pause{ 1,1,1,1 };
            Macro macro = Macro(keys, pause, true, VK_NUMPAD9);
            macro.run();
        }
    }
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
