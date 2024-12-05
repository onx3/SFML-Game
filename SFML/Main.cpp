#include <iostream>
#include "Game.h"

int main()
{
    Game * pGame = new Game();
    auto * pWindow = pGame->mpWindow;
    auto & event = pGame->mEvent;

    while (pWindow->isOpen())
    {
        pGame->PollEvents();

        // Render the game
        pGame->Render();        
    }

    delete pGame;
    return 0;
}
