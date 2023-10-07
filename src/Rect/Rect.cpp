#include "Rect.hpp"

using namespace EZ;

Rect::Rect()
    : _position(new Point)
    , _size(new Point)
{
}

Rect::Rect(int x, int y, int w, int h)
    : _position(new Point(x, y))
    , _size(new Point(w, h))
{
}

Rect::Rect(const Point& pos, const Point& size)
    : _position(new Point(pos.x, pos.y))
    , _size(new Point(size.x, size.y))
{
}

Rect::Rect(const Rect& other)
    : _position(new Point(other._position->x, other._position->y))
    , _size(new Point(other._size->x, other._size->y))
{
}

Rect::Rect(Point* pos, Point* size)
    : _position(pos)
    , _size(size)
{
}

Rect::~Rect()
{
    delete _position;
    delete _size;
}

bool Rect::Collides(const Rect& other) const
{
    if (_position->x + _size->x >= other._position->x && _position->x <= other._position->x + other._size->x && _position->y + _size->y >= other._position->y && _position->y <= other._position->y + other._size->y)
        return true;
    return false;
}

bool Rect::Collides(const Point& other) const
{
    if (_position->x + _size->x >= other.x && _position->x <= other.x && _position->y + _size->y >= other.y && _position->y <= other.y) {
        return true;
    }
    return false;
}

void Rect::Position(const Point& pos)
{
    _position->x = pos.x;
    _position->y = pos.y;
}
const Point* const Rect::Position() const
{
    return _position;
}

void Rect::Size(const Point& size)
{
    _size->x = size.x;
    _size->y = size.y;
}
const Point* const Rect::Size() const
{
    return _size;
}

void Rect::Set(const Rect& other)
{
    Position(*other._position);
    Size(*other._size);
}
