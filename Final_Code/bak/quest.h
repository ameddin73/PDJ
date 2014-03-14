// File: quest.h 
// 
// Version: 
//     $Id$ 
// 
// quest.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef QUEST_H
#define QUEST_H

// add include files only if needed for these declarations.
#include <vector>
#include "floorplan.h"
#include "character.h"
#include "define.h"
/// @author anm5465: Alex Meddin
///

class character;

class quest {

private:
    vector<floorplan> floorplans; //Array of Floorplan's in descending order
    vector< vector<character*> > mobs; //Array of enemies on each floor in descending
    //order
    int current_floor; //index of current floor and enemy set
    int diff; //Difficulty level of level (between 1 and 10)
    bool nexus_;
    character* player_;

public:
    
    //Creates new Quest according to difficulty level
    //Spawns enemies
    //@param float initDiff
    quest(bool nexus, character *player);
    //Updates enemy count and status of Quest
    void update();
    
    floorplan *curr_floor();

};

#endif // QUEST_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
