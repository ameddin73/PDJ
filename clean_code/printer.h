// File: printer.h 
// 
// Version: 
//     $Id$ 
// 
// printer.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include <ncurses.h>

#include "cave.h"
#include "entity.h"

// add include files only if needed for these declarations.

/// @author ddm9373: TODO_AUTHOR_FULL_NAME_
///
class printer{
    public:
        printer();
        void print_level(cave *to_print, vector<entity*> *entities);
};
#endif // PRINTER_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
