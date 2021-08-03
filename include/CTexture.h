#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

class CTexture
{
public:
    CTexture();

    static SDL_Texture *OnLoad(SDL_Renderer *renderer, std::string Filename);

    static bool OnDraw(SDL_Renderer *renderer, SDL_Texture *texture);

    static bool OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y);

    static bool OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h);

    static bool OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int x2, int y2, int w, int h);
};

#endif