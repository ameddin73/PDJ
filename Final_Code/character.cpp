// 
// File: character.cpp 
// 
// 
// 
// @author anm5465: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "define.h"
#include "character.h"
#include "math.h"

using namespace std;

character::character(string initName, int initX, int initY, int initHealth, int initXP, int initSpeed) {
    //Initializes variables
    name_ = initName;
    health_ = initHealth;
    xp_ = initXP;
    x_ = initX;
    y_ = initY;
    speed = initSpeed;

    //Calculate damageMod and attackMod
    damageMod = log10((float)xp_);
    attackMod = log((float)xp_);
}

void character::changeName(string newName) {
    name_ = newName;
}

void character::update() {
    //TODO: update GUI for character location
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
    if(dir == left) {
        if((x_ - speed) != 0)
            x_ -= speed;
    }
    if(dir == up) {
        if((y_ - speed) != 0)
            y_ -= speed;
    }
    if(dir == right) {
        if((x_ + speed) <=  WINDOW_WIDTH)
            x_ += speed;
    }
    if(dir == down) {
        if((y_ + speed) <= WINDOW_HEIGHT)
            y_ += speed;
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
