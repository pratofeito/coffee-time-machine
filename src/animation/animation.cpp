#include "animation/animation.hpp"

Animation::Animation(Instance *instance) {
    this->instance = instance;
    this->delta_time = 0;
}

Animation::~Animation() {
    delete sprite_vec;
}

void Animation::new_state(int state, std::string tileset_dir) {
    sprite_vec = new SpriteSet(tileset_dir);
}

void Animation::update(int player_state, int looking, float delta_time) {

    int index = 0;

    switch (looking) {
        case 0:
            /* code */
            break;
        case 1:
            /* code */
            break;        
    }

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

    current_sprite = *sprite_vec->sprites_map[index];
}

sf::Sprite* Animation::get_sprite() {
    return &this->current_sprite;
}