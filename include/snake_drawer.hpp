#pragma once

#include "snake.hpp"
#include "buffered_canvas.hpp"

class SnakeDrawer{
public:
    using Canvas = BufferedCanvas<char>;
public:
    SnakeDrawer(Canvas &canvas, const Snake &snake);
public:
    void draw();
private:
    Canvas &canvas;
    const Snake &snake;
};