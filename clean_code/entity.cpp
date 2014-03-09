// 
// File: entity.cpp 
// 
// 
// 
// @author ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

//#include <iostream>
#include "entity.h"

//using namespace std;

entity::entity(char p, coordinate l) : location_(l.i(), l.j()){
    print_ = p;
    //location_ = l;
}

entity::entity(char p, coordinate l, cave *curr_level) : location_(l.i(), l.j()), curr_level_(curr_level) {
    print_ = p;
}

char entity::print() { return print_; }
coordinate entity::location(){ return location_; }
void entity::set_char(char c) { print_ = c; }
void entity::move(int direction) { // nesw 0123
    coordinate new_pos;
    switch (direction) {
        case 0:
            new_pos = location_.above();
            break;
        case 1:
            new_pos = location_.right();
            break;
        case 2:
            new_pos = location_.below();
            break;
        case 3:
            new_pos = location_.left();
            break;
    }
    if(!(curr_level_->terrain_at(new_pos)))
        location_ = new_pos;
}
void entity::input(char x) {
    switch(x) {
        case 'h':
            move(3);
            break;
        case 'j':
            move(2);
            break;
        case 'k':
            move(0);
            break;
        case 'l':
            move(1);
            break;
    }
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
