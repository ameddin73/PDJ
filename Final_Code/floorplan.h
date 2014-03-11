// File: cave.h 
// 
// Version: 
//     $Id$ 
// 
// cave.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef FLOORPLAN_H
#define FLOORPLAN_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
//#include <ncurses.h>

#include "coordinate.h"
#include "define.h"
//#include "entity.h"

using namespace std;

// add include files only if needed for these declarations.

/// @author ddm9373: TODO_AUTHOR_FULL_NAME_
///
class floorplan {
    private:
        int floorplan_[FLOOR_HEIGHT][FLOOR_WIDTH];
        int temp_[FLOOR_HEIGHT][FLOOR_WIDTH];
        vector<coordinate> finalized_;
        vector<coordinate> check_;
        vector<coordinate> checked_;
        int vector_contains(int k, coordinate c);
        void refresh_temp();
        void step_thru(int steps);

    public:
        floorplan(bool nexus);
        int count_space();
        coordinate random_space();
        int terrain_at(coordinate c);
        int terrain_at(int i, int j);
};

#endif // CAVE_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
