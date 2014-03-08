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
    float damageMod; //Amount of damage taken from hit
    float attackMod; //Amoutn of damage caused by hit

public:

//Changes name of Character
//@param char[] newName
void changeName(char[] newName);

//Returns name of Character
//@return char[] name
char[] name();

//Returns health of Character
//@return int health
int health();

//Returns the XP of Character
//@return int xp
int xp();

//Adds XP to Character and returns new XP
//@param int plusXP
void addXP(int plusXP);

//Calculates damage and subtracts health of Character when hit
//@param int hitValue
void takeDamage(int hitValue);i

//Calculates attack value
//@return int hitValue
int giveDamage();

};

#endif // CHARACTER_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
