#include "Button.hpp"
using namespace EZ;

Button::Button(Point* mouse)
    : _mouse(mouse)
    , _body(new Rect)
    , _background(nullptr)
    , _hover(true)
    , _hoverTex(nullptr)
    , _normalTex(nullptr)
{
    SetBackground(true);
}

Button::Button(Point* mouse, const Rect& b)
    : Button(mouse)
{
    Pos(b.Pos);
    Size(b.Size);
}

Button::~Button()
{
    delete _body;
    _body = nullptr;

    delete _normalTex;
    _normalTex = nullptr;

    delete _hoverTex;
    _hoverTex = nullptr;

    delete _background;
    _background = nullptr;
}

void Button::SetHover(const char* URL)
{
    delete _hoverTex;

    _hoverTex = new Sprite(_body->Pos, URL);
    _hoverTex->SetMode(SPRITE::FITBOX);
    _hoverTex->Size(_body->Size);
}

void Button::SetNormal(const char* URL)
{
    delete _normalTex;

    _normalTex = new Sprite(_body->Pos, URL);
    _normalTex->SetMode(SPRITE::FITBOX);
    _normalTex->Size(_body->Size);
}

void Button::SetBackground(const bool on)
{
    delete _background;
    _background = nullptr;

    if (on)
        _background = new ColorRect(*_body, { 100, 100, 100, 100 });
}

void Button::Pos(const Point pos)
{
    _body->Pos = pos;
    if (_background)
        _background->Pos = pos;

    if (_normalTex)
        _normalTex->Pos(pos);
    if (_hoverTex)
        _hoverTex->Pos(pos);
}

Point Button::Pos() const
{
    return _body->Pos;
}

void Button::Size(const Point size)
{
    _body->Size = size;
    if (_background)
        _background->Size = size;

    if (_normalTex)
        _normalTex->Size(size);
    if (_hoverTex)
        _hoverTex->Size(size);
}

Point Button::Size() const
{
    return _body->Size;
}

void Button::Update()
{
    if (!_hover && _body->Collides(*_mouse)) {
        _hover = true;
        if (_background)
            _background->Color.Set(200, 200, 200);
    } else if (_hover && !_body->Collides(*_mouse)) {
        _hover = false;
        if (_background)
            _background->Color.Set(100, 100, 100);
    }
}

void Button::Render() const
{
    if (_background)
        _background->Render();

    if (_hover) {
        if (!_hoverTex) {
            print("The hover texture is unintitialized!");
            print("Initialize it using Button::SetHover");
        } else {
            _hoverTex->Render();
        }
    } else {
        if (!_normalTex) {
            print("The normal texture is unintitialized!");
            print("Initialize it using Button::SetNormal");
        } else {
            _normalTex->Render();
        }
    }
}

bool Button::Hover() const
{
    return _hover;
}
