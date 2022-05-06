#include "CApp.h"
#include <iostream>

bool CApp::OnInit() {
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;
    windowFlags = SDL_WINDOW_OPENGL |
                  SDL_WINDOW_RESIZABLE |
                  SDL_WINDOW_FULLSCREEN_DESKTOP;

    //initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "Couldn't initialize SDL: " << SDL_GetError() << "\n";
        return false;
    }

    // Missing init for SDL_image, though it does not produce errors

    //initialize SDL_ttf
    if (TTF_Init() < 0)
    {
        std::cerr << "Couldn't initialize SDL_ttf: " << TTF_GetError() << "\n";
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

    // Get Window size
    SDL_GetWindowSize(app.window, &app.width, &app.height);

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

    //load the game font
    if ((font = CText::OnLoad("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 24)) == NULL)
    {
        std::cerr << "Failed to load font: " << TTF_GetError() << "\n";
        exit(1);
    }

    //load the game textures
    if ((menu_button = CTexture::OnLoad(app.renderer, "assets/img/menu-button.png")) == NULL)
    {
        return false;
    }

    if ((back_button = CTexture::OnLoad(app.renderer, "assets/img/back-button.png")) == NULL)
    {
        return false;
    }

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
    SDL_SetRenderDrawColor(app.renderer, 0x70, 0x97, 0xB3, SDL_ALPHA_OPAQUE);

    //Clear the screen to the set colour
    SDL_RenderClear(app.renderer);

    //Show all the has been done behind the scenes
    SDL_RenderPresent(app.renderer);

    return true;
}