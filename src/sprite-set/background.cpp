#include "sprite-set/background.hpp"

Background::Background(std::string tileset_dir, std::string positionset_dir, sf::Vector2i position) : SpriteSet(tileset_dir) {

    // carrega o arquivo de mapa
    sprites_index_file = std::ifstream(positionset_dir);
    std::string line;

    // quebra o arquivo e  o que tenho que colocar em cada lugar
    sf::Vector2i positionset_size(0, 0);
    while(std::getline(sprites_index_file, line)) {
        positionset_size.y++;
        std::stringstream original_string (line);
        std::string parte;
        while (std::getline(original_string, parte, ',')) {
            positionset_size.x++;
            sprites_index.push_back(stoi(parte));
        }
    }

    //remove as redundancias
    positionset_size.x /= positionset_size.y;

    // limpa o vetor construido ja indexado, pois não faz sentido com o para de sprite
    clear_sprites_map();

    // define a sprite de cada posição
    for (int i = 0; i < (int)sprites_index.size(); i++){
        sf::Sprite* sprite = new sf::Sprite(texture, texture_map[sprites_index[i]]);
        sprites_map.push_back(sprite);
    }

    // define a posição absoluta de cada sprite
    int index = 0;
    for (int i = 0; i < positionset_size.y; i++) {
        for (int j = 0; j < positionset_size.x; j++){
            sprites_map[index]->setPosition((j * TILE_SIZE) + position.x, (i * TILE_SIZE) + position.y);
            index++;
        }
    }

}

void Background::draw(sf::RenderWindow *window) {
    for (auto sprite : sprites_map) {
        window->draw(*sprite);
    }
}