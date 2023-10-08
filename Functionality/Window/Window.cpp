#include "Window.hpp"
using namespace EZ;

Window::Window(const char* name, int x, int y, int w, int h)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        perror("Could not initalze SDL: " << SDL_GetError());
        return;
    }

    window = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        perror("Could not initalze Window: " << SDL_GetError());
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        perror("Could not initalze Renderer: " << SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    if (TTF_Init() == -1) {
        perror("Error Initializing TTF: " << TTF_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    SetColor(255, 255, 255, 255);
}

void Window::SetColor(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Window::DrawRect(int x, int y, int w, int h)
{
    const SDL_Rect rect = { x, y, w, h };
    SDL_RenderFillRect(renderer, &rect);
}

void Window::DrawRectOutline(int x, int y, int w, int h, int t)
{
    for (int i = 0; i < t; i++) {
        const SDL_Rect rct = { x + i, y + i, w - (2 * i), h - (2 * i) };
        SDL_RenderDrawRect(renderer, &rct);
    }
}

void Window::DrawLine(const Point& a, const Point& b, const int thick)
{
    for (int i = 0; i < thick; i++) {
        SDL_RenderDrawLine(renderer, a.x, a.y + i, b.x, b.y + i);
    }
}

void Window::Clear()
{
    SDL_RenderClear(renderer);
}

void Window::Render()
{
    SDL_RenderPresent(renderer);
}

EZ::Window* EZ::CanvasItem::window = nullptr;
