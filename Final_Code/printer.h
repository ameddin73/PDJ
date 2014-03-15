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

// add include files only if needed for these declarations.
#include "define.h"
#include "quest.h"
#include "character.h"
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

#define TOTAL_TILES (FLOOR_HEIGHT * FLOOR_WIDTH)

#define TOTAL_SPRITES 4
#define ANIMATION_FRAMES 4 
/*#define TOTAL_TILE_SPRITES = 15


enum tiles {
    TILE_FLOOR,
    TILE_N_WALL,
    TILE_NE_WALL,
    TILE_E_WALL,
    TILE_SE_WALL,
    TILE_S_WALL,
    TILE_SW_WALL,
    TILE_W_WALL,
    TILE_NW_WALL,
    TILE_N_JUT,
    TILE_E_JUT,
    TILE_S_JUT,
    TILE_W_JUT,
    TILE_WALL };*/
    
#define TOTAL_TILE_SPRITES 39 

enum tiles {
    TILE_FLOOR,
    TILE_WALL };


// Printer will hold the spritesheet, and a clipping array for
// entity/animation state
enum sprites {
    SPRITE_PLAYER
};
/// @author douglas: TODO_AUTHOR_FULL_NAME_
///

// This code heavily borrowed from Lazy Foo' Productions [ http://lazyfoo.net/ ]

class load_texture {
    public:
        load_texture();
        ~load_texture();
        bool load_from_file(string path);
        // bool load_from_rendered_text(string text, SDL_Color color);
        void free();
        void set_color( Uint8 red, Uint8 green, Uint8 blue);
        void set_blend_mode( SDL_BlendMode blending );
        void set_alpha(Uint8 alpha);
        void set_renderer(SDL_Renderer* renderer);
        int width();
        int height();
        SDL_Texture* texture();
        SDL_Renderer* renderer_ = NULL;
    private:
        SDL_Texture* texture_;
        int width_;
        int height_;
};

class printer {
    private:
        //quest *quests_;
        vector<quest> *quests_;
        vector<character> *fireballs_;
        character *player_;
        int *current_quest_;
        SDL_Window* window_ = NULL;
        SDL_Renderer* renderer_ = NULL;
        load_texture tiles_;
        load_texture sprites_;
        load_texture overlay_;
        load_texture fireball_;
        SDL_Rect tile_clips_[TOTAL_TILE_SPRITES];
        SDL_Rect sprite_clips_[TOTAL_SPRITES][ANIMATION_FRAMES];
        SDL_Rect camera_;
    public:
        printer(vector<quest> *quests, character *player, int *current_quest, vector<character> *fireballs);
        bool init();
        bool load_media();
        int poll_event(SDL_Event *e);
        void update();
        void close();
        bool check_collision(SDL_Rect a, SDL_Rect b);
        Uint32 get_ticks();
};


        
#endif // PRINTER_H

// // // // // // // // // // // // // // // // // // // // // // // // 
// 
// Revisions: 
//     $Log$ 
// 
