#ifndef ANIMATION_CPP
#define ANIMATION_CPP

#include <map>
#include "sprite-set/sprite-set.hpp"
#include "instances/instance.hpp"

class Animation {

    private:

        const int NONE = 0;
        Instance *instance;
        SpriteSet *sprite_vec;
        sf::Sprite current_sprite;
        float delta_time;
        float animation_time;
        int past_state;

        std::map<std::vector<int>, SpriteSet*> sprites_collection;

    public:

        Animation(Instance *instance);
        virtual ~Animation();

        void new_state(int state, int direction, std::string tileset_dir);
        void update(int player_state, int looking, float delta_time);
        sf::Sprite* get_sprite();


};

#endif