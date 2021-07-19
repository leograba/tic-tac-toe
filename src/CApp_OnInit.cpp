#include "CApp.h"
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

bool CApp::OnInit() {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = SDL_WINDOW_OPENGL;

    //initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Couldn't initialize SDL: " << SDL_GetError() << "\n";
        return false;
    }

    std::cout << "SDL_GetCurrentVideoDriver: " << SDL_GetCurrentVideoDriver()
        << "\n";

    //OpenGL context to use OpenGL ES
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    //create window
    window = SDL_CreateWindow("CApp 01", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, windowFlags);

    if (!window)
    {
        std::cerr << "Failed to open window: " << SDL_GetError() << "\n";
        exit(1);
    }

    //Suggest OpenGL ES 2
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengles2");

    //create renderer
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);

    if (!renderer)
    {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << "\n";
        exit(1);
    }

    if ((mytexture = CTexture::OnLoad(renderer, "assets/img/tdx-eyes.png")) == NULL)
    {
        return false;
    }

    //Render something
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

    //Set colour of renderer
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    //Clear the screen to the set colour
    SDL_RenderClear(renderer);

    //Show all the has been done behind the scenes
    SDL_RenderPresent(renderer);

    return true;
}