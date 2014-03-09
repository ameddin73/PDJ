// 
// File: character.cpp 
// 
// 
// 
// @author anm5465: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include <iostream>
#include "character.h"
#include "math.h"

using namespace std;

Character:: Character(char[] initName, int initX, int initY, int initHealth, int initXP, int initSpeed) {
    //Initializes variables
    name_ = initName;
    health_ = inithealth;
    xp_ = initXP;
    x_ = initX;
    y_ = initY;
    speed = initSpeed;

    //Calculate damageMod and attackMod
    damageMod = log10((float)xp_);
    attackMod = log((float)xp_);
}

void Character:: changeName(char[] newName) {
    name = newName;
}

char[] Character:: name() {
    return name_;
}

int Character:: health() {
    return health_;
}

int Character:: xp() {
    return xp_;
}

int Character:: x() {
    return x_;
}

int Character:: y() {
    return y_;
}

void Characer:: addXP(int plusXP) {
    xp_ += plusXP;
}

void Character:: takeDamage(int hitValue) {
    health_ -= (int)((float)hitValue - damageMod);
}

int Character:: giveDamage(int hitValue) {
    return (int)((float)hitVlue + attackMod);
}

void Character:: move(enum direction) {
    if(direction == Direction.Left) {
        if((x_ - speed) != 0)
            x_ -= speed;
    }
    if(direction == Direction.Up) {
        if((y_ - speed) != 0)
            y_ -= speed;
    }
    if(direction == Direction.Right) {
        if((x_ + speed) <=  WINDOW_SIZE)
            x_ += speed;
    }
    if(direction == Direction.Down) {
        if((y_ + speed) <= WINDOW_SIZE)
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
