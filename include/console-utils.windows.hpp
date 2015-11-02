#pragma once

#include "conio.h"
#include "windows.h"

#include <iostream>

namespace ConsoleWindowsImpl{
    bool keyboard_hit(){
        return _kbhit() != 0;
    }

    char get_character(){
        return _getch();
    }

    void write_character_at(size_t x, size_t y, char c){
        static auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(handle, {(short)x, (short)y});
        std::cout.put(c);
    }
    void cursor_visible(bool state){
        static auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(handle, &cursorInfo);
        cursorInfo.bVisible = state; // set the cursor visibility
        SetConsoleCursorInfo(handle, &cursorInfo);
    }
}