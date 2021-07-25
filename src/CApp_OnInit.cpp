#include "CApp.h"
#include <iostream>

bool CApp::OnInit() {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = SDL_WINDOW_OPENGL |
                  SDL_WINDOW_RESIZABLE;

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
    app.window = SDL_CreateWindow("tic-tac-toe", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, app.width,
                              app.height, windowFlags);

    if (!app.window)
    {
        std::cerr << "Failed to open window: " << SDL_GetError() << "\n";
        exit(1);
    }

    //Suggest OpenGL ES 2
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengles2");

    //create renderer
    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

    if (!app.renderer)
    {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << "\n";
        exit(1);
    }

    //load the game textures, grid, X and O
    if ((grid = CTexture::OnLoad(app.renderer, "assets/img/grid.png")) == NULL)
    {
        return false;
    }

    if ((mark_x = CTexture::OnLoad(app.renderer, "assets/img/x.png")) == NULL)
    {
        return false;
    }

    if ((mark_o = CTexture::OnLoad(app.renderer, "assets/img/o.png")) == NULL)
    {
        return false;
    }

    //Render something
    SDL_RenderSetLogicalSize(app.renderer, app.width, app.height);

    //Set colour of renderer
    //Grid Blue is #7097B3
    SDL_SetRenderDrawColor(app.renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);

    //Clear the screen to the set colour
    SDL_RenderClear(app.renderer);

    //Show all the has been done behind the scenes
    SDL_RenderPresent(app.renderer);

    Reset(GAME_START);

    return true;
}