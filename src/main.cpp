#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;
using namespace std::literals;

#include "matrix.hpp"
#include "console-utils.hpp"

#include "keyboard_input_handler.hpp"
#include "buffered_canvas.hpp"
#include "console_canvas_drawer.hpp"
#include "snake.hpp"
#include "snake_drawer.hpp"

auto gen_snake_body(){
    Snake::Body result;
    string text = "spartanPAGE";
    for(size_t i = 0; i < text.size(); ++i)
        result.push_back({i, 1, text[i]});
    reverse(begin(result), end(result));
    return result;
}

int main(){
    bool running = true;
    BufferedCanvas<char> canvas(70, 20);
    ConsoleCanvasDrawer console_drawer(canvas, Console::write_character_at);
    Snake snake(gen_snake_body(), Way::down, {0, 0, canvas.width(), canvas.height()});
    SnakeDrawer snake_drawer(canvas, snake);

    KeyboardInputHandler keyboard({
        {'e', [&]{ running = false; }},
        {'w', [&]{ snake.set_direction(Way::up); }},
        {'s', [&]{ snake.set_direction(Way::down); }},
        {'a', [&]{ snake.set_direction(Way::left); }},
        {'d', [&]{ snake.set_direction(Way::right); }}
    }, Console::keyboard_hit, Console::get_character);

    
    auto begin_drawing = [&]{ canvas.fill('.'); };
    auto end_drawing = [&]{ console_drawer.update(); };

    Console::cursor_visible(false);
    console_drawer.draw();
    while(running){
        keyboard.update();
        snake.move();

        begin_drawing();
        snake_drawer.draw();
        end_drawing();

        canvas.update();

        this_thread::sleep_for(50ms);
    }
}