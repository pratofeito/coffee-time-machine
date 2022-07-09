/**
 * @file animation.hpp
 * @author pinguim
 * @brief gerencia a animação de cada isntância, recebendo como configuração um estado e direção, junto com o caminho
 * para algum arquivo de texturas. quando chamado update() utiliza dessas informações para percorrer uma animação, desenhando
 * a sprite correta para cada estágio.
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ANIMATION_CPP
#define ANIMATION_CPP

#include <map>
#include "sprite-set/sprite-set.hpp"
#include "instances/instance.hpp"

#define FRAME_TIME 0.2

class Animation
{

private:
    const int NO_DIRECTION = -1;
    Instance *instance;
    SpriteSet *sprite_vec;
    sf::Sprite current_sprite;
    float delta_time;
    float animation_time;
    int past_state;
    int index;

    std::map<std::vector<int>, SpriteSet *> sprites_collection;

public:
    Animation(Instance *instance);
    virtual ~Animation();

    void new_state(int state, std::string tileset_dir);
    void new_state(int state, int direction, std::string tileset_dir);
    void update(int player_state, int looking, float delta_time);
    sf::Sprite *get_sprite();
};

#endif