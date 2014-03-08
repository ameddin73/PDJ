// 
// File: sdltest.cpp 
// 
// 
// 
// @author                                                                        ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


using namespace std;

int main( int argc, const char* argv[] ) {
    SDL_Window* window = NULL;

    SDL_Surface* screenSurface = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
        printf( "SDL could not initialise!" );
    else {
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if ( window == NULL ) {
            printf( "Window could not be created!" );
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(3000);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
