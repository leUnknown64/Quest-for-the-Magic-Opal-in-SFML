#ifndef SPRITEOBJ_H
#define SPRITEOBJ_H

#include "../GlobalWrapper.h"

// Class to manage sprites and their properties.
class SpriteObj{
private:
    // position coords
    sf::Vector2f spritePos;
    // scale values (x and y)
    sf::Vector2f spriteScale;
    // texture name
    sf::Texture spriteTex;
public:
    SpriteObj(std::string textureName, sf::Vector2f pos, sf::Vector2f scale);
    void setUpSprite();
    // sprite object
    sf::Sprite sprite;
};

#endif