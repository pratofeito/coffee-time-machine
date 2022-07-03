#include "Map/map.hpp"

void Map::load_map_assets() {
    input = std::ifstream("resources/map.csv");

    // obtenho o que tenho que colocar em cada lugar
    while(std::getline(input, line)) {
        std::stringstream original_string (line);
        std::string parte;
        while (std::getline(original_string, parte, ',')) {
            valores.push_back(stoi(parte));
        }
    }

    // carrega tileset
    texture.loadFromFile("resources/bricks.png");
    
    // carrego as texturas    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++){
            sf::IntRect subrect (j * 32, i * 32, 32, 32);
            retangulos.push_back(subrect);
        }
    }

    // define a sprite de cada posição
    for (int i = 0; i < (int)valores.size(); i++){
        sf::Sprite sprite(texture, retangulos[valores[i]]);
        sprites_map.push_back(sprite);
    }

    // define a posição absoluta de cada posição
    int coiso = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 25; j++){
            sprites_map[coiso].setPosition(j * 32, i * 32);
            coiso++;
        }
    }
}

void Map::draw_guide_lines(sf::RenderWindow *window) {
    sf::RectangleShape vertical_line;
    sf::RectangleShape horizontal_line;

    vertical_line.setSize(sf::Vector2f(1, 640));
    horizontal_line.setSize(sf::Vector2f(800, 1));

    sf::Color ct (244, 125, 66, 100);
    vertical_line.setFillColor(ct);
    horizontal_line.setFillColor(ct);

    for (int i = 1; i < (800/32); i++) {
        vertical_line.setPosition(32 * i, 0);
        horizontal_line.setPosition(0, 32 * i);
        window->draw(vertical_line);
        window->draw(horizontal_line);
    }
}

void Map::draw_map(sf::RenderWindow *window) {
    for (auto s : sprites_map) {
        window->draw(s);
    }
}