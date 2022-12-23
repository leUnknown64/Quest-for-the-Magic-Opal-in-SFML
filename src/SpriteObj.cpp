#include "SpriteObj.h"

// Class Constructor
// Initializes private variables and sets up a sprite object
SpriteObj::SpriteObj(std::string textureName, sf::Vector2f pos, sf::Vector2f scale){
    spritePos = pos;
    spriteScale = scale;
    
    // Try to load the texture file
    if(!spriteTex.loadFromFile(textureName)){
        throw("cannot load texture " + textureName);
    }

    setUpSprite();
}

// Set the sprite's texture, screen position, and scale
void SpriteObj::setUpSprite(){
    sprite.setTexture(spriteTex);
    sprite.setPosition(spritePos);
    sprite.setScale(spriteScale);
}
