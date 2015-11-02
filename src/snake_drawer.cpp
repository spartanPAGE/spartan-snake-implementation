#include "snake_drawer.hpp"

SnakeDrawer::SnakeDrawer(
    Canvas &cv,
    const Snake &s
): canvas(cv), snake(s){}

void SnakeDrawer::draw(){
    for(auto &element : snake.get_body()){
        canvas.draw_at(element.x, element.y, element.sign);
    }
}