#include "console-utils.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include "console-utils.windows.hpp"
namespace UsedImplementation = ConsoleWindowsImpl;
#else
#error There is no avaiable implementation for your platform. Mb make one, tho?
#endif

namespace Console{
    bool keyboard_hit(){
        return UsedImplementation::keyboard_hit();
    }
    char get_character(){
        return UsedImplementation::get_character();
    }
    void write_character_at(size_t x, size_t y, char character){
        UsedImplementation::write_character_at(x, y, character);
    }
    void cursor_visible(bool state){
        UsedImplementation::cursor_visible(state);
    }
}