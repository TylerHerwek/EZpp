#include "ColorRect.hpp"
using namespace EZ;

// LIFETIME
ColorRect::ColorRect()
    : Rect()
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , Color({})
	, Visible(true)
{
}

ColorRect::ColorRect(const Rect& body, const EZ::Color color)
    : Rect(body)
    , Thickness(1)
    , Mode(COLORRECT::FILL)
    , Color(color)
	, Visible(true)
{
}

void ColorRect::Render() const
{
	if(!Visible) return;
    if (!window) {
        perror("The renderer Window is not initialized!");
        perror("Set the static CanvasItem::window field to a Window pointer to fix this issue.");
        return;
    }

    window->SetColor(Color);

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
