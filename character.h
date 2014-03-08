// File: character.h 
// 
// Version: 
//     $Id$ 
// 
// character.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef CHARACTER_H
#define CHARACTER_H

// add include files only if needed for these declarations.

/// @author anm5465: Alex Meddin
///
class Character {

private:
    char[] name_; //Character name
    int health_; //Character health
    int xp_; //Character XP, effects damage/strength for enemies and player
    int x_; //Character x pos
    int y_; //Character y pos
    float damageMod; //Amount of damage taken from hit
    float attackMod; //Amoutn of damage caused by hit

public:

    //Creates new Character with described x, y, health and xp
    //Calculates damageMod and attackMod
    //@param char[] initName
    //@param int initX
    //@param int initY
    //@param int initHealth
    //@param int initXP
    Character(char[] initName, int initX, int initY, int initHealth, int initXP);

    //Changes name of Character
    //@param char[] newName
    void changeName(char[] newName);

    //Returns name of Character
    //@return char[] name_
    char[] name();

    //Returns health of Character
    //@return int health_
    int health();

    //Returns the XP of Character
    //@return int xp_
    int xp();

    //Returns x pos of Character
    //@return int x_
    int x();

    //Returns y pos of Character
    //@return int y_
    int y();

    //Adds XP to Character and returns new XP
    //Updates damageMod and attackMod accordingly
    //@param int plusXP
    void addXP(int plusXP);

    //Calculates damage and subtracts health of Character when hit
    //@param int hitValue
    void takeDamage(int hitValue);i

    //Calculates attack value
    //@param int hitValue
    //@return int hitValue
    int giveDamage(int hitValue);

    //Updates position of Character by moving x and y pixels
    //@param moveX
    //@param moveY
    void move(int moveX, int moveY);

};

#endif // CHARACTER_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
