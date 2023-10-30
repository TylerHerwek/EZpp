#include "Color.hpp"

using namespace EZ;

Color::Color()
{
    R = 0;
    G = 0;
    B = 0;
    A = 255;
}

Color::Color(const Color& other)
{
    Set(other.R, other.G, other.B);
    A = other.A;
}

Color::Color(COLOR color, Uint8 a)
{
    Set(color);
    A = a;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    Set(r, g, b);
    A = a;
}

SDL_Color Color::FormatToSDLStd() const
{
    SDL_Color col;
    col.r = R;
    col.g = G;
    col.b = B;
    col.a = A;
    return col;
}

void Color::Set(COLOR color)
{
    switch (color) {
    case EZ::COLOR::WHITE:
        Set(255, 255, 255);
        break;
    case EZ::COLOR::BLACK:
        Set(0, 0, 0);
        break;
    case EZ::COLOR::RED:
        Set(255, 0, 0);
        break;
    case EZ::COLOR::GREEN:
        Set(0, 255, 0);
        break;
    case EZ::COLOR::BLUE:
        Set(0, 0, 255);
        break;
    default:
        Set(255, 255, 255);
        break;
    }
}

void Color::Set(Uint8 r, Uint8 g, Uint8 b)
{
    R = r;
    G = g;
    B = b;
}
