#include "CreationScreen.h"

CreationScreen::CreationScreen(){
	// Do not switch screens on startup
	switchScreen = false;
}

CreationScreen::~CreationScreen(){}

// Check if the screen was switched
bool CreationScreen::isScreenSwitched(){
    return switchScreen;
}

// Load all required resources into memory
void CreationScreen::loadChildren(sf::Font* font){
    // set up sprites
    addSprite(new SpriteObj("res/img/cloud.png", sf::Vector2f(680, 80), sf::Vector2f(0.4, 0.4)));
    addSprite(new SpriteObj("res/img/sunglasses.png", sf::Vector2f(850, 80), sf::Vector2f(0.5, 0.5)));
    addSprite(new SpriteObj("res/img/tophat.png", sf::Vector2f(680, 180), sf::Vector2f(0.25, 0.25)));
    addSprite(new SpriteObj("res/img/bowtie.png", sf::Vector2f(850, 140), sf::Vector2f(0.3, 0.3)));
    addSprite(new SpriteObj("res/img/smiley.png", sf::Vector2f(850, 180), sf::Vector2f(0.2, 0.2)));
    addSprite(new SpriteObj("res/img/tshirt.png", sf::Vector2f(850, 300), sf::Vector2f(0.5, 0.5)));
    addSprite(new SpriteObj("res/img/sweater.png", sf::Vector2f(660, 300), sf::Vector2f(0.8, 0.8)));
    addSprite(new SpriteObj("res/img/sweatpants.png", sf::Vector2f(850, 450), sf::Vector2f(0.3, 0.3)));
    addSprite(new SpriteObj("res/img/jeans.png", sf::Vector2f(680, 450), sf::Vector2f(0.4, 0.4)));

    // set up text
    addText(new TextObj(*font, "Create Your Imaginary Friend!", sf::Vector2f(80, 5), 24, sf::Color(230,0,0)));

    // set up shapes
    addShape(new RectShapeObj(sf::Vector2f(50, 80), sf::Vector2f(600, 600), sf::Color(0,0,240), sf::Color(230,0,0), 5));

    // set up buttons
    addButton("TO_GAME_SELECT", new Button(*font, "I'm done!", sf::Vector2f(280, 60), 22, sf::Color(0,0,240), sf::Color(230,0,0), sf::Vector2f(400, 700)));
}

// Master update function
void CreationScreen::update(sf::RenderWindow* window){
    if(getButton("TO_GAME_SELECT")->isPressed()){
        // Switch to the Game Select screen if the button was pressed
		switchScreen = true;
    }
	
	// Render objects to the screen
    drawChildren(window);
}
