// 
// File: character.cpp 
// 
// 
// 
// @author Douglas Moyer and Alex Meddin
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "define.h"
#include "character.h"
#include "math.h"

using namespace std;

character::character(string initName, int initX, int initY, int initHealth, int initXP, int initSpeed, vector<quest> *quests, int *current_quest) {
    //Initializes variables
    name_ = initName;
    health_ = initHealth;
    xp_ = initXP;
    x_ = initX;
    y_ = initY;
    speed = initSpeed;
    x_vel_ = 0;
    y_vel_ = 0;

    //Calculate damageMod and attackMod
    damageMod = log10((float)xp_);
    attackMod = log((float)xp_);

    quests_ = quests;
    current_quest_ = current_quest;
}

void character::changeName(string newName) {
    name_ = newName;
}

void character::update() {
    //TODO: update GUI for character location
    x_ += x_vel_;
    // i = x left
    int i = (x_ - (x_ % TILE_SIZE)) / TILE_SIZE;
    // j = y top
    int j = (y_ - (y_ % TILE_SIZE)) / TILE_SIZE;
    // k = x right
    int k = ((x_ + PLAYER_SIZE) - ((x_ + PLAYER_SIZE) % TILE_SIZE)) / TILE_SIZE;
    // l = y bot
    int l = ((y_ + PLAYER_SIZE) - ((y_ + PLAYER_SIZE) % TILE_SIZE)) / TILE_SIZE;
    if(x_vel_ < 0) {
        if((*quests_)[*current_quest_].curr_floor()->terrain_at(j, i)) {
            x_ = TILE_SIZE + (x_ - (x_ % TILE_SIZE)) + 1;
        }
        else if((*quests_)[*current_quest_].curr_floor()->terrain_at(l, i)) {
            x_ = TILE_SIZE + (x_ - (x_ % TILE_SIZE)) + 1;
        }
    }
    else if(x_vel_ > 0) {
        if((*quests_)[*current_quest_].curr_floor()->terrain_at(j, k)) {
            x_ = (x_) - ((x_ + PLAYER_SIZE) % TILE_SIZE) - 1;
        }
        else if((*quests_)[*current_quest_].curr_floor()->terrain_at(l, k)) {
            x_ = (x_) - ((x_ + PLAYER_SIZE) % TILE_SIZE) - 1;
        }
    }
    y_ += y_vel_;
    // i = x left
    i = (x_ - (x_ % TILE_SIZE)) / TILE_SIZE;
    // j = y top
    j = (y_ - (y_ % TILE_SIZE)) / TILE_SIZE;
    // k = x right
    k = ((x_ + PLAYER_SIZE) - ((x_ + PLAYER_SIZE) % TILE_SIZE)) / TILE_SIZE;
    // l = y bot
    l = ((y_ + PLAYER_SIZE) - ((y_ + PLAYER_SIZE) % TILE_SIZE)) / TILE_SIZE;
    if(y_vel_ < 0) {
        if((*quests_)[*current_quest_].curr_floor()->terrain_at(j, i)) {
            y_ = TILE_SIZE + (y_ - (y_ % TILE_SIZE)) + 1;
        }
        else if((*quests_)[*current_quest_].curr_floor()->terrain_at(j, k)) {
            y_ = TILE_SIZE + (y_ - (y_ % TILE_SIZE)) + 1;
        }
    }
    else if(y_vel_ > 0) {
        if((*quests_)[*current_quest_].curr_floor()->terrain_at(l, i)) {
            y_ = (y_) - ((y_ + PLAYER_SIZE) % TILE_SIZE) - 1;
        }
        else if((*quests_)[*current_quest_].curr_floor()->terrain_at(l, k)) {
            y_ = (y_) - ((y_ + PLAYER_SIZE) % TILE_SIZE) - 1;
        }
    }
}

string character::name() {
    return name_;
}

int character::health() {
    return health_;
}

int character::xp() {
    return xp_;
}

int character::x() {
    return x_;
}

int character::y() {
    return y_;
}

void character::addXP(int plusXP) {
    xp_ += plusXP;
}

void character::takeDamage(int hitValue) {
    health_ -= (int)((float)hitValue - damageMod);
}

int character::giveDamage(int hitValue) {
    return (int)((float)hitValue + attackMod);
}

void character::move(enum direction dir) {
    if(dir == dir_left) 
        x_vel_ = -speed;
    if(dir == dir_up) 
        y_vel_ = -speed;
    if(dir == dir_right) 
        x_vel_ = speed;
    if(dir == dir_down) 
        y_vel_ = speed;
}

void character::stop_move(enum direction dir) {
    if(dir == dir_left && x_vel_ == -speed) 
        x_vel_ = 0;
    if(dir == dir_up && y_vel_ == -speed) 
        y_vel_ = 0;
    if(dir == dir_right && x_vel_ == speed) 
        x_vel_ = 0;
    if(dir == dir_down && y_vel_ == speed) 
        y_vel_ = 0;

}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
