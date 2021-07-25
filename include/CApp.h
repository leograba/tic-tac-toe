#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>
#include "CTexture.h"
#include "CEvent.h"
//#include <SDL2/SDL_opengles2.h>

class CApp : public CEvent {
    private:
        bool Running;

        SDL_Window *window;
        SDL_Renderer *renderer;

        // grid, X and O for tic-tac-toe
        SDL_Texture *grid;
        SDL_Texture *mark_x;
        SDL_Texture *mark_o;

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event *Event);

        void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

#endif