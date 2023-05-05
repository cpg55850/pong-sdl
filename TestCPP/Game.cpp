//
//  Game.cpp
//  TestCPP
//
//  Created by Charles Graham on 5/5/23.
//

#include <SDL2/SDL.h>
#include "Game.hpp"
#include <iostream>

Game::Game()
:mWindow(nullptr)
,mIsRunning(true){}

bool Game::Initialize(){
    // Initialize SDL
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
    
    mWindow = SDL_CreateWindow("Game Programming in C++ (Chapter 1)", 100, 100, 1024, 768, 0);
    
    if(!mWindow) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::Shutdown() {
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::RunLoop(){
    //Hack to get window to stay up
    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
//    while(mIsRunning){
//        ProcessInput();
//        UpdateGame();
//        GenerateOutput();
//    }
}

void Game::ProcessInput(){
    return;
}
void Game::UpdateGame(){
    return;
}
void Game::GenerateOutput(){
    return;
}
