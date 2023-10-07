#include "Events.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>

using namespace EZ::Events;

WASD::WASD(const SDL_Event* event)
    : _event(event)
    , _w(false)
    , _a(false)
    , _s(false)
    , _d(false)
{
}

void WASD::WASDEventCheck()
{
    switch (_event->type) {
    case SDL_KEYDOWN:
        switch (_event->key.keysym.sym) {
        case SDLK_w:
            _w = true;
            break;
        case SDLK_a:
            _a = true;
            break;
        case SDLK_s:
            _s = true;
            break;
        case SDLK_d:
            _d = true;
            break;
        }
        break;

    case SDL_KEYUP:
        switch (_event->key.keysym.sym) {
        case SDLK_w:
            _w = false;
            break;
        case SDLK_a:
            _a = false;
            break;
        case SDLK_s:
            _s = false;
            break;
        case SDLK_d:
            _d = false;
            break;
        }
        break;
    }
}

void WASD::WASDUpdate()
{
    if (_w)
        onW();
    if (_a)
        onA();
    if (_s)
        onS();
    if (_d)
        onD();
}

MouseTracker::MouseTracker(const SDL_Event* event)
    : mouse(new Point)
    , _event(event)
{
}

MouseTracker::~MouseTracker() { delete mouse; }

void MouseTracker::MouseTrackerUpdate() { SDL_GetMouseState(&mouse->x, &mouse->y); }

void MouseTracker::MouseTrackerCheckForClick()
{
    if (_event->type != SDL_MOUSEBUTTONDOWN)
        return;
    onClick((EZ::Events::MOUSEBTN)_event->button.button);
}
