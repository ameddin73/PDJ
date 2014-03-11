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

using namespace std;

game::game() : player_("Player 1", 400, 300, PLAYER_HEALTH, 0, TILE_SIZE), print_(&quests_, &player_, &current_quest_) {
    current_quest_ = 0;
}
    
void game::run() {
    quest nexus(true, &player_);
    quests_.push_back(nexus);
    current_quest_ = 0;
    printer print(&quests_, &player_, &current_quest_);
    print.init();
    print.load_media();
    print.update();
    char c = getchar();
    print.close();
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
