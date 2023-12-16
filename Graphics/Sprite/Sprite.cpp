#include "Sprite.hpp"
#include <cstdio>
#include <string>
using namespace EZ;

Sprite::Sprite()
	: _tex(nullptr)
	, _url("undefined")
	, _dest(new SDL_Rect)
	, Visible(true)
{
	*_dest = { 0, 0, 0, 0 };
	SetMode(SPRITE::SCALE);
}

Sprite::Sprite(const Point pos, const std::string& imageURL)
    : Sprite()
{
    Pos(pos);
    SetTexture(imageURL, false);
}

Sprite::Sprite(const Sprite& other)
    : _tex(nullptr)
    , _url(other._url)
    , _dest(new SDL_Rect)
	, Visible(other.Visible)
{
    SetMode(other._mode);
    SetTexture(_url);
    *_dest = *other._dest;
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
	if(!Visible) return;
    if (!_tex) {
        print("Cannot Render Sprite. Its not initialzed.");
        print("Try using Sprite::SetTexture");
        return;
    }

    SDL_RenderCopy(window->renderer, _tex, NULL, _dest);
}

void Sprite::SetTexture(const std::string& imgURL, const bool keepSize)
{
    if (_tex != nullptr)
        SDL_DestroyTexture(_tex);
    _tex = IMG_LoadTexture(window->renderer, imgURL.c_str());

    if (!_tex) {
        perror("Could not load texture " << imgURL << " Error: " << SDL_GetError());
        _tex = nullptr;
        return;
    }

    SDL_Surface* surf = IMG_Load(imgURL.c_str());
	if(!keepSize) {
		_dest->w = surf->w;
		_dest->h = surf->h;
	}
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
