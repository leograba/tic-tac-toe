#include "CApp.h"
#include "CTexture.h"

#include <iostream>

CTexture::CTexture()
{
}

SDL_Texture *CTexture::OnLoad(SDL_Renderer *renderer, std::string Filename)
{
    SDL_Texture *texture = NULL;

    if ((texture = IMG_LoadTexture(renderer, Filename.c_str())) == NULL)
    {
        std::cerr << "Failed to load texture: " << IMG_GetError() << "\n";
        return NULL;
    }

    return texture;
}

bool CTexture::OnDraw(SDL_Renderer *renderer, SDL_Texture *texture)
{
    if (renderer == NULL || texture == NULL)
    {
        return false;
    }

    SDL_RenderCopy(renderer, texture, NULL, NULL);

    return true;
}

bool CTexture::OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y)
{
    if (renderer == NULL || texture == NULL)
    {
        return false;
    }

    SDL_Rect DestR;
    DestR.x = x;
    DestR.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &DestR.w, &DestR.h);

    SDL_RenderCopy(renderer, texture, NULL, &DestR);

    return true;
}

bool CTexture::OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int w, int h)
{
    if (renderer == NULL || texture == NULL)
    {
        return false;
    }

    SDL_Rect DestR = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &DestR);

    return true;
}

bool CTexture::OnDraw(SDL_Renderer *renderer, SDL_Texture *texture, int x, int y, int x2, int y2, int w, int h)
{
    if (renderer == NULL || texture == NULL)
    {
        return false;
    }

    SDL_Rect DestR = {x, y, w, h};
    SDL_Rect SrcR = {x2, y2, w, h};

    SrcR.x = x2;
    SrcR.y = y2;
    SrcR.w = w;
    SrcR.h = h;

    SDL_RenderCopy(renderer, texture, &SrcR, &DestR);

    return true;
}