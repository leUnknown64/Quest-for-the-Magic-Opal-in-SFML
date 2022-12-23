#include "SelectGame.h"

SelectGame::SelectGame(){
    // Initalize chosenGame to 0 (Game Select screen)
    chosenGame = 0;
}

SelectGame::~SelectGame(){}

// Load all required resources into memory
void SelectGame::loadChildren(sf::Font* font){
    // set up sprites
    addSprite(new SpriteObj("res/img/arcade.png", sf::Vector2f(0, 0), sf::Vector2f(1, 1)));

    addSprite(new SpriteObj("res/img/balloon.png", sf::Vector2f(120, 120), sf::Vector2f(0.5, 0.5)));
    addSprite(new SpriteObj("res/img/balloon.png", sf::Vector2f(295, 80), sf::Vector2f(0.5, 0.5)));
    addSprite(new SpriteObj("res/img/balloon.png", sf::Vector2f(230, 110), sf::Vector2f(0.25, 0.25)));

    addSprite(new SpriteObj("res/img/question.png", sf::Vector2f(100, 460), sf::Vector2f(0.25, 0.25)));
    addSprite(new SpriteObj("res/img/question.png", sf::Vector2f(350, 480), sf::Vector2f(0.5, 0.5)));
    addSprite(new SpriteObj("res/img/question.png", sf::Vector2f(50, 650), sf::Vector2f(0.3, 0.3)));
    
    // set up text
    addText(new TextObj(*font, "Select A Game", sf::Vector2f(325, 15), 26, sf::Color(230,0,0)));

    // Text for red box
    addText(new TextObj(*font, "Dart", sf::Vector2f(155, 250), 22, sf::Color(230,0,0)));
    addText(new TextObj(*font, "Throw", sf::Vector2f(155, 280), 22, sf::Color(230,0,0)));

    // Text for green Box
    addText(new TextObj(*font, "Ping", sf::Vector2f(680, 250), 22, sf::Color(0,240,0)));
    addText(new TextObj(*font, "Pong", sf::Vector2f(680, 280), 22, sf::Color(0,240,0)));

    // Text for orange Box
    addText(new TextObj(*font, "Trivia", sf::Vector2f(155, 550), 22, sf::Color(255,102,0)));
    addText(new TextObj(*font, "Night", sf::Vector2f(155, 580), 22, sf::Color(255,102,0)));
    
    // Set up shapes
    // Shape for red Box
    addShape(new RectShapeObj(sf::Vector2f(125, 200), sf::Vector2f(220, 160), sf::Color(0,0,240), sf::Color(230,0,0), 5));

    // Shape for green Box
    addShape(new RectShapeObj(sf::Vector2f(650, 200), sf::Vector2f(220, 160), sf::Color(0,0,240), sf::Color(0,240,0), 5));

    // Shape for orange Box
    addShape(new RectShapeObj(sf::Vector2f(125, 500), sf::Vector2f(220, 160), sf::Color(0,0,240), sf::Color(255,102,0), 5));

    // Shape for pink Box
    addShape(new RectShapeObj(sf::Vector2f(650, 500), sf::Vector2f(220, 160), sf::Color(0,0,240), sf::Color(200,0,200), 5));

    // Set up buttons
    addButton("DART_THROW", new Button(*font, "", sf::Vector2f(220, 160), 22, sf::Color(0,0,240), sf::Color(0,0,0), sf::Vector2f(125, 200)));
    addButton("TRIVIA", new Button(*font, "", sf::Vector2f(220, 160), 22, sf::Color(0,0,240), sf::Color(0,0,0), sf::Vector2f(125, 500)));
    addButton("PING_PONG", new Button(*font, "", sf::Vector2f(220, 160), 22, sf::Color(0,0,240), sf::Color(200,0,200), sf::Vector2f(650, 200)));
    addButton("CREDITS", new Button(*font, "Credits", sf::Vector2f(220, 160), 22, sf::Color(0,0,240), sf::Color(200,0,200), sf::Vector2f(650, 500)));
}

// Get the number for the chosen game
int SelectGame::getChosenGame(){
    return chosenGame;
}

// Master update function
void SelectGame::update(sf::RenderWindow* window){
    // Render objects to the screen
    drawChildren(window);

    // Check for what is selected and update chosenGame
    if(getButton("DART_THROW")->isPressed()){
        chosenGame = 1;
    }
    if(getButton("TRIVIA")->isPressed()){
        chosenGame = 2;
    }
    if(getButton("CREDITS")->isPressed()){
        chosenGame = 4;
    }
}
