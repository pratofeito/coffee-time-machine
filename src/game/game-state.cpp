#include "game/game-state.hpp"

GameState::GameState(sf::RenderWindow *window, std::stack<State *> *states) : State(window, states)
{

    // criação do mapa
    map_floor = new Background("resources/sprites/maps/main_room.png", "resources/maps/main_room_floor.csv", sf::Vector2i(0, 0));
    map_chairs = new Background("resources/sprites/maps/main_room.png", "resources/maps/main_room_chairs.csv", sf::Vector2i(0, 0));
    map_tables = new Background("resources/sprites/maps/main_room.png", "resources/maps/main_room_tables.csv", sf::Vector2i(0, 0));
    map_obj = new Background("resources/sprites/maps/main_room.png", "resources/maps/main_room_obj.csv", sf::Vector2i(0, 0));

    // criação do player
    player = new Player(0, 0);

    // criação das paredes
    wall = new Wall(15, 10);
    generate_walls("resources/maps/main_room_walls.csv");

    // criação dos npcs
    npc_blue = new Npc("Leandro", 9, 10, "resources/dialogues/leandro.txt");
    npc_blue_clone = new Npc("Leandro", 9, 10, "resources/dialogues/leandro_item.txt");
    npc_edinho = new Npc("Edinho", 5, 10, "resources/dialogues/edinho.txt");
    npc_edinho2 = new Npc("Edinho", 5, 10, "resources/dialogues/edinho_item.txt");

    npc_blue->set_looking(LEFT);

    npc_blue->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-blue/npc_blue_idle_up.png");
    npc_blue->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-blue/npc_blue_idle_down.png");
    npc_blue->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    npc_blue->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-blue/npc_blue_idle_right.png");

    npc_blue_clone->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-blue/npc_blue_idle_up.png");
    npc_blue_clone->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-blue/npc_blue_idle_down.png");
    npc_blue_clone->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    npc_blue_clone->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-blue/npc_blue_idle_right.png");

    timer = new Timer;

    carrot = new Item("Carrot", 5, 7, 0);
    carrot2 = new Item("Carrot 2", 10, 7, 1);

    // audio
    game_soundtrack = new Audio();
    game_soundtrack->define_music("resources/audio/the_space_is_home.ogg", 60);
    game_soundtrack->play_music();
}

GameState::~GameState()
{
    delete timer;
    delete player;
    delete wall;

    // deleto o background do mapa criado no início
    delete map_floor;
    delete map_chairs;
    delete map_tables;
    delete map_obj;

    delete game_soundtrack;

    std::cout << "Estado de jogo deletado" << std::endl;
}

void GameState::update(const float &delta_time)
{
    this->update_inputs(delta_time);
    this->player->instance_update(delta_time);

    this->npc_blue->instance_update(delta_time);
    this->npc_blue_clone->instance_update(delta_time);
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

    // desenha primeiras partes do mapa
    map_floor->draw(window);
    map_chairs->draw(window);
    map_tables->draw(window);

    this->player->instance_draw(target);
    this->wall->instance_draw(target);
    
    // desenha walls
    for (auto wall : walls)
    {
        wall->instance_draw(target);
    }

// Verificar problema
    if (player->bag["Carrot 2"] == true)
    {
        if (npc_blue->cloned == false)
        {
            npc_blue_clone->set_looking(npc_blue->get_looking());
        }
        npc_blue->cloned = true;
        this->npc_blue_clone->instance_draw(target); //
    }
    else
    {
        this->npc_blue->instance_draw(target);
    }

    this->npc_edinho->instance_draw(target);
    this->npc_edinho2->instance_draw(target);

    // this->timer->hud_draw(target);

    this->carrot->instance_draw(target);
    this->carrot2->instance_draw(target); //

    this->npc_blue->get_npc_dialogue()->dialogue_draw(target);
    this->npc_blue_clone->get_npc_dialogue()->dialogue_draw(target);

    this->npc_edinho->get_npc_dialogue()->dialogue_draw(target);
    this->npc_edinho2->get_npc_dialogue()->dialogue_draw(target);

    // objetos em cima do mapa
    map_obj->draw(window);
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

        std::cout << "entrei em coiso estranho" << std::endl;

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
        std::cout << "primeiro if" << std::endl;
        if ((object_collidable == npc_blue) || (object_collidable == npc_blue_clone))
        {
            npc_blue->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_blue_clone->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (carrot2->get_holding() == true)
            {
                npc_blue->npc_collision->disable_collision();
                if (npc_blue_clone->get_npc_dialogue()->given == false)
                {
                    carrot2->set_given(false);
                }
                if (npc_blue_clone->get_npc_dialogue()->given == true)
                {
                    carrot2->set_given(true);
                }
            }
        }
        std::cout << "segundo if" << std::endl;
    }
}

void GameState::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}

void GameState::generate_walls(std::string walls_dir)
{
    sf::Vector2i positionset_wall (0, 0);
    std::vector<int> walls_index;
    walls_file = std::ifstream(walls_dir);
    std::string line;

    while (std::getline(walls_file, line))
    {
        positionset_wall.y++;
        std::stringstream original_string(line);
        std::string parte;
        while (std::getline(original_string, parte, ','))
        {
            positionset_wall.x++;
            walls_index.push_back(stoi(parte));
        }
    }

    // remove as redundancias
    positionset_wall.x /= positionset_wall.y;

    // define a posição absoluta de cada sprite
    int index = 0;
    for (int i = 0; i < positionset_wall.y; i++)
    {
        for (int j = 0; j < positionset_wall.x; j++)
        {
            if (walls_index[index] == 0)
            {
                Wall *new_wall = new Wall(j, i);
                walls.push_back(new_wall);
            }
            index++;
        }
    }
}
