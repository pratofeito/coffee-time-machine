#include "instances/player.hpp"

Player::Player(int x, int y) : Instance(x, y)
{
    player_state = NOTHING;

    // Hit box test
    hit_box.setFillColor(sf::Color::Magenta);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);

    // Inicializa a player_collision colocando ela no vetor de colisões
    player_colision = new Collision(this);
}

Player::~Player()
{
    delete player_colision;
}

void Player::player_move(const float delta_time)
{
    // Verificação redundante, é possível otimizar e parar de verificar todo frame (Resolver nas férias)
    if (player_colision->get_collision(next_tile) == nullptr)
    {
        elapsed_time += delta_time;
        int partial_move = (elapsed_time * GRID_SIZE) / move_time;

        if (partial_move >= GRID_SIZE)
        {
            player_state = MOVING;
            elapsed_time = 0;
            virtual_position.x = next_tile.x;
            virtual_position.y = next_tile.y;
            hit_box.setPosition(sf::Vector2f(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE));
        }
        else
        {
            hit_box.setPosition(sf::Vector2f((virtual_position.x * GRID_SIZE) + (partial_move * move_dir.x),
                                             (virtual_position.y * GRID_SIZE) + (partial_move * move_dir.y)));
        }
    }
    else
    {
        player_state = NOTHING;
    }
}

// VER O QUE É CERTO AQUI!!

void Player::player_interact()
{
    Instance *object_collidable = player_colision->get_collision(next_tile);
    if (object_collidable != nullptr && accept_key)
    {
        object_collidable->instance_interact();
        okay = true;
        if (object_collidable->instanceof <Item>(object_collidable))
        {
            object_collidable->instance_interact(this->bag);
        }
        }
    if (player_colision->get_collision(next_tile) != nullptr && deny_key == true)
    {
        player_colision->get_collision(next_tile)->instance_desinteract();
        okay = false;
    }
    player_state = NOTHING;
}

void Player::check_inputs()
{
    // Move Keys
    arrow_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    arrow_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    arrow_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    arrow_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Player::uptade_event_player(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Z)
    {
        accept_key = true;
        // deny_key = false;
    }

    if (event.key.code == sf::Keyboard::X)
    {
        deny_key = true;
        // accept_key = false;
    }
}

void Player::keyboard_step()
{
    y_direction = arrow_down - arrow_up;
    x_direction = arrow_right - arrow_left;
    elapsed_time = 0;

    // Aviso: Remover a estranheza daqui (Férias)
    if (arrow_up)
    {
        player_state = MOVING;
        looking = UP;
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y + y_direction;
        move_dir = sf::Vector2i(0, y_direction);
    }
    else if (arrow_down)
    {
        player_state = MOVING;
        looking = DOWN;
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y + y_direction;
        move_dir = sf::Vector2i(0, y_direction);
    }
    else if (arrow_left)
    {
        player_state = MOVING;
        looking = LEFT;
        next_tile.x = virtual_position.x + x_direction;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(x_direction, 0);
    }
    else if (arrow_right)
    {
        player_state = MOVING;
        looking = RIGHT;
        next_tile.x = virtual_position.x + x_direction;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(x_direction, 0);
    }
    else if (accept_key || deny_key)
    {
        switch (looking)
        {
        case UP:
            next_tile.x = virtual_position.x;
            next_tile.y = virtual_position.y - 1;
            break;
        case DOWN:
            next_tile.x = virtual_position.x;
            next_tile.y = virtual_position.y + 1;
            break;
        case LEFT:
            next_tile.x = virtual_position.x - 1;
            next_tile.y = virtual_position.y;
            break;
        case RIGHT:
            next_tile.x = virtual_position.x + 1;
            next_tile.y = virtual_position.y;
            break;
        }
        // std::cout << "x: " << next_tile.x << " y: " << next_tile.y << std::endl;
        player_state = INTERACTING;
    }
    else
    {
        player_state = NOTHING;
    }
}

void Player::instance_interact()
{
}

void Player::instance_desinteract()
{
}

void Player::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->hit_box);
}

void Player::instance_update(const float &delta_time)
{
    switch (player_state)
    {
    case INTERACTING:
        // std::cout << "Case Interacting" << std::endl;
        player_interact();
        break;
    case MOVING:
        // std::cout << "Case Moving" << std::endl;
        player_move(delta_time);
        break;
    case NOTHING:
        // std::cout << "Case Nothing" << std::endl;
        check_inputs();
        keyboard_step();
        break;
    }
}