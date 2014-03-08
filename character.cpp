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

Character:: Character(char[] initName, int initX, int initY, int initHealth, int initXP) {
    //Initializes variables
    name_ = initName;
    health_ = inithealth;
    xp_ = initXP;
    x_ = initX;
    y_ = initY;

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

void Character:: move(int moveX, moveY) {
    x_ += moveX;
    y_ += moveY;
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
