#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>
#include "CTexture.h"
#include "CEvent.h"

class CApp : public CEvent {
    private:

        // global variables
        struct App
        {
            // game running
            bool Running;

            // global SDL objects
            SDL_Window *window;
            SDL_Renderer *renderer;

            // game constants
            int width;
            int height;

            int grid_size;
            int mark_size;
        };
        App app = {true, NULL, NULL, 800, 480, 480, 480/3};

        // game textures
        SDL_Texture *grid;
        SDL_Texture *mark_x;
        SDL_Texture *mark_o;

    private:
        int GridStatus[9];
        int CurrentPlayer;
        int Winner;
        enum
        {
            GRID_TYPE_NONE = 0,
            GRID_TYPE_X,
            GRID_TYPE_O
        };
        enum
        {
            GAME_START = 0,
            GAME_RESTART
        };

    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

        void OnEvent(SDL_Event *Event);

        void CheckWinner();

        void OnLButtonDown(int mX, int mY);

        void OnResize(int width, int height);

        void OnExit();

        void OnLoop();

        void OnRender();

        void OnCleanup();

        void Reset(int init);

        void SetCell(int ID, int Type);
};

#endif