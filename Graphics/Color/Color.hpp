#pragma once
#include "../SDL/SDL.hpp"

namespace EZ {
enum class COLOR {
    WHITE,
    BLACK,
    RED,
    GREEN,
    BLUE
};

class Color {
public:
    Color();
    Color(const Color& col);
    Color(COLOR color, Uint8 a);
    Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    // Changes the r, g, b value
    void Set(COLOR color);
    void Set(Uint8 r, Uint8 g, Uint8 b);

    SDL_Color FormatToSDLStd() const;

    // Represents the Red value (0-255)
    Uint8 R;
    // Represents the Green value (0-255)
    Uint8 G;
    // Represents the Blue value (0-255)
    Uint8 B;
    // Represents the Alpha value that says how transparent a color is (0-255)
    Uint8 A;
};
}
