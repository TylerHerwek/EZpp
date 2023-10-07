#include "ColorRect.hpp"
using namespace EZ;

// LIFETIME
ColorRect::ColorRect()
    : _body(new Rect(new Point, new Point))
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , _color(new EZ::Color)
{
}

ColorRect::ColorRect(const Rect& body, const EZ::Color& color)
    : ColorRect()
{
    this->_body->Set(body);

    this->_color->Set(color.R, color.G, color.B);
    this->_color->A = color.A;
}

ColorRect::ColorRect(const ColorRect& other)
    : _body(new Rect(*other._body))
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
    delete _body;
    _body = nullptr;

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
        window->DrawRectOutline(_body->_position->x, _body->_position->y, _body->_size->x, _body->_size->y, Thickness);
        break;
    case COLORRECT::FILL:
        window->DrawRect(_body->_position->x, _body->_position->y, _body->_size->x, _body->_size->y);
        break;
    }
}

// Body methods
const Point* const ColorRect::Position() const
{
    return _body->_position;
}
void ColorRect::Position(const Point& pos)
{
    Point diff = pos - *_body->_position;
    *_body->_position = pos;
}

const Point* const ColorRect::Size() const
{
    return _body->_size;
}
void ColorRect::Size(const Point& size)
{
    *_body->_size = size;
}

bool ColorRect::Collides(const ColorRect& other) const
{
    return _body->Collides(*other._body);
}
bool ColorRect::Collides(const Rect& other) const
{
    return _body->Collides(other);
}
