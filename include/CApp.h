#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>

class CApp {
    private:
        bool Running;

        SDL_Window *window;
        SDL_Renderer *renderer;

    public:
        CApp();

        int OnExecute();

        bool OnInit();

        void OnEvent(SDL_Event *Event);

        void OnLoop();

        void OnRender();

        void OnCleanup();
};

#endif