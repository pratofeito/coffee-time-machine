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

    // animações do personagem
    player_animation = new Animation(this);
    player_animation->new_state(1, "resources/sprites/player/player_right.png");
    player_sprite = player_animation->get_sprite();

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
            projected_position = sf::Vector2f(virtual_position.x * GRID_SIZE, virtual_position.y * GRID_SIZE);
        }
        else
        {
            projected_position = sf::Vector2f((virtual_position.x * GRID_SIZE) + (partial_move * move_dir.x),
                                              (virtual_position.y * GRID_SIZE) + (partial_move * move_dir.y));
        }
    }
    else
    {
        player_state = NOTHING;
    }
}

void Player::player_interact()
{
    if (player_colision->get_collision(next_tile) != nullptr && accept_key)
    {
        player_colision->get_collision(next_tile)->instance_interact();
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

    // Interact Keys (Trocar pra evento)
    accept_key = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    deny_key = sf::Keyboard ::isKeyPressed(sf::Keyboard::X);
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
    else if (accept_key)
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
        std::cout << "x: " << next_tile.x << " y: " << next_tile.y << std::endl;
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

void Player::instance_draw(sf::RenderTarget *target)
{
    // target->draw(this->hit_box);
    target->draw(*this->player_sprite);
}

void Player::instance_update(const float &delta_time)
{

    // atualiza a posição do objeto que estamos movendo que é modificada em algum outro lugar
    hit_box.setPosition(projected_position);

    // tem que atualizar primeiro de mudar a posição, a posição é sempre resetada!
    player_animation->update(player_state, looking, delta_time);
    player_sprite->setPosition(projected_position);

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