#include "animation/animation.hpp"

Animation::Animation(Instance *instance) {
    this->instance = instance;
    this->delta_time = 0;
}

Animation::~Animation() {
    // delete sprite_vec;
}


// O ERRO ESTÁ ENTRE A LINHA 17 E 22 !!!!
void Animation::new_state(int state, int direction, std::string tileset_dir) {
    // sprite_vec = new SpriteSet(tileset_dir);
    // SpriteSet spr (tileset_dir);
    sprite_vec = new SpriteSet(tileset_dir);
    sf::Vector2i vec (state, direction);
    sprites_collection.insert({vec, sprite_vec});
    // this->current_sprite = 

    sf::Vector2i oiw (0, 3);
    // current_sprite = *sprites_collection[oiw]->sprites_map[0];
}

void Animation::update(int player_state, int looking, float delta_time) {

    int index = 0;

    // switch (looking) {
    //     case 0:
    //         /* code */
    //         break;
    //     case 1:
    //         /* code */
    //         break;        
    // }

    if (player_state == 0) {
        this->delta_time += delta_time;
        if (this->delta_time >= 0.15){
            index = 1;
        }
        if (this->delta_time >= 0.3){
            index = 0;
            this->delta_time = 0;
        }
    } else {
        this->delta_time = 0;
    }  

    // current_sprite = *sprite_vec->sprites_map[index];
    // sf::Vector2i dir_vec (0, 3);
    // current_sprite = *sprites_collection[dir_vec]->sprites_map[index];
}

sf::Sprite* Animation::get_sprite() {
    return &this->current_sprite;
}