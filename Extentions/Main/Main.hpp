#pragma once
#include "../../Include/EZ++Func.hpp"

namespace EZ {
class Main {
public:
    Main(EZ::Window* mainWindow);
    virtual ~Main();

    void StartLoop();
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Events() = 0;
    virtual void OnClick() { }

    float FPS() const;
    void FPS(const float fps);

protected:
    EZ::Window* mainWindow;

    SDL_Event event;
    bool running;

private:
    float _framerate;

    void _loop();
    void _update();
    void _events();
    void _render();
};
}
