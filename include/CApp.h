#ifndef _CAPP_H_
    #define _CAPP_H_

#include <SDL2/SDL.h>
#include <chrono>
#include "CTexture.h"
#include "CText.h"
#include "CEvent.h"

class CApp : public CEvent {
    private:

        // global variables
        struct App
        {
            // game state
            bool Running;
            int State;

            // global SDL objects
            SDL_Window *window;
            SDL_Renderer *renderer;

            // game constants
            int width;
            int height;

            int grid_size;
            int mark_size;

            const double MENUBTN_RATIO = 487.0 / 200.0; //original size;
            SDL_Rect menubtn_vsplayer;
            SDL_Rect menubtn_vscomputer;
            const double BACKBTN_RATIO = 176.0 / 103.0; //original size;
            const double BACKBTN_PADDING = 15.0;
            SDL_Rect menubtn_back;
        };
        App app;

        // game textures
        SDL_Texture *menu_button;
        SDL_Texture *back_button;
        SDL_Texture *grid;
        SDL_Texture *mark_x;
        SDL_Texture *mark_o;

        // font
        TTF_Font *font;

        // game state
        int GridStatus[9];
        int CurrentPlayer;
        int VersusAI;
        int AITurn;
        int Winner;
        struct Score
        {
            int score_x;
            int score_o;
            int score_tie;
        };
        Score score = {0, 0, 0};
        std::chrono::time_point<std::chrono::steady_clock> last_action;

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
        enum
        {
            STATE_DEFAULT = 0,
            STATE_WIN,
            STATE_MENU
        };

    public:
        CApp();

        int OnExecute();

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

        void Reset();

        void SetCell(int ID, int Type);
};

#endif