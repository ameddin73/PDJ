// File: game.h 
// 
// Version: 
//     $Id$ 
// 
// game.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef GAME_H
#define GAME_H

// add include files only if needed for these declarations.
#include <vector>
#include "printer.h"
#include "floorplan.h"
#include "quest.h"
#include "define.h"
/// @author douglas: TODO_AUTHOR_FULL_NAME_
///
#define NUM_QUESTS 1

class game {
    public:
        game();
        void run();
        void handle_event(SDL_Event e);
        void shoot_fireball();
    private:
        vector<quest> quests_;
        vector<character> fireballs_;
        int current_quest_;
        character player_;
        printer print_;
        void update_fireball(vector<character>::iterator it_f);
        void delete_dead();
};

#endif // GAME_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
