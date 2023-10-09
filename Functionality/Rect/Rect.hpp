#pragma once
#include "../Point/Point.hpp"
#include "../SDL/SDL.hpp"

namespace EZ {
// constains to Points Pos and Size
class Rect {
public:
    Rect();
    Rect(int x, int y, int w, int h);
    Rect(const Point pos, const Point size);
    Rect(const Rect& other);

    bool Collides(const Rect& other) const;
    bool Collides(const Point& other) const;

    const SDL_Rect* const ToSDLStd() const;

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
