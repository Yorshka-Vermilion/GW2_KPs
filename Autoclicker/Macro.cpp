#include "Macro.h"

Macro::Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop, UINT stopKey) {
    this->keys = keys;
    this->pause = pause;
    this->loop = loop;
    this->stopKey = stopKey;
}

void Macro::pressKey(CHAR keyParam, bool ctrl = false) {
    SHORT key;
    UINT mappedkey, mappedkey2;
    INPUT input = { 0 };
    INPUT inputs[2] = {0,0};
    if (ctrl) {
        key = VkKeyScan(keyParam);
        mappedkey = MapVirtualKey(LOBYTE(key), 0);
        mappedkey2 = MapVirtualKey(LOBYTE(VK_CONTROL), 0);

        inputs[0].type = INPUT_KEYBOARD;
        inputs[0].ki.dwFlags = KEYEVENTF_SCANCODE;
        inputs[0].ki.wScan = mappedkey2;

        inputs[1].type = INPUT_KEYBOARD;
        inputs[1].ki.dwFlags = KEYEVENTF_SCANCODE;
        inputs[1].ki.wScan = mappedkey;
        SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
        Sleep(10);
        inputs[0].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        inputs[1].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    }
    else {
        key = VkKeyScan(keyParam);
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

void Macro::run() {
    for (int j = 0; j < count; j++) {
        pressKey(VK_RETURN);
        Sleep(100);
        pressKey('V',true);
        Sleep(50);
        pressKey(VK_RETURN);
        Sleep(100);
    }
}