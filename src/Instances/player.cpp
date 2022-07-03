#include "Instances/player.hpp"

Player::Player()
{
    this->colision_mask.setFillColor(sf::Color::Cyan);
    walking = false;
    for (int i = 0; i < 4; i++)
    {
        move[i] = false;
    }
}

Player::~Player()
{
}

void Player::player_move(const float delta_time)
{
    if (move[DOWN] == true)
    {
        this->y += move_speed + delta_time;
        if (this->y >= next_tile_y)
        {
            this->y = next_tile_y;
            walking = false;
            move[DOWN] = false;
        }
    }

    if (move[UP] == true)
    {
        this->y -= move_speed - delta_time;
        if (this->y <= next_tile_y)
        {
            this->y = next_tile_y;
            walking = false;
            move[UP] = false;
        }
    }

    if (move[LEFT] == true)
    {
        this->x -= move_speed - delta_time;
        if (this->x <= next_tile_x)
        {
            this->x = next_tile_x;
            walking = false;
            move[LEFT] = false;
        }
    }

    if (move[RIGHT] == true)
    {
        this->x += move_speed + delta_time;
        if (this->x >= next_tile_x)
        {
            this->x = next_tile_x;
            walking = false;
            move[RIGHT] = false;
        }
    }
    colision_mask.setPosition(this->x, this->y);
}

void Player::player_inputs()
{
    // Movimentos

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (can_up)
        {
            if (walking == false)
            {
                next_tile_y = y - GRID_SIZE;
                move[UP] = true;
                walking = true;
            }
        }
        this->direction = "Looking UP";
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (can_down)
        {
            if (walking == false)
            {
                next_tile_y = y + GRID_SIZE;
                move[DOWN] = true;
                walking = true;
            }
        }
        this->direction = "Looking DOWN";
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (can_left)
        {
            if (walking == false)
            {
                next_tile_x = x - GRID_SIZE;
                move[LEFT] = true;
                walking = true;
            }
        }
        this->direction = "Looking LEFT";
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (can_right)
        {
            if (walking == false)
            {
                next_tile_x = x + GRID_SIZE;
                move[RIGHT] = true;
                walking = true;
            }
        }
        this->direction = "Looking RIGHT";
    }
}

void Player::player_col(std::vector<Wall> colisions)
{
    for (auto &i : colisions)
    {
        // Teste Colisão Para cima
        can_up = true;
        can_down = true;
        can_left = true;
        can_right = true;
        if (i.get_colision_mask().getPosition().x == next_tile_x && i.get_colision_mask().getPosition().y == next_tile_y - GRID_SIZE)
        {
            can_up = false;
            player_interact(i);
        }

        // Teste Colisão Para baixo
        if (i.get_colision_mask().getPosition().x == next_tile_x && i.get_colision_mask().getPosition().y == next_tile_y + GRID_SIZE)
        {
            can_down = false;
            player_interact(i);
        }

        // Teste Colisão Para direita
        if (i.get_colision_mask().getPosition().x == next_tile_x + GRID_SIZE && i.get_colision_mask().getPosition().y == next_tile_y)
        {
            can_right = false;
            player_interact(i);
        }

        // Teste Colisão Para esquerda
        if (i.get_colision_mask().getPosition().x == next_tile_x - GRID_SIZE && i.get_colision_mask().getPosition().y == next_tile_y)
        {
            can_left = false;
            player_interact(i);
        }
    }
}

void Player::player_interact(const Wall colisions)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (direction == "Looking UP" && can_up == false)
        {
            std::cout << "Interagiu" << std::endl;
        }

        if (direction == "Looking DOWN" && can_down == false)
        {
            std::cout << "Interagiu" << std::endl;
        }

        if (direction == "Looking LEFT" && can_left == false)
        {
            std::cout << "Interagiu" << std::endl;
        }

        if (direction == "Looking RIGHT" && can_right == false)
        {
            std::cout << "Interagiu" << std::endl;
        }
    }
}

void Player::instance_draw(sf::RenderTarget *target)
{
    target->draw(this->colision_mask);
}

void Player::instance_update(const float &delta_time)
{
    // std::cout << this->direction << std::endl;
    player_inputs();
    player_move(delta_time);
}