// 
// File: printer.cpp 
// 
// 
// 
// @author douglas: Douglas Moyer
// 
// // // // // // // // // // // // // // // // // // // // // // // // 

#include "printer.h"
#include <iostream>

printer::printer(vector<quest> *quests, character *player, int *current_quest) {
    quests_ = quests;
    player_ = player;
    current_quest_ = current_quest;
    tile_clips_[TILE_FLOOR].x = 0;
    tile_clips_[TILE_FLOOR].y = 0;
    tile_clips_[TILE_FLOOR].w = TILE_SIZE;
    tile_clips_[TILE_FLOOR].h = TILE_SIZE;
    tile_clips_[TILE_WALL].x = 40;
    tile_clips_[TILE_WALL].y = 0;
    tile_clips_[TILE_WALL].w = TILE_SIZE;
    tile_clips_[TILE_WALL].h = TILE_SIZE;
    sprite_clips_[0][0].x = 40;
    sprite_clips_[0][0].y = 00;
    sprite_clips_[0][0].w = PLAYER_SIZE;
    sprite_clips_[0][0].h = PLAYER_SIZE;
    camera_.x = (player_->x() + PLAYER_SIZE / 2) - WINDOW_WIDTH / 2;
    camera_.y = (player_->y() + PLAYER_SIZE / 2) - WINDOW_HEIGHT / 2;
    camera_.w = WINDOW_WIDTH;
    camera_.h = WINDOW_HEIGHT;
}

bool printer::init() {
    bool success = true;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        cout << "SDL could not initialize! Error: " << SDL_GetError() << "\n";
        success = false;
    } else {
        if (!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1"))
            cout << "VSyinc not enabled!\n";
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
            cout << "Linear texture filtering not enabled!\n";
            
        window_ = SDL_CreateWindow("Procedural Death Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (window_ == NULL ) {
            cout << "Window could not be created! Error: " << SDL_GetError() << "\n";
            success = false;
        } else {
            renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
            if(renderer_ == NULL) {
                cout << "Renderer could not be created! Error: " << SDL_GetError() << "\n";
                success = false;
            } else {
                SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
                
                tiles_.set_renderer(renderer_);
                sprites_.set_renderer(renderer_);
                
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags)) {
                    cout << "SDL could not initialize! image Error: " << IMG_GetError() << "\n";
                    success = false;
                }
            }
        }
    }
    return success;
}

bool printer::load_media() {
    bool success = true;
    if(!tiles_.load_from_file("tiles.png")) {
        cout << "Can't load tileset!\n";
        success = false;
    }
    if(!sprites_.load_from_file("tiles.png")) {
        cout << "Can't load sprites!\n";
        success = false;
    } 
    return success;
}

void printer::update() {
    Uint32 ticks = get_ticks();
    camera_.x = (player_->x() + PLAYER_SIZE / 2) - WINDOW_WIDTH / 2;
    camera_.y = (player_->y() + PLAYER_SIZE / 2) - WINDOW_HEIGHT / 2;
    if(camera_.x < 0) camera_.x = 0;
    if(camera_.y < 0) camera_.y = 0;
    if(camera_.x > LEVEL_WIDTH - camera_.w) camera_.x = LEVEL_WIDTH - camera_.w;
    if(camera_.y > LEVEL_HEIGHT - camera_.h) camera_.y = LEVEL_HEIGHT - camera_.h;
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer_);
    ticks = get_ticks();
    int terr;
	for (int i = ((camera_.y) % TILE_SIZE)0; i < ((camera_.x + camara.h) % TILE_SIZE); i++) {
		for (int j = ((camera_.x) % TILE_SIZE); j < ((camera_.x + camara.w) % TILE_SIZE); j++) {
            SDL_Rect render_quad = {j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE};
            if(check_collision(camera_, render_quad)) {
                render_quad.x -= camera_.x;
                render_quad.y -= camera_.y;
                terr = (*quests_)[*current_quest_].curr_floor()->terrain_at(i, j);
                SDL_RenderCopyEx(renderer_, tiles_.texture(), &tile_clips_[terr], &render_quad, 0.0, NULL, SDL_FLIP_NONE);
            }
        }
    }
    cout << "For loop: " << get_ticks() - ticks << " ticks\n";
    SDL_Rect player_render = {player_->x() - camera_.x, player_->y() - camera_.y, PLAYER_SIZE, PLAYER_SIZE};

    SDL_RenderCopyEx(renderer_, sprites_.texture(), &sprite_clips_[0][0], &player_render, 0.0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(renderer_);
}

bool printer::check_collision(SDL_Rect a, SDL_Rect b) {
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB ) return false;
    if( topA >= bottomB ) return false;
    if( rightA <= leftB ) return false;
    if( leftA >= rightB ) return false;
    //If none of the sides from A are outside B
    return true;
}
int printer::poll_event(SDL_Event *e) { return SDL_PollEvent(e); }

void printer::close() {
    tiles_.free();
    sprites_.free();
    
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    window_ = NULL;
    renderer_ = NULL;
    
    IMG_Quit();
    SDL_Quit();
}

Uint32 printer::get_ticks() { return SDL_GetTicks(); }

load_texture::load_texture(){
    texture_ = NULL;
    width_ = 0;
    height_ = 0;
}

load_texture::~load_texture() {
    free();
}

bool load_texture::load_from_file(string path) {
    free();
    SDL_Texture* new_texture = NULL;
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == NULL)
        cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << "\n";
    else {
        SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB( loaded_surface->format, 0, 0xFF, 0xFF));
        new_texture = SDL_CreateTextureFromSurface( renderer_, loaded_surface);
        if (new_texture == NULL)
            cout << "Unable to load image " << path << "! SDL Error: " << SDL_GetError() << "\n";
        else {
            width_ = loaded_surface->w;
            height_ = loaded_surface->h;
        }
        SDL_FreeSurface(loaded_surface);
    }
    texture_ = new_texture;
    return texture_ != NULL;
}

// bool load_texture::load_from_rendered_text(string text, SDL_Color color){}

void load_texture::free(){
    if(texture_ != NULL) {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
        width_ = 0;
        height_ = 0;
    }
}

void load_texture::set_color( Uint8 red, Uint8 green, Uint8 blue){
    SDL_SetTextureColorMod(texture_, red, green, blue);
}

void load_texture::set_blend_mode( SDL_BlendMode blending ){
    SDL_SetTextureBlendMode(texture_, blending);
}

void load_texture::set_alpha(Uint8 alpha){
    SDL_SetTextureAlphaMod(texture_, alpha);
}

void load_texture::set_renderer(SDL_Renderer* renderer) {
    renderer_ = renderer;
}

int load_texture::width(){
    return width_;
}

int load_texture::height(){
    return height_;
}

SDL_Texture* load_texture::texture(){
    return texture_;
}



// // // // // // // // // // // // // // // // // // // // // // // // 
// Version: 
// $Id$ 
// 
// Revisions: 
// $Log$ 
// 
