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
    vector<character> mobs1;
    mobs_.push_back(mobs1);
    if(nexus_) {
        floorplan nexus(true);
        floorplans.push_back(nexus);
    } else {
        floorplan random(false);
        floorplans.push_back(random);
    }

    int x;
    int y;
    do {
        coordinate random = floorplans[current_floor].random_space();
        x = random.j();
        y = random.i();
    } while((TILE_SIZE * x > player_->x() - WINDOW_WIDTH/2 && TILE_SIZE * x < player_->x() + WINDOW_WIDTH/2) && (TILE_SIZE * y > player_->y() - WINDOW_HEIGHT/2 && TILE_SIZE * y < player_->y() + WINDOW_HEIGHT/2));
    panda_ = new character("MFP", x * TILE_SIZE, y * TILE_SIZE, PLAYER_HEALTH, 0, DEFAULT_SPEED, quests, current_quest, character_panda);
}

//quest::~quest() { delete panda_; }

void quest::update(Uint32 dt) {
    diff = player_->xp(); // CHANGE THIS
    time_passed_ += (int)dt;
    if(time_passed_ > 1000) {
        spawn_monster();
        time_passed_ = 0;
    }
    for(vector<character>::iterator it = mobs_[current_floor].begin(); it != mobs_[current_floor].end(); ++it) {
        it->move_degrees((180/PI)*atan2(it->y() - player_->y(), player_->x() - it->x()));
        it->update(dt);
		if (it->collides_with(*player_)) {
			it->take_damage(1000000);
		}
    }
    panda_->update(dt);
}

void quest::spawn_monster() {
    int x;
    int y;
    do {
        coordinate random = floorplans[current_floor].random_space();
        x = random.j();
        y = random.i();
    } while((TILE_SIZE * x > player_->x() - WINDOW_WIDTH/2 && TILE_SIZE * x < player_->x() + WINDOW_WIDTH/2) && (TILE_SIZE * y > player_->y() - WINDOW_HEIGHT/2 && TILE_SIZE * y < player_->y() + WINDOW_HEIGHT/2));
    character zombie("ZOMBEE", x * TILE_SIZE, y * TILE_SIZE, 100, 0, DEFAULT_SPEED/2 + (rand() % (DEFAULT_SPEED/4)), quests_, current_quest_, character_monster);
    mobs_[current_floor].push_back(zombie);
}

vector<character> *quest::mobs() { return &(mobs_[current_floor]); }

floorplan* quest::curr_floor(){ return &(floorplans.front()); }

character* quest::panda() { return panda_; }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
// 
