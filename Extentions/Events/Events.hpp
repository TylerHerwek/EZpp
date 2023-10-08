#pragma once
#include "../../src/Point/Point.hpp"
#include "../../src/SDL/SDL.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>

namespace EZ::Events {
class WASD {
public:
    WASD(const SDL_Event* event);

protected:
    // Put this into your pollEvent loop, or in your EZ::Main::Events method!
    void WASDEventCheck();
    //Put this somewhere somewhere where its called every frame
    void WASDUpdate();

    virtual void onW() { }
    virtual void onA() { }
    virtual void onS() { }
    virtual void onD() { }

private:
    const SDL_Event* _event;
    bool _w, _a, _s, _d;
};

enum class MOUSEBTN { LEFT = SDL_BUTTON_LEFT, RIGHT = SDL_BUTTON_RIGHT };

class MouseTracker {
public:
    MouseTracker(const SDL_Event* event);
    virtual ~MouseTracker();

protected:
    EZ::Point* const mouse;


    virtual void onClick(const MOUSEBTN btn) {}

    //Put this somewhere where it gets updated every frame
    void MouseTrackerUpdate();
    //Put this in your Events() method
    void MouseTrackerCheckForClick();

private:
    const SDL_Event* _event;
};
}
