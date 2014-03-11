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
    private:
        vector<quest> quests_;
        int current_quest_;
        character player_;
        printer print_;
};

#endif // GAME_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
