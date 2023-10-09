#include "Window.hpp"
#include <SDL2/SDL_rect.h>
using namespace EZ;

Window::Window(const char* name, const Rect& bd)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        perror("Could not initalze SDL: " << SDL_GetError());
        return;
    }

    window = SDL_CreateWindow(name, bd.X, bd.Y, bd.W, bd.H, SDL_WINDOW_SHOWN);
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

void Window::DrawRect(const Rect& r)
{
    SDL_RenderFillRect(renderer, r.ToSDLStd());
}

void Window::DrawRectOutline(const Rect& r, int t)
{
    for (int i = 0; i < t; i++) {
        const SDL_Rect rct = {
            r.X + i,
            r.Y + i,
            r.W - (2 * i),
            r.H - (2 * i)
        };
        SDL_RenderDrawRect(renderer, &rct);
    }
}

void Window::DrawLine(const Point a, const Point b, const int thick)
{
    for (int i = 0; i < thick; i++) {
        SDL_RenderDrawLine(renderer, a.X, a.Y + i, b.X, b.Y + i);
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
