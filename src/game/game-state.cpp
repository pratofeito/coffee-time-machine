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
    generate_walls("resources/maps/main_room_walls.csv");

    // inicializa os npcs
    init_npcs();

    timer = new Timer;

    coffee = new Item("Coffee", 19, 7, 0);
    chocolate = new Item("Chocolate", 10, 7, 1);
    penguin = new Item("Penguin", 7, 12, 2);
    camera = new Item("Camera", 7, 7, 3);

    // audio
    game_soundtrack = new Audio();
    game_soundtrack->define_music("resources/audio/the_space_is_home.ogg", 60);
    game_soundtrack->play_music();
}

GameState::~GameState()
{
    delete timer;
    delete player;

    // deleto o background do mapa criado no início
    delete map_floor;
    delete map_chairs;
    delete map_tables;
    delete map_obj;
    for (auto wall : walls)
    {
        delete wall;
    }

    delete game_soundtrack;

    std::cout << "Estado de jogo deletado" << std::endl;
}
void GameState::init_npcs()
{
    // Criação dos npcs
    // Blue
    npc_blue = new Npc("Blue", 9, 10, "resources/dialogues/blue.txt");
    npc_blue_clone = new Npc("Blue", 9, 10, "resources/dialogues/blue_item.txt");
    // Pink
    npc_pink = new Npc("Pink", 20, 6, "resources/dialogues/pink.txt");
    npc_pink_clone = new Npc("Pink", 20, 6, "resources/dialogues/pink_item.txt");
    // Yellow
    npc_yellow = new Npc("Yellow", 5, 5, "resources/dialogues/yellow.txt");
    npc_yellow_clone = new Npc("Yellow", 5, 5, "resources/dialogues/yellow_item.txt");
    // cyan
    npc_cyan = new Npc("Cyan", 15, 7, "resources/dialogues/cyan.txt");
    npc_cyan_clone = new Npc("Cyan", 15, 7, "resources/dialogues/cyan_item.txt");
    // Jitsi
    npc_jitsi_intro = new Npc("Jitsi Intro", 12, 3, "resources/dialogues/jitsi_intro.txt");
    npc_jitsi_complete = new Npc("Jitsi Complete", 12, 3, "resources/dialogues/jitsi_complete.txt");

    // Blue
    npc_blue->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-blue/npc_blue_idle_up.png");
    npc_blue->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-blue/npc_blue_idle_down.png");
    npc_blue->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    npc_blue->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-blue/npc_blue_idle_right.png");

    npc_blue_clone->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-blue/npc_blue_idle_up.png");
    npc_blue_clone->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-blue/npc_blue_idle_down.png");
    npc_blue_clone->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-blue/npc_blue_idle_left.png");
    npc_blue_clone->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-blue/npc_blue_idle_right.png");
    npc_blue->set_looking(LEFT);

    // Pink
    npc_pink->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-pink/npc_pink_idle_up.png");
    npc_pink->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-pink/npc_pink_idle_down.png");
    npc_pink->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-pink/npc_pink_idle_left.png");
    npc_pink->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-pink/npc_pink_idle_right.png");

    npc_pink_clone->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-pink/npc_pink_idle_up.png");
    npc_pink_clone->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-pink/npc_pink_idle_down.png");
    npc_pink_clone->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-pink/npc_pink_idle_left.png");
    npc_pink_clone->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-pink/npc_pink_idle_right.png");
    npc_pink->set_looking(UP);

    // Yellow
    npc_yellow->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_up.png");
    npc_yellow->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_down.png");
    npc_yellow->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_left.png");
    npc_yellow->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_right.png");

    npc_yellow_clone->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_up.png");
    npc_yellow_clone->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_down.png");
    npc_yellow_clone->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_left.png");
    npc_yellow_clone->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-yellow/npc_yellow_idle_right.png");
    npc_yellow->set_looking(UP);

    // cyan
    npc_cyan->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_up.png");
    npc_cyan->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_down.png");
    npc_cyan->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_left.png");
    npc_cyan->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_right.png");

    npc_cyan_clone->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_up.png");
    npc_cyan_clone->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_down.png");
    npc_cyan_clone->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_left.png");
    npc_cyan_clone->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-cyan/npc_cyan_idle_right.png");
    npc_cyan->set_looking(RIGHT);

    // Jitsi
    npc_jitsi_intro->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-jitsi/jitsi_idle_up.png");
    npc_jitsi_intro->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-jitsi/jitsi_idle_down.png");
    npc_jitsi_intro->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-jitsi/jitsi_idle_left.png");
    npc_jitsi_intro->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-jitsi/jitsi_idle_right.png");

    npc_jitsi_complete->npc_animation->new_state(NOTHING, UP, "resources/sprites/npcs/npc-jitsi/jitsi_idle_up.png");
    npc_jitsi_complete->npc_animation->new_state(NOTHING, DOWN, "resources/sprites/npcs/npc-jitsi/jitsi_idle_down.png");
    npc_jitsi_complete->npc_animation->new_state(NOTHING, LEFT, "resources/sprites/npcs/npc-jitsi/jitsi_idle_left.png");
    npc_jitsi_complete->npc_animation->new_state(NOTHING, RIGHT, "resources/sprites/npcs/npc-jitsi/jitsi_idle_right.png");

    npc_jitsi_intro->set_looking(DOWN);
}

void GameState::update(const float &delta_time)
{
    this->update_inputs(delta_time);
    this->player->instance_update(delta_time);

    this->npc_blue->instance_update(delta_time);
    this->npc_blue_clone->instance_update(delta_time);
    this->npc_pink->instance_update(delta_time);
    this->npc_pink_clone->instance_update(delta_time);
    this->npc_cyan->instance_update(delta_time);
    this->npc_cyan_clone->instance_update(delta_time);
    this->npc_yellow->instance_update(delta_time);
    this->npc_yellow_clone->instance_update(delta_time);
    this->npc_jitsi_intro->instance_update(delta_time);
    this->npc_jitsi_complete->instance_update(delta_time);

    coffee->instance_update(delta_time);
    chocolate->instance_update(delta_time);

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

    // desenha walls
    for (auto wall : walls)
    {
        wall->instance_draw(target);
    }

    // Desenha os NPCs

    // PINK
    if (player->bag["Chocolate"] == true)
    {
        if (npc_pink->cloned == false)
        {
            npc_pink_clone->set_looking(npc_pink->get_looking());
        }
        npc_pink->cloned = true;
        this->npc_pink_clone->instance_draw(target); //
    }
    else
    {
        this->npc_pink->instance_draw(target);
    }

    // BLUE
    if (player->bag["Coffee"] == true)
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

    // YELLOW
    if (player->bag["Camera"] == true)
    {
        if (npc_yellow->cloned == false)
        {
            npc_yellow_clone->set_looking(npc_yellow->get_looking());
        }
        npc_yellow->cloned = true;
        this->npc_yellow_clone->instance_draw(target); //
    }
    else
    {
        this->npc_yellow->instance_draw(target);
    }

    // cyan
    if (player->bag["Penguin"] == true)
    {
        if (npc_cyan->cloned == false)
        {
            npc_cyan_clone->set_looking(npc_cyan->get_looking());
        }
        npc_cyan->cloned = true;
        this->npc_cyan_clone->instance_draw(target); //
    }
    else
    {
        this->npc_cyan->instance_draw(target);
    }

    // JITSI
    if(player->bag["Chocolate"] == true && player->bag["Chocolate"]== true
    && player->bag["Chocolate"] == true &&player->bag["Chocolate"]== true)
    {
        if(npc_jitsi_intro->cloned == false)
        {
            this->npc_jitsi_complete->instance_draw(target);
        }
        npc_jitsi_intro->cloned = true;
        npc_jitsi_complete->instance_draw(target);
    }else
    {
        this->npc_jitsi_intro->instance_draw(target);
    }
    // this->timer->hud_draw(target);

    this->coffee->instance_draw(target);
    this->chocolate->instance_draw(target);
    this->camera->instance_draw(target);
    this->penguin->instance_draw(target);

    // objetos em cima do mapa
    map_obj->draw(window);

    this->npc_blue->get_npc_dialogue()->dialogue_draw(target);
    this->npc_blue_clone->get_npc_dialogue()->dialogue_draw(target);

    this->npc_pink->get_npc_dialogue()->dialogue_draw(target);
    this->npc_pink_clone->get_npc_dialogue()->dialogue_draw(target);

    this->npc_yellow->get_npc_dialogue()->dialogue_draw(target);
    this->npc_yellow_clone->get_npc_dialogue()->dialogue_draw(target);

    this->npc_cyan->get_npc_dialogue()->dialogue_draw(target);
    this->npc_cyan_clone->get_npc_dialogue()->dialogue_draw(target);

    this->npc_jitsi_intro->get_npc_dialogue()->dialogue_draw(target);
    this->npc_jitsi_complete->get_npc_dialogue()->dialogue_draw(target);
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

        if ((object_collidable == npc_pink) || (object_collidable == npc_pink_clone))
        {
            npc_pink->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_pink_clone->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (chocolate->get_holding() == true)
            {
                npc_pink->npc_collision->disable_collision();
                if (npc_pink_clone->get_npc_dialogue()->given == false)
                {
                    chocolate->set_given(false);
                }
                if (npc_pink_clone->get_npc_dialogue()->given == true)
                {
                    chocolate->set_given(true);
                }
            }
        }

        if ((object_collidable == npc_blue) || (object_collidable == npc_blue_clone))
        {
            npc_blue->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_blue_clone->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (coffee->get_holding() == true)
            {
                npc_blue->npc_collision->disable_collision();
                if (npc_blue_clone->get_npc_dialogue()->given == false)
                {
                    coffee->set_given(false);
                }
                if (npc_blue_clone->get_npc_dialogue()->given == true)
                {
                    coffee->set_given(true);
                }
            }
        }

        if ((object_collidable == npc_yellow) || (object_collidable == npc_yellow_clone))
        {
            npc_yellow->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_yellow_clone->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (camera->get_holding() == true)
            {
                npc_yellow->npc_collision->disable_collision();
                if (npc_yellow_clone->get_npc_dialogue()->given == false)
                {
                    camera->set_given(false);
                }
                if (npc_yellow_clone->get_npc_dialogue()->given == true)
                {
                    camera->set_given(true);
                }
            }
        }

        if ((object_collidable == npc_cyan) || (object_collidable == npc_cyan_clone))
        {
            npc_cyan->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_cyan_clone->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (penguin->get_holding() == true)
            {
                npc_cyan->npc_collision->disable_collision();
                if (npc_cyan_clone->get_npc_dialogue()->given == false)
                {
                    penguin->set_given(false);
                }
                if (npc_cyan_clone->get_npc_dialogue()->given == true)
                {
                    penguin->set_given(true);
                }
            }
        }

        if ((object_collidable == npc_jitsi_intro) || (object_collidable == npc_jitsi_complete))
        {
            npc_jitsi_intro->get_npc_dialogue()->update_event_dialogue(player->z, player->x, false);
            npc_jitsi_complete->get_npc_dialogue()->update_event_dialogue(player->z, player->x, true);
            if (player->bag["Chocolate"] == true && player->bag["Camera"] == true && player->bag["Penguin"] == true && player->bag["Coffee"] == true)
            {
                // Levar para ending state
                std::cout << "AAAAAAAAAAAJITIJSIJ" << std::endl;
            }
        }
    }
}

void GameState::end_state()
{
    std::cout << "Ending game state!!!" << std::endl;
}

void GameState::generate_walls(std::string walls_dir)
{
    sf::Vector2i positionset_wall(0, 0);
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
