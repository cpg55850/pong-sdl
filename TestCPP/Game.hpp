//
//  Game.hpp
//  TestCPP
//
//  Created by Charles Graham on 5/5/23.
//

#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <stdio.h>

// Vector2 struct just stores x/y coordinates
// (for now)
struct Vector2
{
    float x;
    float y;
};

class Game {
public:
    Game();
    // Initialize the game
    bool Initialize();
    // Runs the game loop until the game is over
    void RunLoop();
    // Shutdown the game
    void Shutdown();
private:
    // Helper functions for the game loop
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();
    
    // Window created by SDL
    SDL_Window* mWindow;
    // Renderer for 2D drawing
    SDL_Renderer* mRenderer;
    // Number of ticks since start of game
    Uint32 mTicksCount;
    // Game should continue to run
    bool mIsRunning;
    
    // Pong specific
    // Direction of paddle
    int mPaddleDir;
    // Position of paddle
    Vector2 mPaddlePos;
    // Position of ball
    Vector2 mBallPos;
    // Velocity of ball
    Vector2 mBallVel;
};

#endif /* Game_hpp */
