#ifndef SCREEN_H
#define SCREEN_H

#include "../GlobalWrapper.h"
#include "SpriteObj.h"
#include "RectShapeObj.h"
#include "TextObj.h"
#include "Button.h"

// Abstract class for game screens
class Screen{
private:
    std::vector<SpriteObj*> screenSprites;
    std::vector<RectShapeObj*> screenShapes;
    std::vector<TextObj*> screenText;
    std::map<std::string, Button*> screenButtons;

public:
    Screen();
    ~Screen();

    // Adder functions
    void addSprite(SpriteObj* sprite);
    void addShape(RectShapeObj* shape);
    void addText(TextObj* text);
    void addButton(std::string key, Button* button);

    // Modifier functions
    Button* getButton(std::string key);
    TextObj* getText(unsigned int index);
    SpriteObj* getSprite(unsigned int index);

    virtual void loadChildren(sf::Font* font) = 0;
    void unloadSprites();
    void unloadShapes();
    void unloadText();
    void unloadButtons();
    void unloadChildren();

    void drawButtons(sf::RenderWindow* window);
    void drawChildren(sf::RenderWindow* window);
    virtual void update(sf::RenderWindow* window) = 0;
};

#endif