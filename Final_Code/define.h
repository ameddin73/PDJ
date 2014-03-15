// File: define.h 
// 
// Version: 
//     $Id$ 
// 
// define.h TODO_DOCS_
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#ifndef DEFINE_H
#define DEFINE_H

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define LEVEL_HEIGHT 2400
#define LEVEL_WIDTH 3200
#define FLOOR_HEIGHT 60
#define FLOOR_WIDTH 80
#define TILE_SIZE 40

#define PLAYER_HEALTH 100
#define PLAYER_SIZE 16

#define DEFAULT_SPEED 200

#define FIREBALL_SIZE 32

enum tile {
    tile_floor, //0
    tile_single, //5
    tile_internal, //6
    tile_pipe_vert, //7
    tile_pipe_whore, //8
    tile_wall_westface, //9
    tile_wall_northface, //10
    tile_wall_eastface, //11
    tile_wall_southface, //12
    tile_cap_west, //13
    tile_cap_north, //14
    tile_cap_east, //15
    tile_cap_south, //16
    tile_wall_southwest, //17
    tile_wall_southeast, //18
    tile_wall_northwest, //19
    tile_wall_northeast, //20
    tile_corner_southwest, //21
    tile_corner_northwest, //22
    tile_corner_northeast, //23
    tile_corner_southeast, //24
    tile_attachcorner_southwest, //25
    tile_attachcorner_northwest, //26
    tile_attachcorner_northeast, //27
    tile_attachcorner_southeast //28
};

enum direction {
    dir_right,
    dir_up,
    dir_left,
    dir_down
};
// add include files only if needed for these declarations.
//#include "character.h"
//#include "printer.h"
//#include "game.h"
//#include "floorplan.h"
//#include "quest.h"

/// @author douglas: TODO_AUTHOR_FULL_NAME_
///

#endif // DEFINE_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
