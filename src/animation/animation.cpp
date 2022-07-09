#include "animation/animation.hpp"

Animation::Animation(Instance *instance) {
    this->instance = instance;
    this->delta_time = 0;
    this->past_state = -1;
    this->animation_time = 0.15;
}

Animation::~Animation() {
    delete sprite_vec;
}


void Animation::new_state(int state, int direction, std::string tileset_dir) {
    sprite_vec = new SpriteSet(tileset_dir);
    std::vector<int> vec ({state, direction});
    sprites_collection.insert({vec, sprite_vec});
}

// isso aqui precisa urgentemente de um try_catch
// se ele tenta definir uma sprite que nao existe, simplesmente falha de segmentação
void Animation::update(int player_state, int looking, float delta_time) {

    // evita que se uma da opções nao exista na lista, nao dê falha de segmentação
    if (player_state == 2) {
        looking = NULL;
    }

    int index = 0;
    int sprites_collection_size = sprites_collection[{player_state, looking}]->sprites_map.size();
    std::cout << "sprites_collection_size: " << sprites_collection_size << std::endl;

    if (this->past_state == player_state) {
        this->delta_time += delta_time;
        if (this->delta_time >= animation_time) {
            index++;
            if (index >= sprites_collection_size){
                this->delta_time = 0;
                index = 0;
            }
        }
    } else {
        this->past_state = player_state;
        this->delta_time = 0;
    }
 
    current_sprite = *sprites_collection[{player_state, looking}]->sprites_map[index];
    
}

sf::Sprite* Animation::get_sprite() {
    return &this->current_sprite;
}