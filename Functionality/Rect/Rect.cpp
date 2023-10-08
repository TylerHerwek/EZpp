#include "Rect.hpp"

using namespace EZ;

Rect::Rect()
    : Pos({})
    , Size({})
{
}

Rect::Rect(int x, int y, int w, int h)
    : Pos({ x, y })
    , Size({ w, h })
{
}

Rect::Rect(const Point pos, const Point size)
    : Pos({ pos.X, pos.Y })
    , Size({ pos.X, pos.Y })
{
}

bool Rect::Collides(const Rect& other) const
{
    if (X + W >= other.X && X <= other.X + other.W && Y + H >= other.Y && Y <= other.Y + other.H) {
        return true;
    }
    return false;
}

bool Rect::Collides(const Point& other) const
{
    if (X + W >= other.X && X <= other.X && Y + H >= other.Y && Y <= other.Y) {
        return true;
    }
    return false;
}
