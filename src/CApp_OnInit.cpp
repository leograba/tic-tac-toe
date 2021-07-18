#include "CApp.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

bool CApp::OnInit() {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("CApp 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!window)
    {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    renderer = SDL_CreateRenderer(window, -1, rendererFlags);

    if (!renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00,
                           SDL_ALPHA_OPAQUE);

    return true;
}