#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "game/state.hpp"
#include "sprite-set/background.hpp"
#include "audio/audio.hpp"

class GameState : public State
{
private:
    enum directions
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    enum states
    {
        MOVING,
        INTERACTING,
        NOTHING
    };

    // Background
    Background *map_floor;
    Background *map_chairs;
    Background *map_tables;
    Background *map_obj;

    // Elementos de Game
    Player *player;

    // Blue
    Npc *npc_blue;
    Npc *npc_blue_clone;
    // Pink
    Npc *npc_pink;
    Npc *npc_pink_clone;
    // Cian
    Npc *npc_cyan;
    Npc *npc_cyan_clone;
    // Yellow
    Npc *npc_yellow;
    Npc *npc_yellow_clone;

    // Jitsi
    Npc *npc_jitsi_intro;
    Npc *npc_jitsi_complete;

    std::vector<Wall *> walls;
    std::ifstream walls_file;

    Timer *timer;

    Item *coffee;
    Item *chocolate;
    Item *penguin;
    Item *camera;

    void generate_walls(std::string walls_dir);

    // audio
    Audio *game_soundtrack;

public:
    GameState(sf::RenderWindow *window, std::stack<State *> *states);
    virtual ~GameState();

    void init_npcs();
    void update(const float &delta_time) override;
    void update_inputs(const float &delta_time) override;
    void update_events(sf::Event event) override;

    void draw(sf::RenderTarget *target = nullptr) override;

    void end_state() override;
};

#endif