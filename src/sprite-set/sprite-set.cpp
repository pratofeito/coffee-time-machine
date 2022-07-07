#include "sprite-set/sprite-set.hpp"

SpriteSet::SpriteSet(std::string tileset_dir) {

    // carrega o tileset em uma textura
    texture.loadFromFile(tileset_dir);

    // obtem a largura e altura do tileset
    sf::Vector2u texture_size = texture.getSize();
    tileset_width = texture_size.x / TILE_SIZE;
    tileset_height = texture_size.y / TILE_SIZE;

    // preenche texture map   
    for (int i = 0; i < tileset_height; i++) {
        for (int j = 0; j < tileset_width; j++){
            sf::IntRect subrect (j * TILE_SIZE, i * TILE_SIZE, TILE_SIZE, TILE_SIZE);
            texture_map.push_back(subrect);
        }
    }

    // o tamanho das sprites de uma instância tem que ser toda preenchida
    int sprites_size = tileset_width * tileset_height;

    // preenche o vetor de sprites
    for (int i = 0; i < sprites_size; i++){
        sf::Sprite* sprite = new sf::Sprite(texture, texture_map[i]);
        sprites_map.push_back(sprite);
    }

}

SpriteSet::~SpriteSet() {
    clear_sprites_map();
}

void SpriteSet::clear_sprites_map() {
    for (auto sprite : sprites_map) {
        delete sprite;
    }
    sprites_map.clear();
}