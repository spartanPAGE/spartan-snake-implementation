#include "keyboard_input_handler.hpp"

KeyboardInputHandler::KeyboardInputHandler(
    const KeyActionMap &map, 
    InputAvaiableFunc avail_func, 
    InputFunc input_func
): key_mapped_actions(map), is_input_avaiable(avail_func), get_input(input_func)
{}

void KeyboardInputHandler::handle(Key key) const{
    if(key_mapped_actions.count(key))
        key_mapped_actions.at(key)();
}

void KeyboardInputHandler::update() const{
    while(is_input_avaiable())
        handle(get_input());
}