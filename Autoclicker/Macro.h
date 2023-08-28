#pragma once

#include <Windows.h>
#include <iostream>
#include <vector>

class Macro
{
    std::vector<CHAR> keys;
    std::vector<DWORD> pause;
    bool loop = false;
    UINT stopKey = VK_NUMPAD5;
    int count = 3;

public:
    Macro(std::vector<CHAR> keys, std::vector<DWORD> pause, bool loop = false, UINT stopKey = VK_NUMPAD5);
    static void pressKey(CHAR keyParam, bool ctrl);
    void run();
};