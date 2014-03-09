// File: entity.h 
// 
// Version: 
//     $Id$ 
// 
// entity.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef ENTITY_H
#define ENTITY_H

// add include files only if needed for these declarations.
#include "coordinate.h"
#include "cave.h"

/// @author ddm9373: TODO_AUTHOR_FULL_NAME_
///
class entity {
    protected:
        char print_;
        // make a name
        coordinate location_;
        cave *curr_level_;
        void move(int direction);
    public:
        entity(char p, coordinate l);
        entity(char p, coordinate l, cave *curr_level);
        char print();
        coordinate location();
        void set_char(char c);
        void input(char x);
        void update();
};

#endif // ENTITY_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
