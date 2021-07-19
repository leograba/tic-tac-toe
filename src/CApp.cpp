#include "CApp.h"

CApp::CApp() {
    Running = true;
    window = NULL;
    renderer = NULL;
    mytexture = NULL;
}

int CApp::OnExecute() {
    if (OnInit() == false)
    {
        return -1;
    }

    SDL_Event Event;

    while (Running)
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

int main(int argc, char *argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}