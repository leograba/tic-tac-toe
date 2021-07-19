#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>
#include "CTexture.h"
//#include <SDL2/SDL_opengles2.h>

class CApp {
    private:
        bool Running;

        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *mytexture;

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event *Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

#endif