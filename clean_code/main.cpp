// 
// File: main.cpp 
// 
// 
// 
// @author ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include <iostream>
#include <ctime>

#include "cave.h"
#include "entity.h"
#include "printer.h"
using namespace std;

int main( int argc, const char* argv[] ) {
    vector<entity*> entities;
    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);
    cave test;
    //coordinate temp = test.random_space();
    entity character('@', test.random_space(), &test);
    entities.push_back(&character);
    printer print;
    print.print_level(&test, &entities); 
    char input;
    while((input = getch()) != 'q') {
        character.input(input);
        print.print_level(&test, &entities);
        //move(5,9);
        //addch('%');
        move(0, 0);
    }
    endwin();
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
