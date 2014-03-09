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

/// @author anm5465: Alex Meddin
///
class Quest {

private:
    vector<Floorplan> floorplans; //Array of Floorplan's in descending order
    vector< vector<*Character> > mobs; //Array of enemies on each floor in descending
    //order
    int currentFloor; //index of current floor and enemy set
    int diff; //Difficulty level of level (between 1 and 10)

public:
    
    //Creates new Quest according to difficulty level
    //Spawns enemies
    //@param float initDiff
    Quest(int initDiff);

    //Updates enemy count and status of Quest
    void update();

}

#endif // QUEST_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
