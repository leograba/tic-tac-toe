#ifndef _CTEXT_H_
#define _CTEXT_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <string>

class CText
{

public:
    CText();

    static TTF_Font *OnLoad(std::string Filename, int Pixels);

    static bool OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, TTF_Font *font, std::string Text, int x, int y);

    static bool OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, TTF_Font *font, std::string Text, int scr_width, int grid_size, int y);
};

#endif
