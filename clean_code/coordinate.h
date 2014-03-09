// File: coordinate.h 
// 
// Version: 
//     $Id$ 
// 
// coordinate.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef COORDINATE_H
#define COORDINATE_H

// add include files only if needed for these declarations.

/// @author ddm9373: TODO_AUTHOR_FULL_NAME_
///
class coordinate {
    private:
        int i_;
        int j_;
    public:
        coordinate();
        coordinate(int i, int j);
        int i();
        int j();
        coordinate above();
        coordinate left();
        coordinate right();
        coordinate below();
        int equals(coordinate k);
};

#endif // COORDINATE_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
