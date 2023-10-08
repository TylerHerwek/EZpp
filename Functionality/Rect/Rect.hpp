#pragma once
#include "../Point/Point.hpp"

namespace EZ {
// constains to Points Pos and Size
class Rect {
public:
    Rect();
    Rect(int x, int y, int w, int h);
    Rect(const Point pos, const Point size);

    bool Collides(const Rect& other) const;
    bool Collides(const Point& other) const;

    union {
        Point Pos;
        struct { int X, Y; };
    };
    union {
        Point Size;
        struct { int W, H; };
    };
};
}
