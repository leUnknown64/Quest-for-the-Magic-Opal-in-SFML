#include "Screen.h"

Screen::Screen(){}

Screen::~Screen(){}

// Functions which add objects to the screen
void Screen::addSprite(SpriteObj* sprite){
    screenSprites.push_back(sprite);
}

void Screen::addShape(RectShapeObj* shape){
    screenShapes.push_back(shape);
}
    
void Screen::addText(TextObj* text){
    screenText.push_back(text);
}

void Screen::addButton(std::string key, Button* button){
    screenButtons.insert({key, button});
}

// Functions to access and modify added objects
Button* Screen::getButton(std::string key){
    auto search = screenButtons.find(key);
    if(search == screenButtons.end()){
        throw("Button with key " + key + " was not found!");
    }
    return screenButtons[key];
}

TextObj* Screen::getText(unsigned int index){
    if(index >= screenText.size()){
        throw("Index for screenText out of range!");
    }
    return screenText[index];
}

SpriteObj* Screen::getSprite(unsigned int index){
    if(index >= screenSprites.size()){
        throw("Index for screenSprites out of range!");
    }
    return screenSprites[index];
}

// Unload functions
void Screen::unloadSprites(){
    for(const SpriteObj* sprite : screenSprites){
        delete sprite;
    }
}

void Screen::unloadShapes(){
    for(const RectShapeObj* shape : screenShapes){
        delete shape;
    }
}

void Screen::unloadText(){
    for(const TextObj* text : screenText){
        delete text;
    }
}

void Screen::unloadButtons(){
    auto it = screenButtons.begin();
    for(it = screenButtons.begin(); it != screenButtons.end(); ++it){
        delete it->second;
    }
}

// Unload all screen objects from heap memory
void Screen::unloadChildren(){
    unloadSprites();
    unloadShapes();
    unloadText();
    unloadButtons();
}

// Render buttons to the screen
void Screen::drawButtons(sf::RenderWindow* window){
    auto it = screenButtons.begin();
    for(it = screenButtons.begin(); it != screenButtons.end(); ++it){
        it->second->drawButton(window);
        it->second->updateState(window);
    }
}

// Render all objects to the screen
void Screen::drawChildren(sf::RenderWindow* window){
    for(SpriteObj* sprt : screenSprites){
        window->draw(sprt->sprite);
    }

    for(RectShapeObj* rectShape : screenShapes){
        window->draw(rectShape->shape);
    }

    drawButtons(window);

    for(TextObj* textObj : screenText){
        window->draw(textObj->text);
    }
}
