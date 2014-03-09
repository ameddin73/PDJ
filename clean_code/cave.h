// File: cave.h 
// 
// Version: 
//     $Id$ 
// 
// cave.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef CAVE_H
#define CAVE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>

#include "coordinate.h"
//#include "entity.h"

using namespace std;
const int WIDTH = 16;
const int HEIGHT = 12;

// add include files only if needed for these declarations.

/// @author ddm9373: TODO_AUTHOR_FULL_NAME_
///
class cave {
    private:
    int cave_[HEIGHT][WIDTH];
    int temp_[HEIGHT][WIDTH];
    vector<coordinate> finalized_;
    vector<coordinate> check_;
    vector<coordinate> checked_;
    int vector_contains(int k, coordinate c);
    void refresh_temp();
    void step_thru(int steps);

    public:
    cave();
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
