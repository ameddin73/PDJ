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
    x_vel_ = 0;
    y_vel_ = 0;

    //Calculate damageMod and attackMod
    damageMod = log10((float)xp_);
    attackMod = log((float)xp_);
}

void character::changeName(string newName) {
    name_ = newName;
}

void character::update() {
    //TODO: update GUI for character location
    x_ += x_vel_;
    y_ += y_vel_;
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
