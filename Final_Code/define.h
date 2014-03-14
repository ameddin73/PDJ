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

#define FIREBALL_SIZE 32

enum tile {
    tile_floor,
    tile_single,
    tile_internal,
    tile_pipe_vert,
    tile_pipe_whore,
    tile_wall_westface,
    tile_wall_northface,
    tile_wall_eastface,
    tile_wall_southface,
    tile_cap_west,
    tile_cap_north,
    tile_cap_east,
    tile_cap_south,
    tile_wall_southwest,
    tile_wall_southeast,
    tile_wall_northwest,
    tile_wall_northeast,
    tile_corner_southwest,
    tile_corner_northwest,
    tile_corner_northeast,
    tile_corner_southeast,
    tile_attachcorner_southwest,
    tile_attachcorner_northwest,
    tile_attachcorner_northeast,
    tile_attachcorner_southeast
};

enum direction {
    dir_left,
    dir_right,
    dir_up,
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
