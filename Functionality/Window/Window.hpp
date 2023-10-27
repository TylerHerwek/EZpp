#pragma once
#include "../Rect/Rect.hpp"
#include "../Color/Color.hpp"

namespace EZ {
class Sprite;
class TextField;

void Initialize();
Point FullScreen();
	
class Window final {
public:
	Window(const char* name, const Rect& body);
	Window(const Window& other) = delete;
	~Window();

	void SetColor(const EZ::Color color);
	void DrawRect(const Rect& rect);
	
	void DrawRectOutline(const Rect& rect, int t);
	void DrawLine(const Point a, const Point b, const int thick);

	const Rect* const Body;

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
