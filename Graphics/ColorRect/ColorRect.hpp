#pragma once
#include "../Color/Color.hpp"
#include "../../Include/EZ++Func.hpp"

namespace EZ {
enum class COLORRECT { FILL, OUTLINE };

class ColorRect : public CanvasItem, public Rect {
public:
    ColorRect();
    ColorRect(const Rect& body, const EZ::Color& color);
    ColorRect(const ColorRect& other);

    ~ColorRect();
    unique_ptr<ColorRect> Duplicate() const;

    COLORRECT Mode;
    int Thickness;

    bool Collides(const ColorRect& other) const;
    bool Collides(const Rect& other) const;

    EZ::Color* const Color() const;
    void Render() const;

protected:
    EZ::Color* _color;
};
}
