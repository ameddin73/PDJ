// 
// File: coordinate.cpp 
// 
// 
// 
// @author ddm9373: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "coordinate.h" 

using namespace std;

coordinate::coordinate(int i, int j) {
    i_ = i;
    j_ = j;
}
coordinate::coordinate() {
    i_ = -1;
    j_ = -1;
}

int coordinate::i() { return i_; }
int coordinate::j() { return j_; }

coordinate coordinate::above() {
    return coordinate(i_ - 1, j_);
}
coordinate coordinate::left() {
    return coordinate(i_, j_ - 1);
}
coordinate coordinate::right() {
    return coordinate(i_, j_ + 1);
}
coordinate coordinate::below() {
    return coordinate(i_ + 1, j_);
}

int coordinate::equals(coordinate k) {
    if(k.i() == i_ && k.j() == j_) return 1;
    return 0;
}

// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
