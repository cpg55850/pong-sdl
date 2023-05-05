//
//  Game.cpp
//  TestCPP
//
//  Created by Charles Graham on 5/5/23.
//

#include <SDL2/SDL.h>
#include "Game.hpp"
#include <iostream>

const int thickness = 15;
const float paddleH = 100.0f;

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
    
    mPaddlePos.x = 10.0f;
    mPaddlePos.y = 768.0f/2.0f;
    mBallPos.x = 1024.0f/2.0f;
    mBallPos.y = 768.0f/2.0f;

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
        53,        // R
        149,        // G
        188,        // B
        255        // A
    );

    // Clear back buffer
    SDL_RenderClear(mRenderer);
    
    // Draw walls
    SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
    
    // Draw top wall
    SDL_Rect wall{
        0,            // Top left x
        0,            // Top left y
        1024,        // Width
        thickness    // Height
    };
    SDL_RenderFillRect(mRenderer, &wall);
    
    // Draw bottom wall
    wall.y = 768 - thickness;
    SDL_RenderFillRect(mRenderer, &wall);
    
    // Draw right wall
    wall.x = 1024 - thickness;
    wall.y = 0;
    wall.w = thickness;
    wall.h = 1024;
    SDL_RenderFillRect(mRenderer, &wall);
    
    // Draw paddle
    SDL_Rect paddle{
        static_cast<int>(mPaddlePos.x),
        static_cast<int>(mPaddlePos.y - paddleH/2),
        thickness,
        static_cast<int>(paddleH)
    };
    SDL_RenderFillRect(mRenderer, &paddle);
    
    // Draw ball
    SDL_Rect ball{
        static_cast<int>(mBallPos.x - thickness/2),
        static_cast<int>(mBallPos.y - thickness/2),
        thickness,
        thickness
    };
    SDL_RenderFillRect(mRenderer, &ball);
    
    // Swap front buffer and back buffer
    SDL_RenderPresent(mRenderer);
}
