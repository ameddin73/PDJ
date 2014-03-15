// 
// File: floorplan.cpp 
// 
// 
// 
// @author ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "floorplan.h"

#define HEIGHT FLOOR_HEIGHT
#define WIDTH FLOOR_WIDTH

// SPACE = 0

// private: check if a vector contains coord c
// or at least a coord that has the same values
int floorplan::vector_contains(int k, coordinate c) { 
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

// Initialise the floorplan with random walls
floorplan::floorplan(bool nexus) {
	//create flooplan
    if(nexus) {
        for(int i = 0; i < HEIGHT; i++) {
            for(int j = 0; j < WIDTH; j++) {
                temp_[i][j] = 0;
                floorplan_[i][j] = 0;
            }
        }
        for(int i = 0; i < HEIGHT; i++) {
            floorplan_[i][0] = 1;
            floorplan_[i][WIDTH-1] = 1;
            floorplan_[i][WIDTH/3] = 1;
            floorplan_[i][2*WIDTH/3] = 1;
            temp_[i][0] = 1;
            temp_[i][WIDTH-1] = 1;
        }
        for(int j = 0; j < WIDTH; j++) {
            floorplan_[0][j] = 1;
            floorplan_[HEIGHT-1][j] = 1;
            temp_[0][j] = 1;
            temp_[HEIGHT-1][j] = 1;
        }
    } else {
        do {
            for(int i = 0; i < HEIGHT; i++) {
                for(int j = 0; j < WIDTH; j++) {
                    temp_[i][j] = 0;
                    if((rand() % 100) < 35)
                        floorplan_[i][j] = 1;
                    else
                        floorplan_[i][j] = 0;
                }
            }
            for(int i = 0; i < HEIGHT; i++) {
                floorplan_[i][0] = 1;
                floorplan_[i][WIDTH-1] = 1;
                temp_[i][0] = 1;
                temp_[i][WIDTH-1] = 1;
            }
            for(int j = 0; j < WIDTH; j++) {
                floorplan_[0][j] = 1;
                floorplan_[HEIGHT-1][j] = 1;
                temp_[0][j] = 1;
                temp_[HEIGHT-1][j] = 1;
            }

            for(int i = 0; i < 4; i++) step_thru(1);
            for(int i = 0; i < 3; i++) step_thru(0);
        } while ((count_space()*100 / (HEIGHT * WIDTH)) < 50 );
        for(int i = 0; i < HEIGHT; i++)
            for(int j = 0; j < WIDTH; j++)
                if(!vector_contains(1, coordinate(i, j))) floorplan_[i][j] = 1;
    }
	//check tile type
	//internal
	for (int i = 1; i < HEIGHT - 1; i++) {
		for (int j = 1; j < WIDTH - 1; j++) {
			if (floorplan_[i][j]){
				floorplan_[i][j] = tile_single;
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j]) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1] == 0) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j] == 0) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j] == 0)) { //left
					floorplan_[i][j] = tile_cap_south;
				} 
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j] == 0) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1]) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j] == 0) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_pipe_whore;
				} 
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j] == 0) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1] == 0) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j] == 0) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_cap_east;
				} 
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j]) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1] == 0) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j] == 0)) { //left
					floorplan_[i][j] = tile_pipe_vert;
				}
				
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j] == 0) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1] == 0) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j] == 0)) { //left
					floorplan_[i][j] = tile_cap_north;
				}
				
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j] == 0) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1]) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j] == 0) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j] == 0)) { //left
					floorplan_[i][j] = tile_cap_west;
				} 
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j]) && //top
					(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1]) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_attachcorner_southwest;
				} 
				if (//(floorplan_[i - 1][j - 1] ) && //top-left
					(floorplan_[i - 1][j]) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1]) && //right
					(floorplan_[i + 1][j + 0] == 0) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_attachcorner_northwest;
				}
				
				if (//(floorplan_[i - 1][j - 1] ) && //top-left
					(floorplan_[i - 1][j]) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1]) && //right
					//(floorplan_[i + 1][j + 0] == 0) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_attachcorner_northeast;
				}
				
				if ((floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j]) && //top
					//(floorplan_[i - 1][j + 1] == 0) && //top-right
					(floorplan_[i][j + 1]) && //right
					//(floorplan_[i + 1][j + 0] == 0) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_attachcorner_southeast;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    //(floorplan_[i - 1][j + 1] ) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    //(floorplan_[i + 1][j + 1] ) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] == 0)) { //left
                    floorplan_[i][j] = tile_wall_westface;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] == 0) && //top
                    //(floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    //(floorplan_[i + 1][j + 1] ) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    //(floorplan_[i + 1][j - 1] ) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_wall_northface;
                } 
                if (//(floorplan_[i - 1][j - 1] ) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    //(floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] == 0) && //right
                    //(floorplan_[i + 1][j + 1] ) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    //(floorplan_[i + 1][j - 1] ) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_wall_eastface;
                } 
                if (//(floorplan_[i - 1][j - 1] ) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    //(floorplan_[i - 1][j + 1] ) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] == 0) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_wall_southface;
                } 
               
                 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    (floorplan_[i - 1][j + 1] ) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] == 0) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] == 0)) { //left
                    floorplan_[i][j] = tile_wall_southwest;
                } 
                if ((floorplan_[i - 1][j - 1] ) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    //(floorplan_[i - 1][j + 1] ) && //top-right
                    (floorplan_[i][j + 1] == 0) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] == 0) && //bottom
                    //(floorplan_[i + 1][j - 1] ) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_wall_southeast;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] == 0) && //top
                    //(floorplan_[i - 1][j + 1] ) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    (floorplan_[i + 1][j + 1] ) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] == 0)) { //left
                    floorplan_[i][j] = tile_wall_northwest;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] == 0) && //top
                    (floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] == 0) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    //(floorplan_[i + 1][j - 1] ) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_wall_northeast;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    (floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] == 0) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] == 0)) { //left
                    floorplan_[i][j] = tile_corner_southwest;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] == 0) && //top
                    //(floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] ) && //right
                    (floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] == 0)) { //left
                    floorplan_[i][j] = tile_corner_northwest;
                } 
                if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] == 0) && //top
                    //(floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] == 0) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] ) && //bottom
                    (floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_corner_northeast;
                } 
                if ((floorplan_[i - 1][j - 1] == 0) && //top-left
                    (floorplan_[i - 1][j] ) && //top
                    //(floorplan_[i - 1][j + 1] == 0) && //top-right
                    (floorplan_[i][j + 1] == 0) && //right
                    //(floorplan_[i + 1][j + 1] == 0) && //bottom-right
                    (floorplan_[i + 1][j] == 0) && //bottom
                    //(floorplan_[i + 1][j - 1] == 0) && //bottom-left
                    (floorplan_[i - 1][j] )) { //left
                    floorplan_[i][j] = tile_corner_southeast;
				} 
				if (//(floorplan_[i - 1][j - 1] == 0) && //top-left
					(floorplan_[i - 1][j]) && //top
					(floorplan_[i - 1][j + 1]) && //top-right
					(floorplan_[i][j + 1]) && //right
					//(floorplan_[i + 1][j + 1] == 0) && //bottom-right
					(floorplan_[i + 1][j] == 0) && //bottom
					//(floorplan_[i + 1][j - 1] == 0) && //bottom-left
					(floorplan_[i - 1][j] == 0)) { //left
					floorplan_[i][j] = tile_wall_southwest;
				} 	
                if(!(floorplan_[i - 1][j - 1]) && //top-left
					(!floorplan_[i - 1][j]) && //top
					(!floorplan_[i - 1][j + 1]) && //top-right
					(!floorplan_[i][j + 1]) && //right
					(!floorplan_[i + 1][j + 1]) && //bottom-right
					(!floorplan_[i + 1][j]) && //bottom
					(!floorplan_[i + 1][j - 1]) && //bottom-left
					(!floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_single;
				} 
				if ((floorplan_[i - 1][j - 1]) && //top-left
					(floorplan_[i - 1][j]) && //top
					(floorplan_[i - 1][j + 1]) && //top-right
					(floorplan_[i][j + 1]) && //right
					(floorplan_[i + 1][j + 1]) && //bottom-right
					(floorplan_[i + 1][j]) && //bottom
					(floorplan_[i + 1][j - 1]) && //bottom-left
					(floorplan_[i - 1][j])) { //left
					floorplan_[i][j] = tile_internal;
				}
            }
		} //ALEX IS A BUTTHOLE!! <3 Topher
	}//DOUG IS A BUTTHOLE!! <3 Meddin
}
int floorplan::count_space() {
    check_.clear();
    checked_.clear();
    finalized_.clear();
    int i = 0;
    int j = 0;
    do {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
    } while (floorplan_[i][j]);
    check_.push_back(coordinate(i, j));
    coordinate temp(-1, -1);
    while (!check_.empty()) {
        temp = check_.front();
        check_.erase(check_.begin());
        checked_.push_back(temp);
        if(!floorplan_[temp.i()][temp.j()]){
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
void floorplan::step_thru(int steps) {
    refresh_temp();
    int adj_count = 0;
    for(int i = 1; i < HEIGHT-1; i++) {
        for(int j = 1; j < WIDTH-1; j++) {
            adj_count = 0;
            for(int ii = -1; ii <= 1; ii++)
                for(int jj = -1; jj <= 1; jj++)
                    if(floorplan_[i+ii][j+jj]) adj_count++;
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
                        if(floorplan_[i+ii][j+jj]) adj_count++;
                    }
                if(adj_count <= 2) temp_[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < HEIGHT; i++)
        for(int j = 0; j < WIDTH; j++)
            floorplan_[i][j] = temp_[i][j];
}
void floorplan::refresh_temp() {
    for(int i = 1; i < HEIGHT-1; i++)
        for(int j = 1; j < WIDTH-1; j++)
            temp_[i][j] = 0;
}
coordinate floorplan::random_space() {
    int i, j;
    do {
        i = rand() % HEIGHT;
        j = rand() % WIDTH;
    } while (floorplan_[i][j]);
    coordinate temp(i, j);
    return temp;   
}

int floorplan::terrain_at(coordinate c) { return floorplan_[c.i()][c.j()]; }
int floorplan::terrain_at(int i, int j) { return floorplan_[i][j]; }
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
/*
//void floorplan::print_floorplan() {
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
            //switch(floorplan_[i][j]) {
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
/*//void floorplan::add_entity(entity *to_add) { 
    //entities_.push_back(to_add);
//}*/

//char floorplan::entity_char() { return entities_.front()->print(); }
/*//void floorplan::change_finalized() {
    //for(vector<coordinate>::iterator it = finalized_.begin(); it != finalized_.end(); ++it) {
        //floorplan_[it->i()][it->j()] = 2;
    //}
//}*/
