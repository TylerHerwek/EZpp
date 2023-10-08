#pragma once
#include "../Rect/Rect.hpp"
#include "../SDL/SDL.hpp"

namespace EZ {
class Sprite;
class TextField;

class Window final {
public:
    Window(const char* name, const Rect& body);
    Window(const Window& other) = delete;

    void SetColor(int r, int g, int b, int a);

    void DrawRect(const Rect& rect);
    void DrawRectOutline(const Rect& rect, int t);
    void DrawLine(const Point a, const Point b, const int thick);

    void Clear();
    void Render();

    friend Sprite;
    friend TextField;

private:
    SDL_Renderer* renderer;
    SDL_Window* window;
};

class CanvasItem {
public:
    static EZ::Window* window;
};
}
