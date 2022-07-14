#include "game/game-state.hpp"

GameState::GameState(sf::RenderWindow *window,std::stack<State *>* states) : State(window,states)
{
    player = new Player(0, 0);
    wall = new Wall(15, 10);
    npc_leandro = new Npc("Leandro", 10, 10, "resources/dialogues/leandro.txt");
    npc_leandro2 = new Npc("Leandro", 10, 10, "resources/dialogues/leandro_item.txt");
    npc_edinho = new Npc("Edinho", 5, 10, "resources/dialogues/edinho.txt");
    npc_edinho2 = new Npc("Edinho", 5, 10, "resources/dialogues/edinho_item.txt");

    npc_leandro->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-blue/npc_blue_idle_up.png");
    npc_leandro->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-blue/npc_blue_idle_down.png");
    npc_leandro->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    npc_leandro->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-blue/npc_blue_idle_right.png");

    npc_leandro2->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-blue/npc_blue_idle_up.png");
    npc_leandro2->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-blue/npc_blue_idle_down.png");
    npc_leandro2->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    npc_leandro2->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-blue/npc_blue_idle_right.png");

    timer = new Timer;

    carrot = new Item("Carrot", 5, 7, 0);
    carrot2 = new Item("Carrot 2", 10, 7, 1);
}

GameState::~GameState()
{
    delete timer;
    delete player;
    delete wall;

    std::cout << "Estado de jogo deletado" << std::endl;
}

void GameState::update(const float &delta_time)
{
    this->update_inputs(delta_time);
    this->player->instance_update(delta_time);

    this->npc_leandro->instance_update(delta_time);
    this->npc_leandro2->instance_update(delta_time);
    this->npc_edinho->instance_update(delta_time);
    this->npc_edinho2->instance_update(delta_time);

    carrot->instance_update(delta_time);
    carrot2->instance_update(delta_time);

    if (timer->timer_update() == 110)
    {
        // quit_state = true;
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
    this->npc_leandro2->instance_draw(target); //

    this->npc_edinho->instance_draw(target);
    this->npc_edinho2->instance_draw(target);

    // this->timer->hud_draw(target);

    this->carrot->instance_draw(target);
    this->carrot2->instance_draw(target); //

    this->npc_leandro->get_npc_dialogue()->dialogue_draw(target);
    this->npc_leandro2->get_npc_dialogue()->dialogue_draw(target);

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
        player->uptade_event_player(event);

        if ((object_collidable == npc_edinho) || (object_collidable == npc_edinho2))
        {
            npc_edinho->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_edinho2->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
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
        if ((object_collidable == npc_leandro) || (object_collidable == npc_leandro2))
        {
            npc_leandro->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_leandro2->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (carrot2->get_holding() == true)
            {
                npc_leandro->npc_collision->disable_collision();
                if (npc_leandro2->get_npc_dialogue()->given == false)
                {
                    carrot2->set_given(false);
                }
                if (npc_leandro2->get_npc_dialogue()->given == true)
                {
                    carrot2->set_given(true);
                }
            }
        }
    }
}

void GameState::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}
