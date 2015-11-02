#pragma once

#include <functional>

#include "buffered_canvas.hpp"

class ConsoleCanvasDrawer{
public:
    using Canvas = BufferedCanvas<char>;
    using DrawerFunc = std::function<void(size_t, size_t, char)>;
public:
    ConsoleCanvasDrawer(const Canvas &, DrawerFunc);
public:
    void draw();
    void update();
private:
    const Canvas &canvas;
    const DrawerFunc draw_at;
};