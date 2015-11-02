#pragma once

namespace Console{
    bool keyboard_hit();
    char get_character();
    void write_character_at(size_t x, size_t y, char c);
    void cursor_visible(bool state);
}