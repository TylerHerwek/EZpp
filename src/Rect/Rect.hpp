#pragma once
#include "../Point/Point.hpp"

namespace EZ {
class Sprite;
class ColorRect;
class CanvasGroup;
class TextField;

// constains to Points Pos and Size
class Rect {
public:
    Rect();
    Rect(int x, int y, int w, int h);
    Rect(const Point& pos, const Point& size);
    Rect(Point* pos, Point* size);
    Rect(const Rect& other);
    ~Rect();

    bool Collides(const Rect& other) const;
    bool Collides(const Point& other) const;

    void Position(const Point& pos);
    const Point* const Position() const;

    void Size(const Point& pos);
    const Point* const Size() const;

    void Set(const Rect& other);

    friend Sprite;
    friend ColorRect;
    friend CanvasGroup;
    friend TextField;

private:
    Point* _position;
    Point* _size;
};
}
