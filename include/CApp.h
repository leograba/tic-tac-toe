#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>
#include "CTexture.h"
#include "CText.h"
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
        SDL_Texture *text_header;
        SDL_Texture *text_player_x;
        SDL_Texture *text_player_o;

        // font
        TTF_Font *font;

    private:
        int GridStatus[9];
        int CurrentPlayer;
        int Winner;
        struct Score
        {
            int score_x;
            int score_o;
            int score_tie;
        };
        Score score = {0, 0, 0};

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

        void ComputeScore(int winner);

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