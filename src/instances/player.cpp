#include "instances/player.hpp"

Player::Player(int x, int y) : Instance(x, y)
{
    is_moving = false;

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
            is_moving = false;
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
        is_moving = false;
    }
}

void Player::check_inputs()
{
    // Move Keys
    arrow_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    arrow_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    arrow_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    arrow_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

    // Interact Keys
    accept_key = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    deny_key = sf::Keyboard ::isKeyPressed(sf::Keyboard::X);
}

void Player::keyboard_step()
{
    check_inputs();
    int y_direction = arrow_down - arrow_up;
    int x_direction = arrow_right - arrow_left;
    is_moving = true;
    elapsed_time = 0;

    // Aviso: Remover a estranhesa daqui (Férias)
    if (arrow_up || arrow_down)
    {
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y + y_direction;
        move_dir = sf::Vector2i(0, y_direction);
    }
    else if (arrow_left || arrow_right)
    {
        next_tile.x = virtual_position.x + x_direction;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(x_direction, 0);
    }
}

void Player::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->hit_box);
}

void Player::instance_update(const float &delta_time)
{
    if (is_moving)
    {
        player_move(delta_time);
    }
    else
    {
        keyboard_step();
    }
}