#include "animation/animation.hpp"

Animation::Animation(Instance *instance)
{
    this->instance = instance;
    this->delta_time = 0;
    this->past_state = -1;
    this->animation_time = FRAME_TIME;
    index = 0;
}

Animation::~Animation()
{
    delete sprite_vec;
}

void Animation::new_state(int state, std::string tileset_dir)
{
    this->new_state(state, NO_DIRECTION, tileset_dir);
}

void Animation::new_state(int state, int direction, std::string tileset_dir)
{
    sprite_vec = new SpriteSet(tileset_dir);
    std::vector<int> iterator_vector;

    if (direction == NO_DIRECTION)
    {
        iterator_vector = std::vector<int>({state});
    }
    else
    {
        iterator_vector = std::vector<int>({state, direction});
    }

    sprites_collection.insert({iterator_vector, sprite_vec});
}

// o fato de se utilizar tamanhos diferentes no vector das keys do map faz a necessidade de se incluir
// mais ifs. uma forma de otimização desta classe é fazer tudo trabalhar padronizado.
void Animation::update(int player_state, int looking, float delta_time)
{
    bool has_sprite = false;

    // verificar se o vetor key de player state tem apenas um registro (significa que não tem direção)
    for (auto sprite : sprites_collection)
    {
        if ((sprite.first[0]) == player_state)
        {
            has_sprite = true;
            if (sprite.first.size() == 1)
            {
                looking = NO_DIRECTION;
            }
            break;
        }
    }

    if (has_sprite)
    {
        int sprites_collection_size = 0;

        if (looking == NO_DIRECTION)
        {
            sprites_collection_size = sprites_collection[{player_state}]->sprites_map.size();
        }
        else
        {
            sprites_collection_size = sprites_collection[{player_state, looking}]->sprites_map.size();
        }

        if (this->past_state == player_state)
        {
            this->delta_time += delta_time;

            if (this->delta_time >= animation_time)
            {
                index++;
                this->delta_time = 0;
                if (index >= sprites_collection_size)
                {
                    index = 0;
                }
            }
        }
        else
        {
            this->past_state = player_state;
            this->delta_time = 0;
            index = 0;
        }

        if (looking == NO_DIRECTION)
        {
            current_sprite = *sprites_collection[{player_state}]->sprites_map[index];
        }
        else
        {
            current_sprite = *sprites_collection[{player_state, looking}]->sprites_map[index];
        }
    }
}

sf::Sprite *Animation::get_sprite()
{
    return &this->current_sprite;
}