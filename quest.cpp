// 
// File: quest.cpp 
// 
// 
// 
// @author anm5465: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include <iostream>

using namespace std;

Quest:: Quest(int initDiff) {
    diff = initDiff;
    for(int i = 0; i < diff; ++i) {
        floorplans.push_back(new /*TODO create Floorplan*/);
        vector<Character> row;
        for(int j = 0; j < diff; ++j) {
            row.push_back(new /*TODO enemy*/("floor" + to_string(i) + "mob"
                          + to_string(j), /*TODO x,y according to map*/,
                          diff * 30, diff * 100, diff * 5);
        }
        mobs.push_back(row);
    }
}

Quest:: update() {
    //Update mobs
    for(int i = 0; i < diff; ++i) {
        for(int j = 0; j < diff; ++j) {
            dkl
        }
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
