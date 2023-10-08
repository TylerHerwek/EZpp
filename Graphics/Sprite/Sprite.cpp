#include "Sprite.hpp"
using namespace EZ;

Sprite::Sprite()
    : _tex(nullptr)
    , _url(nullptr)
    , _dest(new SDL_Rect)
{
    *_dest = { 0, 0, 0, 0 };
    SetMode(SPRITE::SCALE);
}

Sprite::Sprite(const Point pos, const char* imageURL)
    : Sprite()
{
    Pos(pos);
    SetTexture(imageURL);
}

Sprite::Sprite(const Sprite& other)
    : _tex(nullptr)
    , _url(other._url)
    , _dest(new SDL_Rect)
{
    *_dest = *other._dest;
    SetTexture(_url);
    SetMode(other._mode);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(_tex);
    _tex = nullptr;

    delete _dest;
    _dest = nullptr;
}

CanvasItem* Sprite::Duplicate() const
{
    return new Sprite(*this);
}

void Sprite::Render() const
{
    if (!_tex) {
        print("Cannot Render Sprite. Its not initialzed.");
        print("Try using Sprite::SetTexture");
        return;
    }

    SDL_RenderCopy(window->renderer, _tex, NULL, _dest);
}

void Sprite::SetTexture(const char* imgURL)
{
    if (_tex != nullptr)
        SDL_DestroyTexture(_tex);
    _tex = IMG_LoadTexture(window->renderer, imgURL);

    if (!_tex) {
        print("Could not load texture " << imgURL << " Error: " << SDL_GetError());
        _tex = nullptr;
        return;
    }

    SDL_Surface* surf = IMG_Load(imgURL);
    _dest->w = surf->w;
    _dest->h = surf->h;

    SDL_FreeSurface(surf);
    _url = imgURL;
}

void Sprite::SetScale(const float x, const float y)
{
    if (_mode == SPRITE::FITBOX) {
        perror("This object is in fitbox mode, you cannot use Sprite::SetScale to change its size!");
        perror("Try using the Sprite::Size(set) method, or use Sprite SetMode(SPRITE::SCALE) to make it scalable.");
        return;
    }

    _dest->w = (int)(_dest->w * x);
    _dest->h = (int)(_dest->h * y);
}

void Sprite::SetMode(const SPRITE mode)
{
    _mode = mode;

    switch (mode) {
    case EZ::SPRITE::SCALE:
        print("This object is now in Scale mode, use Sprite::SetScale to change it's size!");
        break;

    case EZ::SPRITE::FITBOX:
        print("This object is now in Fitbox mode, use Sprite::Size(set) to change it's size!");
        break;

    default:
        print("You somehow fat in a wrong value into Sprite::SetMode");
        break;
    }
}

void Sprite::Pos(const Point pos)
{
    _dest->x = pos.X;
    _dest->y = pos.Y;
}
Point Sprite::Pos() const
{
    return { _dest->x, _dest->y };
}

void Sprite::Size(const Point size)
{
    if (_mode == SPRITE::SCALE) {
        perror("This object is in scale mode, you cannot change its Size from the 'Sprite::Size' method!");
        perror("To change its Size try Sprite::SetScale");
        perror("Or set it to FITBOX mode with 'Sprite::SetMode(SPRITE::FITBOX)'");
        return;
    }
    _dest->w = size.X;
    _dest->h = size.Y;
}
Point Sprite::Size() const
{
    return { _dest->w, _dest->h };
}
