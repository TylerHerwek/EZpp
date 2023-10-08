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

    void SetFont(const string& path, int size);

    void Pos(const Point pos);
    Point Pos() const;

    void Text(const string& text);
    const string* const Text() const;

    void Color(const EZ::Color& other);
    const EZ::Color* const Color() const;

    void SetBackGround(bool on);

    void Render() const;

private:
    EZ::Color* _color;
    string* _text;
    ColorRect* _background;

    SDL_Texture* _texture;
    SDL_Rect* _dest;

    TTF_Font* _font;
    string* _fontPath;
    int _fontSize;
};
}
