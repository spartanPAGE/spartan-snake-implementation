#include "console_canvas_drawer.hpp"

#include <iostream>
using namespace std;

ConsoleCanvasDrawer::ConsoleCanvasDrawer(
    const Canvas &observed_canvas,
    DrawerFunc drawer_func
): canvas(observed_canvas), draw_at(drawer_func){}

void ConsoleCanvasDrawer::draw(){
    auto buffer = canvas.get_buffer();
    for(size_t y = 0; y < buffer.height(); ++y){
        for(size_t x = 0; x < buffer.width(); ++x)
            cout << buffer[x][y];
        cout.put('\n');
    }
    cout.flush();
}

void ConsoleCanvasDrawer::update(){
    const auto diff = canvas.diff();
    if(diff.empty())
        return;
    for(auto &element : diff)
        draw_at(element.x, element.y, element.val);
    cout.flush();
}