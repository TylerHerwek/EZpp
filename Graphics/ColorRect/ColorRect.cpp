#include "ColorRect.hpp"
using namespace EZ;

// LIFETIME
ColorRect::ColorRect()
    : Rect()
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , _color(new EZ::Color)
{
}

ColorRect::ColorRect(const Rect& body, const EZ::Color& color)
    : Rect(body)
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , _color(new EZ::Color(color))
{
}

ColorRect::ColorRect(const ColorRect& other)
    : Rect(other.Pos, other.Size)
    , Thickness(other.Thickness)
    , _color(new EZ::Color(*other._color))
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
    if (!window) {
        perror("The renderer Window is not initialized!");
        perror("Set the static CanvasItem::window field to a Window pointer to fix this issue.");
        return;
    }

    window->SetColor(_color->R, _color->G, _color->B, _color->A);
    switch (Mode) {
    case COLORRECT::OUTLINE:
        window->DrawRectOutline(X, Y, W, Y, Thickness);
        break;
    case COLORRECT::FILL:
        window->DrawRect(X, Y, W, H);
        break;
    }
}
