#include "game/game-state.hpp"

Game_state::Game_state(sf::RenderWindow *window) : State(window)
{
    player = new Player(0, 0);
    wall = new Wall(4, 4);
    npc_leandro = new Npc("Leandro", 2, 3, "resources/leandro.txt");
    npc_edinho = new Npc("Edinho", 5, 5, "resources/edinho.txt");

    timer = new Timer;

    carrot = new Item("Carrot", 6, 6);
}

Game_state::~Game_state()
{
    delete timer;
    delete player;
    delete wall;
    delete npc_leandro;
    delete npc_edinho;

    std::cout << "Estado de jogo deletado" << std::endl;
}

void Game_state::update(const float &delta_time)
{
    this->update_inputs(delta_time);
    this->player->instance_update(delta_time);
    carrot->instance_update(delta_time);

    if (timer->timer_update() == 110)
    {
        // quit_state = true;
    }
}

void Game_state::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }

    this->player->instance_draw(target);
    this->wall->instance_draw(target);
    this->npc_leandro->instance_draw(target);
    this->npc_edinho->instance_draw(target);

    // this->timer->hud_draw(target);

    this->carrot->instance_draw(target);

    // if (npc_leandro->get_npc_dialogue()->Pode == true)
    this->npc_leandro->get_npc_dialogue()->dialogue_draw(target);

    // if (npc_edinho->get_npc_dialogue()->Pode == true)
    this->npc_edinho->get_npc_dialogue()->dialogue_draw(target);
}

void Game_state::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void Game_state::update_events(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (player->uptade_event_player(event) == true)
        {
            npc_leandro->get_npc_dialogue()->uptade_event_dialogue(player->z, player->x, player->space);
            npc_edinho->get_npc_dialogue()->uptade_event_dialogue(player->z, player->x, player->space);
        }
    }
}

void Game_state::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}