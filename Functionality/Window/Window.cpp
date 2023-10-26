#include "Window.hpp"
using namespace EZ;

Window::Window(const char* name, const Rect& bd)
	: Body(new Rect(bd))
{
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

    SetColor({255, 255, 255, 255});
}

Window::~Window() {
	delete Body;
}

void Window::SetColor(const EZ::Color col)
{
    SDL_SetRenderDrawColor(renderer, col.R, col.G, col.B, col.A);
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

Point EZ::FullScreen() {
	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
		perror("FullScreen operation failed: " << SDL_GetError());
		return {-1, -1};
	}
	return { dm.w, dm.h };
}

void EZ::Initialize() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        perror("Could not initalze SDL: " << SDL_GetError());
    }
}

EZ::Window* EZ::CanvasItem::window = nullptr;
