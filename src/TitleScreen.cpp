#include "TitleScreen.h"

TitleScreen::TitleScreen(){
    // Initialize to false on startup
	gameStarted = false;
}

TitleScreen::~TitleScreen(){}

bool TitleScreen::isGameStarted(){
    return gameStarted;
}

void TitleScreen::loadChildren(sf::Font* font){
    // set up sprites
    addSprite(new SpriteObj("res/img/treasureMap.png", sf::Vector2f(200, 70), sf::Vector2f(0.8, 0.8)));
    
    // set up text
    addText(new TextObj(*font, "The Quest for the Magic Opal", sf::Vector2f(90, 15), 26, sf::Color(230,0,0)));
    addText(new TextObj(*font, "By Tim Koehler", sf::Vector2f(350, 60), 20, sf::Color(230,0,0)));

    // set up buttons
    addButton("START_GAME", new Button(*font, "Start Game", sf::Vector2f(300, 60), 22, sf::Color(0,0,240), sf::Color(230,0,0), sf::Vector2f(350, 645)));
}

void TitleScreen::update(sf::RenderWindow* window){
    if(getButton("START_GAME")->isPressed()){
        gameStarted = true;
    }
    
    if(!isGameStarted()){
        drawChildren(window);
    }
    else{
        unloadChildren();
    }
}
