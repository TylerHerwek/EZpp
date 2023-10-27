#include "Main.hpp"
using namespace EZ;

Main::Main(EZ::Window* mainWindow)
    : mainWindow(mainWindow)
    , running(true)
	, BackGround({0, 0, 0, 255})
{
    FPS(20);
    CanvasItem::window = mainWindow;
}

Main::~Main()
{
    running = false;

    delete mainWindow;
    mainWindow = nullptr;
    CanvasItem::window = nullptr;

    SDL_Quit();
    print("Closed EZ::Main class.");
}

void Main::StartLoop()
{
    _loop();
}

float Main::FPS() const
{
    return _framerate * 1000;
}
void Main::FPS(const float fps)
{
    _framerate = 1000 / fps;
}

void Main::_loop()
{
    while (running) {
        _events();
        Update();
        _render();
        SDL_Delay(_framerate);
    }
}

void Main::_events()
{
    while (SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) running = false;
        Events();
    }
}

void Main::_render()
{
    mainWindow->Clear();
    Render();
    mainWindow->SetColor(BackGround);
    mainWindow->DrawRect({0, 0, 0, 0});
    mainWindow->Render();
}
