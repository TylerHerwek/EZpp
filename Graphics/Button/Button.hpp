#pragma once
#include "../ColorRect/ColorRect.hpp"
#include "../Sprite/Sprite.hpp"
#include "string"

namespace EZ {
class Button {
public:
    Button(const Point* const mouse);
    Button(const Point* const mouse, const Rect& body);
    ~Button();

    void SetHover(const std::string& URL);
    void SetNormal(const std::string& URL);

    void Pos(const Point pos);
    Point Pos() const;

    void Size(const Point size);
    Point Size() const;

    void SetBackground(const bool on);


    void Update();
    void Render() const;

    const bool Hover() const;
	int Value;
	bool Disabled;

private:
    Rect* _body;
    Sprite *_normalTex, *_hoverTex;
    ColorRect* _background;
    const Point* const _mouse;
	bool _hover;
};
}
