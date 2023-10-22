#include "TextField.hpp"
using namespace EZ;

TextField::TextField()
    : _dest(new SDL_Rect)
    , _text(new string("undefined"))
    , _fontPath(new string("uninit"))
    , _font(nullptr)
    , _texture(nullptr)
    , _fontSize(0)
    , _background(nullptr)
    , _color(new ::Color)
{
}

TextField::TextField(const TextField& other)
    : _dest(new SDL_Rect)
    , _text(nullptr)
    , _font(nullptr)
    , _texture(nullptr)
    , _background(new ColorRect(*other._background))
    , _color(new ::Color(*other._color))
{
    _dest->x = other._dest->x;
    _dest->y = other._dest->y;
    SetFont(*other._fontPath, other._fontSize);
    Text(*other._text);
}

TextField::~TextField()
{
    delete _dest;
    delete _text;
    delete _fontPath;
    delete _color;

    TTF_CloseFont(_font);
    SDL_DestroyTexture(_texture);
}

unique_ptr<TextField> TextField::Duplicate() const
{
    return std::make_unique<TextField>(*this);
}

void TextField::SetFont(const string& path, int size)
{
    // Load font
    TTF_CloseFont(_font);
    _font = TTF_OpenFont(path.c_str(), size);

    if (!_font) {
        _font = nullptr;
        print("could not load font: " << path);
        return;
    }

    *_fontPath = path;
    _fontSize = size;
    // Make Sprite
    SDL_Surface* surf = TTF_RenderText_Solid(_font, _text->c_str(), _color->FormatToSDLStd());
    _dest->w = surf->w;
    _dest->h = surf->h;

    SDL_DestroyTexture(_texture);
    _texture = SDL_CreateTextureFromSurface(window->renderer, surf);
    SDL_FreeSurface(surf);

    if (_background != nullptr)
        _background = new ColorRect(
            { _dest->x - 4, _dest->y - 4, _dest->w + 8, _dest->h + 8 },
            { 200, 200, 200, 50 });
}

// Text getters and setters
void TextField::Text(const string& text)
{
    if (!_font) {
        print("You did not initializa a font!");
        print("Try TextField::SetFont");
        return;
    }
    *this->_text = text;

    // Make Sprite
    SDL_Surface* surf = TTF_RenderText_Solid(_font, _text->c_str(), _color->FormatToSDLStd());
    if (!surf) {
     print("failed to create Surface in ::TextField::Text(set): " << SDL_GetError());
        *_text = "failed";
        return;
    }

    _dest->w = surf->w;
    _dest->h = surf->h;

    SDL_DestroyTexture(_texture);
    _texture = SDL_CreateTextureFromSurface(window->renderer, surf);
    if (!_texture) {
        print("failed to create texture in ::TextField::Text(set): " << SDL_GetError());
        _texture = nullptr;
        return;
    }

    if (_background != nullptr)
        _background = new ColorRect(
            { _dest->x - 4, _dest->y - 4, _dest->w + 8, _dest->h + 8 },
            { 200, 200, 200, 50 });

    SDL_FreeSurface(surf);
}

const char* TextField::Text() const
{
    return _text->c_str();
}

void TextField::Color(const EZ::Color& other)
{
    _color->Set(other.R, other.G, other.B);
    _color->A = other.A;
    Text(*_text);
}

const ::Color* const TextField::Color() const
{
    return _color;
}

// Position getters and setters
void TextField::Pos(const Point pos)
{
    _dest->x = pos.X;
    _dest->y = pos.Y;

    if (!_background)
        return;
    _background->Pos = Point(_dest->x - 4, _dest->y - 4);
}

Point TextField::Pos() const
{
    return { _dest->x, _dest->y };
}

void TextField::SetBackGround(bool on)
{
    delete _background;
    _background = nullptr;

    if (on)
        _background = new ColorRect(
            { _dest->x - 4, _dest->y - 4, _dest->w + 8, _dest->h + 8 },
            { 200, 200, 200, 50 });
}

// Render methods
void TextField::Render() const
{
    if (_background != nullptr)
        _background->Render();

    if (!_texture) {
        print("You did not initialize the font!");
        print("Try TextField::SetFont");
        return;
    }

    SDL_RenderCopy(window->renderer, _texture, NULL, _dest);
}

int TextField::FontSize() const { return _fontSize; }
