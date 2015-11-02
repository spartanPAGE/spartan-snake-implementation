#pragma once
#include <vector>

enum class Way{ none, up, down, left, right };

class Snake{
public:
    using BodySegment = struct{ size_t x, y; char sign; };
    using Body = std::vector<BodySegment>;
    struct Limiter{
        size_t min_x, min_y, max_x, max_y;
    };
public:
    Snake(const Body &body_segments, Way dir, Limiter limiter);
    const BodySegment &head() const;
    BodySegment &head();
    const Body &get_body() const;
    void move();
    void set_direction(Way);
private:
    Way direction;
    Body body;
    Limiter limit;
};