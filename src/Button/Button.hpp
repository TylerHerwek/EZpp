#pragma once
#include "../ColorRect/ColorRect.hpp"
#include "../Sprite/Sprite.hpp"

namespace EZ {
class Button {
public:
    Button(Point* mouse);
    Button(Point* mouse, const Rect& body);
    ~Button();

    void SetHover(const char* URL);
    void SetNormal(const char* URL);

    void Position(const Point& pos);
    const Point* const Position() const;

    void Size(const Point& size);
    const Point* const Size() const;

    void SetBackground(const bool on);

    bool Hover() const;

    void Update();
    void Render() const;

private:
    Rect* _body;
    Sprite *_normalTex, *_hoverTex;
    ColorRect* _background;

    const Point* _mouse;
    bool _hover;
};
}
