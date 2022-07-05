#include "instances/player.hpp"
#include <unistd.h>

Player::Player(int x, int y) : Instance(x, y)
{
    // Hit box test
    hit_box.setFillColor(sf::Color::Magenta);
    hit_box.setSize(sf::Vector2f(GRID_SIZE, GRID_SIZE));
    hit_box.setPosition(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);

    is_moving = false;
}

Player::~Player()
{
}

void Player::player_move(const float delta_time)
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

void Player::check_inputs()
{
    // Movimentos
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        looking = UP;
        is_moving = true;
        elapsed_time = 0;
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y - 1;
        move_dir = sf::Vector2i(0, -1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        looking = DOWN;
        is_moving = true;
        elapsed_time = 0;
        next_tile.x = virtual_position.x;
        next_tile.y = virtual_position.y + 1;
        move_dir = sf::Vector2i(0, 1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        looking = LEFT;
        is_moving = true;
        elapsed_time = 0;
        next_tile.x = virtual_position.x - 1;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(-1, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        looking = RIGHT;
        is_moving = true;
        elapsed_time = 0;
        next_tile.x = virtual_position.x + 1;
        next_tile.y = virtual_position.y;
        move_dir = sf::Vector2i(1, 0);
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
        check_inputs();
    }
}