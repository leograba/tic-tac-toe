#include "CApp.h"

CApp::CApp() {

    // Initialize global variables
    // Game state
    app.Running = true;
    app.State = STATE_MENU;

    // Global SDL objects
    app.window = NULL;
    app.renderer = NULL;

    // Game constants
    app.width = 800;
    app.height = 480;
    app.grid_size = app.height;
    app.mark_size = app.height / 3;

    app.menubtn_vsplayer.w = 0.35 * app.width;
    app.menubtn_vsplayer.h = app.menubtn_vsplayer.w / app.MENUBTN_RATIO;
    app.menubtn_vsplayer.x = 0.1 * app.width;
    app.menubtn_vsplayer.y = (app.height - app.menubtn_vsplayer.h) / 2;

    app.menubtn_vscomputer.w = app.menubtn_vsplayer.w;
    app.menubtn_vscomputer.h = app.menubtn_vsplayer.h;
    app.menubtn_vscomputer.x = 0.55 * app.width;
    app.menubtn_vscomputer.y = app.menubtn_vsplayer.y;

    // Initialize textures
    menu_button = NULL;
    grid = NULL;
    mark_x = NULL;
    mark_o = NULL;
    text_header = NULL;
    text_player_x = NULL;
    text_player_o = NULL;

    // Initialize font
    font = NULL;

    // Initialize game state
    CurrentPlayer = 0;
    VersusAI = 1;
    AITurn = 0;
    Winner = -1;
}

int CApp::OnExecute() {
    if (OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while (app.Running)
    {
        while (SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();

        SDL_Delay(15);
    }

    OnCleanup();

    return 0;
}

void CApp::Reset(int init)
{
    for (int i = 0; i < 9; i++)
    {
        GridStatus[i] = GRID_TYPE_NONE;
    }
    if (init == GAME_RESTART)
        SDL_Delay(5000);
    CurrentPlayer = 0;
    AITurn = 0;
    Winner = -1;
    app.State = STATE_DEFAULT;
}

void CApp::SetCell(int ID, int Type)
{
    if (ID < 0 || ID >= 9)
        return;
    if (Type < 0 || Type > GRID_TYPE_O)
        return;

    GridStatus[ID] = Type;
}

void CApp::ComputeScore(int winner)
{
    if (winner == GRID_TYPE_NONE)
        score.score_tie++;
    else if (winner == GRID_TYPE_X)
        score.score_x++;
    else if (winner == GRID_TYPE_O)
        score.score_o++;
    Winner = winner;
    app.State = STATE_WIN;
}

void CApp::CheckWinner()
{
    //8 ways to win
    if (GridStatus[0] != GRID_TYPE_NONE && GridStatus[0] == GridStatus[1] && GridStatus[1] == GridStatus[2])
    {
        ComputeScore(GridStatus[0]);
    }
    else if ((GridStatus[3] != GRID_TYPE_NONE && GridStatus[3] == GridStatus[4] && GridStatus[4] == GridStatus[5]))
    {
        ComputeScore(GridStatus[3]);
    }
    else if ((GridStatus[6] != GRID_TYPE_NONE && GridStatus[6] == GridStatus[7] && GridStatus[7] == GridStatus[8]))
    {
        ComputeScore(GridStatus[6]);
    }
    else if ((GridStatus[0] != GRID_TYPE_NONE && GridStatus[0] == GridStatus[3] && GridStatus[3] == GridStatus[6]))
    {
        ComputeScore(GridStatus[0]);
    }
    else if ((GridStatus[1] != GRID_TYPE_NONE && GridStatus[1] == GridStatus[4] && GridStatus[4] == GridStatus[7]))
    {
        ComputeScore(GridStatus[1]);
    }
    else if ((GridStatus[2] != GRID_TYPE_NONE && GridStatus[2] == GridStatus[5] && GridStatus[5] == GridStatus[8]))
    {
        ComputeScore(GridStatus[2]);
    }
    else if ((GridStatus[0] != GRID_TYPE_NONE && GridStatus[0] == GridStatus[4] && GridStatus[4] == GridStatus[8]))
    {
        ComputeScore(GridStatus[0]);
    }
    else if ((GridStatus[2] != GRID_TYPE_NONE && GridStatus[2] == GridStatus[4] && GridStatus[4] == GridStatus[6]))
    {
        ComputeScore(GridStatus[2]);
    }
    else if (GridStatus[0] != GRID_TYPE_NONE &&
            GridStatus[1] != GRID_TYPE_NONE &&
            GridStatus[2] != GRID_TYPE_NONE &&
            GridStatus[3] != GRID_TYPE_NONE &&
            GridStatus[4] != GRID_TYPE_NONE &&
            GridStatus[5] != GRID_TYPE_NONE &&
            GridStatus[6] != GRID_TYPE_NONE &&
            GridStatus[7] != GRID_TYPE_NONE &&
            GridStatus[8] != GRID_TYPE_NONE)
    {
        ComputeScore(GRID_TYPE_NONE);
    }
    return;
}

int main(int argc, char *argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}