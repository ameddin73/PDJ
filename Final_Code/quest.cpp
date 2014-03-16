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
    got_panda = false;
    quests_ = quests;
    current_quest_ = current_quest;
    time_passed_ = 0;
    nexus_ = nexus;
    player_ = player;
    current_floor = 0;
    vector<character> mobs1;
    mobs_.push_back(mobs1);
    int x;
    int y;
    if(nexus_) {
        floorplan nexus(true);
        floorplans.push_back(nexus);
    } else {
        floorplan random(false);
        coordinate random_pos = random.random_space();
        x = random_pos.j() * TILE_SIZE;
        y = random_pos.i() * TILE_SIZE;
        floorplans.push_back(random);
    }

    player_->set_position(x, y);

    do {
        coordinate random_coor = floorplans[current_floor].random_space();
        x = random_coor.j();
        y = random_coor.i();
    } while((TILE_SIZE * x > player_->x() - WINDOW_WIDTH/2 && TILE_SIZE * x < player_->x() + WINDOW_WIDTH/2) && (TILE_SIZE * y > player_->y() - WINDOW_HEIGHT/2 && TILE_SIZE * y < player_->y() + WINDOW_HEIGHT/2));
    panda_ = new character("MFP", x * TILE_SIZE, y * TILE_SIZE, PLAYER_HEALTH, 0, DEFAULT_SPEED / 2, quests, current_quest, character_panda);
    do {
        coordinate random_coor = floorplans[current_floor].random_space();
        x = random_coor.j();
        y = random_coor.i();
    } while(((TILE_SIZE * x > player_->x() - WINDOW_WIDTH/2 && TILE_SIZE * x < player_->x() + WINDOW_WIDTH/2) && (TILE_SIZE * y > player_->y() - WINDOW_HEIGHT/2 && TILE_SIZE * y < player_->y() + WINDOW_HEIGHT/2)) && ((*quests_)[*current_quest_].curr_floor()->terrain_at(y + 1, x) || (*quests_)[*current_quest_].curr_floor()->terrain_at(y, x + 1) || (*quests_)[*current_quest_].curr_floor()->terrain_at(y + 1, x + 1)));
    cout << "x: " << x << " y: " << y << "\n";
    trapdoor_ = new character("It's a trap!", x * TILE_SIZE, y * TILE_SIZE, PLAYER_HEALTH, 0, 0, quests, current_quest, character_trapdoor);
}

//quest::~quest() { delete panda_; }

void quest::new_quest() {
    quest newq(false, player_, quests_, current_quest_);
    quests_->push_back(newq);
    *current_quest_ += 1;
}

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
    if(panda_->collides_with(*player_)){
        got_panda = true;
        trapdoor_->face_direction(dir_up);
    }
    if(got_panda && (player_->is_moving())) panda_->stop();
    if(got_panda && !player_->is_moving()) panda_->move_degrees(0);
    panda_->update(dt);
    if(got_panda){
        panda_->set_position(player_->x() - 8, player_->y() - 8);
        panda_->face_direction(player_->get_direction());
    }
    if(got_panda && trapdoor_->collides_with(*player_)) new_quest();
}

void quest::spawn_monster() {
    int x;
    int y;
    do {
        coordinate random = floorplans[current_floor].random_space();
        x = random.j();
        y = random.i();
    } while((TILE_SIZE * x > player_->x() - WINDOW_WIDTH/2 && TILE_SIZE * x < player_->x() + WINDOW_WIDTH/2) && (TILE_SIZE * y > player_->y() - WINDOW_HEIGHT/2 && TILE_SIZE * y < player_->y() + WINDOW_HEIGHT/2));
    character zombie("ZOMBEE", x * TILE_SIZE, y * TILE_SIZE, 100, 0, DEFAULT_SPEED/3 + (rand() % (DEFAULT_SPEED/4)), quests_, current_quest_, character_monster);
    mobs_[current_floor].push_back(zombie);
}

vector<character> *quest::mobs() { return &(mobs_[current_floor]); }

floorplan* quest::curr_floor(){ return &(floorplans.front()); }

character* quest::panda() { return panda_; }

character* quest::trapdoor() { return trapdoor_; }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
// 
