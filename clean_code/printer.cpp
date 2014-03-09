// 
// File: printer.cpp 
// 
// 
// 
// @author ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "printer.h"

using namespace std;

printer::printer(){}

void printer::print_level(cave *to_print, vector<entity*> *entities) {
    move(0,0);
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            switch(to_print->terrain_at(i, j)) {
                case 0:
                    printw(".");
                    break;
                case 1:
                    printw("+");
                    break;
                case 2:
                    printw("*");
                    break;
                default:
                    printw(" ");
                    break;
            }
        }
        printw("\n");
    }
    for(vector<entity*>::iterator it = entities->begin(); it != entities->end(); ++it) {
        move((*it)->location().i(), (*it)->location().j());
        addch((*it)->print());
    }
}
// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
