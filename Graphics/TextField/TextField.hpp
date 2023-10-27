#pragma once
#include "../ColorRect/ColorRect.hpp"
#include "../Sprite/Sprite.hpp"
#include "../../Include/EZ++Func.hpp"

namespace EZ {
class TextField : public CanvasItem {
public:
    TextField();
    TextField(const TextField& other);
    ~TextField();

    unique_ptr<TextField> Duplicate() const;

    void SetFont(const string& path, const Uint16 size);

    void Pos(const Point pos);
    Point Pos() const;

    void Text(const string& text);
    const char* Text() const;

    void Color(const EZ::Color& other);
    const EZ::Color* const Color() const;

    void SetBackGround(const bool on);

    void Render() const;
	int FontSize() const;

	const Rect* const Destination() const;

private:
    EZ::Color* _color;
    string* _text;
    ColorRect* _background;

    SDL_Texture* _texture;
    SDL_Rect* _dest;

    TTF_Font* _font;
    string* _fontPath;
    Uint16 _fontSize;
};
}
