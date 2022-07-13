#include "game/game-state.hpp"

GameState::GameState(sf::RenderWindow *window,std::stack<State *>* states) : State(window,states)
{
    player = new Player(0, 0);
    wall = new Wall(4, 4);
    npc_leandro = new Npc("Leandro", 2, 3, "resources/leandro.txt");
    npc_edinho = new Npc("Edinho", 5, 5, "resources/edinho.txt");
    npc_edinho2 = new Npc("Edinho", 5, 5, "resources/edinho_item.txt");

    timer = new Timer;

    carrot = new Item("Carrot", 1, 3, 0);

    // carrot2 = new Item("Carrot", 5, 6, 1);
}

GameState::~GameState()
{
    delete timer;
    delete player;
    delete wall;
    delete npc_leandro;

    std::cout << "Estado de jogo deletado" << std::endl;
}

void GameState::update(const float &delta_time)
{
    this->update_inputs(delta_time);
    this->player->instance_update(delta_time);
    carrot->instance_update(delta_time);

    if (timer->timer_update() == 110)
    {
        // quit_state = true;
    }

    if (carrot->get_holding() == true)
    {
        npc_edinho->npc_collision->disable_collision();
        if (npc_edinho2->get_npc_dialogue()->given == false)
        {
            carrot->set_given(false);
        }
        if (npc_edinho2->get_npc_dialogue()->given == true)
        {
            carrot->set_given(true);
        }
    }
}

void GameState::draw(sf::RenderTarget *target)
{
    if (!target)
    {
        target = this->window;
    }

    this->player->instance_draw(target);
    this->wall->instance_draw(target);
    this->npc_leandro->instance_draw(target);

    this->npc_edinho->instance_draw(target);

    this->npc_edinho2->instance_draw(target);

    // this->timer->hud_draw(target);

    this->carrot->instance_draw(target);

    this->npc_leandro->get_npc_dialogue()->dialogue_draw(target);

    this->npc_edinho->get_npc_dialogue()->dialogue_draw(target);

    this->npc_edinho2->get_npc_dialogue()->dialogue_draw(target);
}

void GameState::update_inputs(const float &delta_time)
{
    this->kb_check_for_quit();
}

void GameState::update_events(sf::Event event)
{
    Instance *object_collidable = player->player_colision->get_collision(player->next_tile);

    if (event.type == sf::Event::KeyPressed)
    {
        if ((player->uptade_event_player(event) == true))
            if (!object_collidable->instanceof <Item>(object_collidable))
            {
                npc_leandro->get_npc_dialogue()->update_event_dialogue(player->z, player->x, player->space);

                npc_edinho->get_npc_dialogue()->update_event_dialogue(player->z, player->x, player->space);

                npc_edinho2->get_npc_dialogue()->update_event_dialogue(player->z, player->x, player->space);
            }
    }
}

void GameState::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}
