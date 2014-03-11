// 
// File: quest.cpp 
// 
// 
// 
// @author anm5465: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 
#include "quest.h"

using namespace std;

quest::quest(bool nexus, character *player) {
    nexus_ = nexus;
    player_ = player;
    current_floor = 0;
    if(nexus_) {
        floorplan nexus(true);
        floorplans.push_back(nexus);
    } else {
        for(int i = 0; i < 3; ++i) {
//            floorplans.push_back(new /*TODO create Floorplan*/);
        }
    }
}

void quest::update() {
    diff = player_->xp(); // CHANGE THIS
}

floorplan* quest::curr_floor(){ return &(floorplans.front()); }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
