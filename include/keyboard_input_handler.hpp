#pragma once
#include <functional>
#include <map>

class KeyboardInputHandler{
    using Key = char;
    using Action = std::function<void()>;
    using KeyActionMap = std::map<Key, Action>;

    using InputAvaiableFunc = std::function<bool()>;
    using InputFunc = std::function<Key()>;
public:
    KeyboardInputHandler(const KeyActionMap &map, InputAvaiableFunc input_avaiable, InputFunc input);
public:
    void handle(Key key) const;
    void update() const;
private:
    const KeyActionMap key_mapped_actions;
    const InputAvaiableFunc is_input_avaiable;
    const InputFunc get_input;
};