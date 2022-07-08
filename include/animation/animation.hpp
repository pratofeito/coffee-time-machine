#ifndef ANIMATION_CPP
#define ANIMATION_CPP

#include "sprite-set/sprite-set.hpp"
#include "instances/instance.hpp"

class Animation {

    private:

        Instance *instance;
        SpriteSet *sprite_vec;
        sf::Sprite current_sprite;
        float delta_time;

        std::map<sf::Vector2i, SpriteSet*> sprites_collection;

    public:

        Animation(Instance *instance);
        virtual ~Animation();

        void new_state(int state, int direction, std::string tileset_dir);
        void update(int player_state, int looking, float delta_time);
        sf::Sprite* get_sprite();

};

#endif