#pragma once
#include "../Point/Point.hpp"
#include "../SDL/SDL.hpp"

namespace EZ {
class Sprite;
class TextField;

class Window final {
public:
    Window(const char* name, int x, int y, int w, int h);
    Window(const Window& other) = delete;

    void SetColor(int r, int g, int b, int a);

    void DrawRect(int x, int y, int w, int h);
    void DrawRectOutline(int x, int y, int w, int h, int t);
    void DrawLine(const Point& a, const Point& b, const int thick);

    void Clear();
    void Render();

    friend Sprite;
    friend TextField;

private:
    SDL_Renderer* renderer;
    SDL_Window* window;
    int w, h;
};

class CanvasItem {
public:
    static EZ::Window* window;
};
}
