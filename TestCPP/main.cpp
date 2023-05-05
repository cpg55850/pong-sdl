/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//https://github.com/gameprogcpp/code

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Game.hpp"

int main( int argc, char* args[] )
{
    Game game;
    bool success = game.Initialize();
    if(success) {
        game.RunLoop();
    }
    game.Shutdown();

    return 0;
}
