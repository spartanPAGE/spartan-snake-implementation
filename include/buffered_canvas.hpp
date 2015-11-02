#pragma once

#include <functional>

#include "matrix.hpp"

template<typename T>
class BufferedCanvas{
public:
    using Canvas = Matrix<T>;
    using DifferenceData = struct{ size_t x, y; T val; };
    using DifferenceContainer = std::vector<DifferenceData>;
public:
    BufferedCanvas(
        size_t width,
        size_t height
    ): canvas(width, height), buffer(canvas){}
    BufferedCanvas(
        size_t width,
        size_t height,
        T init
    ): canvas(width, height), buffer(0, 0){
        std::fill(std::begin(canvas), std::end(canvas), init);
        buffer = canvas;
    }
public:
    size_t width() const{
        return canvas.width();
    }
    size_t height() const{
        return canvas.height();
    }
    void draw_at(size_t x, size_t y, T val){
        buffer[x][y] = val;
    }
    void fill(T val){
        std::fill(begin(buffer), end(buffer), val);
    }
    const Canvas &get_buffer() const{
        return buffer;
    }
    void update(){
        std::copy(std::begin(buffer), std::end(buffer), std::begin(canvas));
    }
    DifferenceContainer diff() const{
        DifferenceContainer cont;
        for(size_t y = 0; y < canvas.height(); ++y){
            for(size_t x = 0; x < canvas.width(); ++x){
                if(canvas[x][y] != buffer[x][y])
                    cont.push_back({x, y, buffer[x][y]});
            }
        }
        return cont;
    }
private:
    Canvas canvas, buffer;
};