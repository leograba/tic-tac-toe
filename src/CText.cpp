#include "CApp.h"
#include "CText.h"

#include <iostream>

CText::CText()
{
}

TTF_Font *CText::OnLoad(std::string Filename, int Pixels)
{
    TTF_Font *font_load = NULL;

    if ((font_load = TTF_OpenFont(Filename.c_str(), Pixels)) == NULL)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << "\n";
        return NULL;
    }

    return font_load;
}

bool CText::OnDraw(SDL_Renderer *renderer, TTF_Font *font, std::string Text,
                   int x, int y)
{
    if (renderer == NULL)
    {
        return false;
    }

    // font is white and BG is a shade of blue
    SDL_Color font_color = {0xFF, 0xFF, 0xFF};
    SDL_Color bg_color = {0x70, 0x97, 0xB3};

    SDL_Surface *text;
    //text = TTF_RenderText_Solid(font, Text.c_str(), font_color);
    text = TTF_RenderText_Shaded(font, Text.c_str(), font_color, bg_color);

    if (!text)
    {
        std::cerr << "Failed to render text: " << TTF_GetError() << "\n";
    }

    SDL_Texture *texture;
    texture = SDL_CreateTextureFromSurface(renderer, text);

    SDL_Rect DestR = {x, y, text->w, text->h};

    SDL_RenderCopy(renderer, texture, NULL, &DestR);
    SDL_FreeSurface(text);
    SDL_DestroyTexture(texture);

    return true;
}

bool CText::OnDraw(SDL_Renderer *renderer, TTF_Font *font,
                   std::string Text, int scr_width, int grid_size, int y)
{
    if (renderer == NULL)
    {
        return false;
    }

    // font is white and BG is a shade of blue
    SDL_Color font_color = {0xFF, 0xFF, 0xFF};
    SDL_Color bg_color = {0x70, 0x97, 0xB3};

    SDL_Surface *text;
    //text = TTF_RenderText_Solid(font, Text.c_str(), font_color);
    text = TTF_RenderText_Shaded(font, Text.c_str(), font_color, bg_color);

    if (!text)
    {
        std::cerr << "Failed to render text: " << TTF_GetError() << "\n";
    }

    SDL_Texture *texture;
    texture = SDL_CreateTextureFromSurface(renderer, text);

    //center align
    int x = grid_size + (scr_width - grid_size - text->w) / 2;
    SDL_Rect DestR = {x, y, text->w, text->h};

    SDL_RenderCopy(renderer, texture, NULL, &DestR);
    SDL_FreeSurface(text);
    SDL_DestroyTexture(texture);

    return true;
}

bool CText::OnDraw(SDL_Renderer *renderer, TTF_Font *font,
                   std::string Text, SDL_Rect Dest)
{
    if (renderer == NULL)
    {
        return false;
    }

    // font is white and BG is a shade of blue
    SDL_Color font_color = {0xFF, 0xFF, 0xFF};
    SDL_Color bg_color = {0x70, 0x97, 0xB3};

    SDL_Surface *text;
    //text = TTF_RenderText_Solid(font, Text.c_str(), font_color);
    text = TTF_RenderText_Shaded(font, Text.c_str(), font_color, bg_color);

    if (!text)
    {
        std::cerr << "Failed to render text: " << TTF_GetError() << "\n";
    }

    SDL_Texture *texture;
    texture = SDL_CreateTextureFromSurface(renderer, text);

    //center align with given rectangle
    int x = Dest.x + (Dest.w - text->w) / 2;
    int y = Dest.y + (Dest.h - text->h) / 2;
    SDL_Rect DestR = {x, y, text->w, text->h};

    SDL_RenderCopy(renderer, texture, NULL, &DestR);
    SDL_FreeSurface(text);
    SDL_DestroyTexture(texture);

    return true;
}