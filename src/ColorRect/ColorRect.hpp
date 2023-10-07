#pragma once
#include "../Color/Color.hpp"
#include "../Rect/Rect.hpp"
#include "../Window/Window.hpp"

namespace EZ {
enum class COLORRECT { FILL, OUTLINE };

class ColorRect : public CanvasItem {
public:
    ColorRect();
    ColorRect(const Rect& body, const EZ::Color& color);
    ColorRect(const ColorRect& other);

    ~ColorRect();
    unique_ptr<ColorRect> Duplicate() const;

    COLORRECT Mode;
    int Thickness;

    const Point* const Position() const;
    void Position(const Point& pos);

    const Point* const Size() const;
    void Size(const Point& size);

    bool Collides(const ColorRect& other) const;
    bool Collides(const Rect& other) const;

    EZ::Color* const Color() const;
    void Render() const;

protected:
    Rect* _body;
    EZ::Color* _color;
};
}
