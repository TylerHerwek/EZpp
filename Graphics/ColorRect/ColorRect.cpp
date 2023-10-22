#include "ColorRect.hpp"
#include <cstdio>
using namespace EZ;

// LIFETIME
ColorRect::ColorRect()
    : Rect()
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , _color(new EZ::Color)
	, Visible(true)
{
}

ColorRect::ColorRect(const Rect& body, const EZ::Color& color)
    : Rect(body)
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , _color(new EZ::Color(color))
	, Visible(true)
{
}

ColorRect::ColorRect(const ColorRect& other)
    : Rect(other.Pos, other.Size)
    , Thickness(other.Thickness)
    , Mode(other.Mode)
    , _color(new EZ::Color(*other._color))
	, Visible(other.Visible)
{
}

unique_ptr<ColorRect> ColorRect::Duplicate() const
{
    return std::make_unique<ColorRect>(*this);
}

ColorRect::~ColorRect()
{
    delete _color;
    _color = nullptr;
}

EZ::Color* const ColorRect::Color() const
{
    return _color;
}

void ColorRect::Render() const
{
	if(!Visible) return;
    if (!window) {
        perror("The renderer Window is not initialized!");
        perror("Set the static CanvasItem::window field to a Window pointer to fix this issue.");
        return;
    }

    window->SetColor(_color->R, _color->G, _color->B, _color->A);

    switch (Mode) {
    case COLORRECT::OUTLINE:
        window->DrawRectOutline({X, Y, W, H}, Thickness);
        break;
    case COLORRECT::FILL:
        window->DrawRect({Pos, Size});
        break;
    default:
        perror("wrong mode!: " << (int)Mode);
        break;
    }
}
