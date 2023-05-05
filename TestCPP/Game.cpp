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
,mRenderer(nullptr)
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
    
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (!mRenderer)
    {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::Shutdown() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::RunLoop(){
    //Hack to get window to stay up
//    SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    while(mIsRunning){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type) {
            case SDL_QUIT:
                mIsRunning = false;
                break;
        }
    }
    
    // Get state of keyboard
    const Uint8* state = SDL_GetKeyboardState(NULL);
    // If escape is pressed, also end loop
    if (state[SDL_SCANCODE_ESCAPE]){
        mIsRunning = false;
    }
}
void Game::UpdateGame(){
    return;
}
void Game::GenerateOutput(){
    // Set draw color to blue
    SDL_SetRenderDrawColor(
        mRenderer,
        0,        // R
        0,        // G
        255,    // B
        255        // A
    );

    // Clear back buffer
    SDL_RenderClear(mRenderer);
    
    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}
