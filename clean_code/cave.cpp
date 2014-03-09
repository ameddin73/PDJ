// 
// File: cave.cpp 
// 
// 
// 
// @author ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "cave.h"

using namespace std;

// SPACE = 0

// private: check if a vector contains coord c
// or at least a coord that has the same values
int cave::vector_contains(int k, coordinate c) { 
    int toreturn = 0;
    if(k == 1)
        for(vector<coordinate>::iterator it = finalized_.begin(); it != finalized_.end(); ++it)
            if(it->equals(c)) toreturn = 1;
    if(k == 2)
        for(vector<coordinate>::iterator it = check_.begin(); it != check_.end(); ++it)
            if(it->equals(c)) toreturn = 1;
    if(k == 3)
        for(vector<coordinate>::iterator it = checked_.begin(); it != checked_.end(); ++it)
            if(it->equals(c)) toreturn = 1;
    return toreturn;
}

// Initialise the cave with random walls
cave::cave() {
    do {
        for(int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < WIDTH; j++) {
                temp_[i][j] = 0;
                if((rand() % 100) < 35)
                    cave_[i][j] = 1;
                else
                    cave_[i][j] = 0;
            }
        }
        for(int i = 0; i < HEIGHT; i++) {
            cave_[i][0] = 1;
            cave_[i][WIDTH-1] = 1;
            temp_[i][0] = 1;
            temp_[i][WIDTH-1] = 1;
        }
        for(int j = 0; j < WIDTH; j++) {
            cave_[0][j] = 1;
            cave_[HEIGHT-1][j] = 1;
            temp_[0][j] = 1;
            temp_[HEIGHT-1][j] = 1;
        }

        for(int i = 0; i < 4; i++) step_thru(1);
        for(int i = 0; i < 3; i++) step_thru(0);
    } while ((count_space()*100 / (HEIGHT * WIDTH)) < 40 );
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            if(!vector_contains(1, coordinate(i, j))) cave_[i][j] = 1;
}
int cave::count_space() {
    check_.clear();
    checked_.clear();
    finalized_.clear();
    int i = 0;
    int j = 0;
    do {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
    } while (cave_[i][j]);
    check_.push_back(coordinate(i, j));
    coordinate temp(-1, -1);
    while (!check_.empty()) {
        temp = check_.front();
        check_.erase(check_.begin());
        checked_.push_back(temp);
        if(!cave_[temp.i()][temp.j()]){
            finalized_.push_back(temp);
            if(!vector_contains(2, temp.above()) && !vector_contains(3, temp.above()))
                check_.push_back(temp.above());
            if(!vector_contains(2, temp.left()) && !vector_contains(3, temp.left()))
                check_.push_back(temp.left());
            if(!vector_contains(2, temp.right()) && !vector_contains(3, temp.right()))
                check_.push_back(temp.right());
            if(!vector_contains(2, temp.below()) && !vector_contains(3, temp.below()))
                check_.push_back(temp.below());
        }
    }
    return finalized_.size();
}
void cave::step_thru(int steps) {
    refresh_temp();
    int adj_count = 0;
    for(int i = 1; i < HEIGHT-1; i++) {
        for(int j = 1; j < WIDTH-1; j++) {
            adj_count = 0;
            for(int ii = -1; ii <= 1; ii++)
                for(int jj = -1; jj <= 1; jj++)
                    if(cave_[i+ii][j+jj]) adj_count++;
            if(adj_count >= 5) temp_[i][j] = 1;
            else temp_[i][j] = 0;
        }
    }
    if(steps) {
        for(int i = 2; i < HEIGHT - 2; i++) {
            for(int j = 2; j < WIDTH - 2; j++) {
                adj_count = 0;
                for (int ii = -2; ii <= 2; ii++)
                    for(int jj = -2; jj <= 2; jj++) {
                        if(abs(ii) + abs(jj) == 4) continue;
                        if(cave_[i+ii][j+jj]) adj_count++;
                    }
                if(adj_count <= 2) temp_[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            cave_[i][j] = temp_[i][j];
}
void cave::refresh_temp() {
    for(int i = 1; i < HEIGHT-1; i++)
        for(int j = 1; j < WIDTH-1; j++)
            temp_[i][j] = 0;
}
coordinate cave::random_space() {
    int i, j;
    do {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
    } while (cave_[i][j]);
    coordinate temp(i, j);
    return temp;   
}

int cave::terrain_at(coordinate c) { return cave_[c.i()][c.j()]; }
int cave::terrain_at(int i, int j) { return cave_[i][j]; }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
/*
//void cave::print_cave() {
    ////clear();
    //move(0,0);
    ////cout << "\t";
    //// the following code adds coordinates for debugging
    //// for( int j = 0; j < WIDTH; j++) cout << j % 10; cout << "\n";
    //for(int i = 0; i < HEIGHT; i++) {
        //// again coordinate code
        //// cout << i << "\t";
        //for(int j = 0; j < WIDTH; j++) {
            ////if(vector_contains(4, coordinate(i, j))) {
                ////printw("@");
                ////continue;
            ////}
            //switch(cave_[i][j]) {
                //case 0:
                    //printw(".");
                    //break;
                //case 1:
                    //printw("+");
                    //break;
                //case 2:
                    //printw("*");
                    //break;
                //default:
                    //printw(" ");
                    //break;
            //}
        //}
        //printw("\n");
    //}
    ////refresh();
    //for(vector<entity*>::iterator it = entities_.begin(); it!= entities_.end(); ++it){
        //move((*it)->location().i(), (*it)->location().j());
        //addch((*it)->print());
    //}
//}
*/
/*//void cave::add_entity(entity *to_add) { 
    //entities_.push_back(to_add);
//}*/

//char cave::entity_char() { return entities_.front()->print(); }
/*//void cave::change_finalized() {
    //for(vector<coordinate>::iterator it = finalized_.begin(); it != finalized_.end(); ++it) {
        //cave_[it->i()][it->j()] = 2;
    //}
//}*/
