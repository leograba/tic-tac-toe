#include "CApp.h"
#include <iostream>

void CApp::OnEvent(SDL_Event *Event) {
    if (Event->type == SDL_QUIT)
    {
        std::cout << "Exiting..." << std::endl;
        Running = false;
    }
}