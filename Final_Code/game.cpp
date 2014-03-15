// 
// File: game.cpp 
// 
// 
// 
// @author douglas: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include <iostream>
#include "game.h"
#include "SDL2/SDL.h"

using namespace std;

game::game() : player_("Player 1", -1, -1, PLAYER_HEALTH, 0, DEFAULT_SPEED*2, &quests_, &current_quest_, character_player), print_(&quests_, &player_, &current_quest_, &fireballs_) {
    current_quest_ = 0;
}
    
void game::run() {
    quest nexus(false, &player_, &current_quest_);
    quests_.push_back(nexus);
    current_quest_ = 0;
    player_.random_pos();
    printer print(&quests_, &player_, &current_quest_, &fireballs_);
    print.init();
    print.load_media();
    bool running = true;
    SDL_Event e;
    Uint32 ticks = 0;
    Uint32 dt = 0;
    while(running) {
        dt = print.get_ticks() - ticks;
        ticks = print.get_ticks();
        while (print.poll_event(&e) != 0) {
            if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_q)
                running = false;
            handle_event(e);
        }
        player_.update(dt);
        for(vector<character>::iterator it = fireballs_.begin(); it != fireballs_.end(); ++it)
            it->update(dt);
        print.update();
    }
    print.close();
}

void game::shoot_fireball() {
    int x = 0;
    int y = 0;
    switch(player_.get_direction()) {
        case dir_up:
            x = player_.x() + PLAYER_SIZE/2 - FIREBALL_SIZE/2;
            y = player_.y() - FIREBALL_SIZE; break;
        case dir_left:
            x = player_.x() - FIREBALL_SIZE;
            y = player_.y() + PLAYER_SIZE/2 - FIREBALL_SIZE/2; break;
        case dir_down:
            x = player_.x() + PLAYER_SIZE/2 - FIREBALL_SIZE/2;
            y = player_.y() + PLAYER_SIZE; break;
        case dir_right:
            x = player_.x() + PLAYER_SIZE;
            y = player_.y() + PLAYER_SIZE/2 - FIREBALL_SIZE/2; break;
    }
    character fireball("Ball o' FIRE", x, y, 1000, 0, (DEFAULT_SPEED/2) + (rand() % DEFAULT_SPEED), &quests_, &current_quest_, character_fireball);
    fireball.move_degrees(((rand() % 90) - 45) + 90 * player_.get_direction());
    fireballs_.push_back(fireball); 
}
void game::handle_event(SDL_Event e) {
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player_.move(dir_up); break;
            case SDLK_DOWN: player_.move(dir_down); break;
            case SDLK_LEFT: player_.move(dir_left); break;
            case SDLK_RIGHT: player_.move(dir_right); break;
            case SDLK_w: player_.face_direction(dir_up); break;
            case SDLK_a: player_.face_direction(dir_left); break;
            case SDLK_s: player_.face_direction(dir_down); break;
            case SDLK_d: player_.face_direction(dir_right); break;
            case SDLK_SPACE: shoot_fireball(); break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: player_.stop_move(dir_up); break;
            case SDLK_DOWN: player_.stop_move(dir_down); break;
            case SDLK_LEFT: player_.stop_move(dir_left); break;
            case SDLK_RIGHT: player_.stop_move(dir_right); break;
        }
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
