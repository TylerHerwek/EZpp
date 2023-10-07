#pragma once
#include "../Rect/Rect.hpp"
#include "../Window/Window.hpp"

namespace EZ {

class TextField;
enum class SPRITE { SCALE,
    FITBOX };

class Sprite : public CanvasItem {
public:
    Sprite();
    Sprite(const Point& pos, const char* imageURL);
    Sprite(const Sprite& other);
    ~Sprite();

    CanvasItem* Duplicate() const;

    void SetTexture(const char* imageURL);
    void Render() const;

    void SetMode(const SPRITE mode);
    void SetScale(const float x, const float y);

    void Position(const Point& pos);
    Point Position() const;

    void Size(const Point& size);
    Point Size() const;

    friend TextField;

private:
    SDL_Texture* _tex;
    const char* _url;

    SPRITE _mode;
    SDL_Rect* _dest;
};
}
