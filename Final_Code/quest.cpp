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

quest::quest(bool nexus, character *player, vector<quest> *quests, int *current_quest) {
    quests_ = quests;
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
    time_passed_ += (int)dt;
    if(time_passed_ > 10000) {
        spawn_monster();
        time_passed_ = 0;
    }
    for(vector<character>::iterator it = mobs_[current_floor].begin(); it != mobs_[current_floor].end(); ++it)
        it->update(dt);
}

void quest::spawn_monster() {
    int x;
    int y;
    do {
        coordinate random = floorplans[current_floor].random_space();
        x = random.j();
        y = random.i();
    } while((x > player_->x() - WINDOW_WIDTH/2 && x < player_->x() + WINDOW_WIDTH/2) || (y > player_->y() - WINDOW_HEIGHT/2 && y < player_->y() + WINDOW_HEIGHT/2));
    character zombie("ZOMBEE", x * TILE_SIZE, y * TILE_SIZE, 100, 0, DEFAULT_SPEED, quests_, current_quest_, character_monster);
    zombie.move(static_cast<direction>(rand() % 4));
    mobs_[current_floor].push_back(zombie);
}

//vector<character> *mobs() { return &(mobs_[current_floor]); }

floorplan* quest::curr_floor(){ return &(floorplans.front()); }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
// 
