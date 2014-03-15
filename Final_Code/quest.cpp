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

quest::quest(bool nexus, character *player, int *current_quest) {
    current_quest_ = current_quest;
    time_passed_ = 0;
    nexus_ = nexus;
    player_ = player;
    current_floor = 0;
    if(nexus_) {
        floorplan nexus(true);
        floorplans.push_back(nexus);
    } else {
        for(int i = 0; i < 3; ++i) {
        }
        floorplan random(false);
        floorplans.push_back(random);
    }
}

void quest::update(Uint32 dt) {
    diff = player_->xp(); // CHANGE THIS
    time_passed += (int)dt;
    if(time_passed > 10000) {
        spawn_monster();
        time_passed = 0;
    }
    for(vector<character>
}

void quest::spawn_monster() {
    int x;
    int y;
    do {
        coordinate random = floorplans(current_floor).random_space();
        x = random.j();
        y = random.i();
    } while((x > player_->x() - WINDOW_WIDTH/2 && x < player_->x() + WINDOW_WIDTH/2) || y > player_->y() - WINDOW_HEIGHT/2 && y < player_->y() + WINDOW_HEIGHT/2);
    character zombie("ZOMBEE", x * TILE_SIZE, y * TILE_SIZE, 100, 0, DEFAULT_SPEED, this, current_quest_, character_monster);
    zombie.move(rand() % 4);
    mobs[current_floor].push_back(zombie);
}

floorplan* quest::curr_floor(){ return &(floorplans.front()); }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
