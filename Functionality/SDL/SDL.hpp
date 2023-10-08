#pragma once
#include "SDL2/SDL.h"  // main Graphics API
#include "SDL2/SDL_image.h" // SDL Image helps rendering images
#include "SDL2/SDL_ttf.h" // SDL Font libary renders fonts

#include "vector"
#include "string"
#include "memory"
#include <vector>

using std::string, std::vector, std::unique_ptr, std::shared_ptr;

#include "iostream"
#define perror(x) std::cerr << x << std::endl;

#define DEBUG true

#if (DEBUG)
#define print(x) std::cout << x << '\n'
#else
#define print(x)
#endif


namespace EZ
{
  enum class KEY {
    a = SDLK_a,
    b = SDLK_b,
    c = SDLK_c,
    d = SDLK_d,
    e = SDLK_e,
    f = SDLK_f,
    g = SDLK_g,
    h = SDLK_h,
    i = SDLK_i,
    j = SDLK_j,
    k = SDLK_k,
    l = SDLK_l,
    m = SDLK_m,
    n = SDLK_n,
    o = SDLK_o,
    p = SDLK_p,
    q = SDLK_q,
    r = SDLK_r,
    s = SDLK_s,
    t = SDLK_t,
    u = SDLK_u,
    v = SDLK_v,
    w = SDLK_w,
    x = SDLK_x,
    y = SDLK_y,
    z = SDLK_z,

    num_0 = SDLK_0,
    num_1 = SDLK_1,
    num_2 = SDLK_2,
    num_3 = SDLK_3,
    num_4 = SDLK_4,
    num_5 = SDLK_5,
    num_6 = SDLK_6,
    num_7 = SDLK_7,
    num_8 = SDLK_8,
    num_9 = SDLK_9,

    LSHIFT = SDLK_LSHIFT,
    RSHIFT = SDLK_RSHIFT,
    SPACE = SDLK_SPACE,
    TAB = SDLK_TAB,
    LCTRL = SDLK_LCTRL,
    RCTRL = SDLK_RCTRL,
    LALT = SDLK_LALT,
    RALT = SDLK_RALT,

    ESC = SDLK_ESCAPE,
    UP = SDLK_UP,
    DOWN = SDLK_DOWN,
    LEFT = SDLK_LEFT,
    RIGHT = SDLK_RIGHT
  };
}
