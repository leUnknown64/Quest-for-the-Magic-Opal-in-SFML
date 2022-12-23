#include "Credits.h"

Credits::Credits(){}

Credits::~Credits(){}

// Load all required resources into memory
void Credits::loadChildren(sf::Font* font){
    // Set up sprites for story screen
    addSprite(new SpriteObj("res/img/storyFair.png", sf::Vector2f(120, 5), sf::Vector2f(1.1, 1.1)));
    addSprite(new SpriteObj("res/img/imaginaryFriend.png", sf::Vector2f(600, 300), sf::Vector2f(0.5, 0.5)));
    addSprite(new SpriteObj("res/img/guyWalking.png", sf::Vector2f(500, 300), sf::Vector2f(0.5, 0.5)));

    // Sprites for credits page
    addSprite(new SpriteObj("res/img/opal.png", sf::Vector2f(800, 10), sf::Vector2f(1, 1)));
    addSprite(new SpriteObj("res/img/opal.png", sf::Vector2f(60, 10), sf::Vector2f(1, 1)));
    addSprite(new SpriteObj("res/img/opal.png", sf::Vector2f(60, 550), sf::Vector2f(1.5, 1.5)));

    // Set up text for story screen
    addText(new TextObj(*font, "It is a hot summer afternoon. You and your new",
        sf::Vector2f(40, 460), 16, sf::Color(230,0,0)));
    addText(new TextObj(*font, "imaginary friend decide to visit the carnival", 
        sf::Vector2f(40, 500), 16, sf::Color(230,0,0)));
    addText(new TextObj(*font, "for the night. As you enter, the carnival's",
        sf::Vector2f(40, 540), 16, sf::Color(230,0,0)));
    addText(new TextObj(*font, "host announces that the best players will receive a",
        sf::Vector2f(40, 580), 16, sf::Color(230,0,0)));
    addText(new TextObj(*font, "magic opal. It is up to you and your friend to",
        sf::Vector2f(40, 620), 16, sf::Color(230,0,0)));
    addText(new TextObj(*font, "win that opal!!!!!",
        sf::Vector2f(40, 660), 16, sf::Color(230,0,0)));
    
    // Text for credits page
    addText(new TextObj(*font, "Game Credits", sf::Vector2f(300, 50), 30, sf::Color(230,0,0)));
    addText(new TextObj(*font, "Programming, Story, and Visual Design by", sf::Vector2f(40, 200), 20, sf::Color(230,0,0)));
    addText(new TextObj(*font, "Tim Koehler", sf::Vector2f(40, 250), 26, sf::Color(230,0,0)));
    addText(new TextObj(*font, "All sprite assets are free to use and", sf::Vector2f(40, 350), 20, sf::Color(230,0,0)));
    addText(new TextObj(*font, "available online.", sf::Vector2f(40, 380), 20, sf::Color(230,0,0)));
    addText(new TextObj(*font, "Thank you for playing!", sf::Vector2f(300, 620), 26, sf::Color(230,0,0)));

    // Set up buttons for story screen
    addButton("CONTINUE", new Button(*font, "Continue", sf::Vector2f(220,80), 22, sf::Color(0,0,240), sf::Color(230,0,0), sf::Vector2f(700, 660)));
}

// Show the credits screen
void Credits::showCreditsScreen(sf::RenderWindow* window){
    // Only draw new objects
    window->draw(getSprite(3)->sprite);
    window->draw(getSprite(4)->sprite);
    window->draw(getSprite(5)->sprite);
    for(int i = 6; i < 12; i++){
        window->draw(getText(i)->text);
    }
}

// Show the opening story
void Credits::showStoryScreen(sf::RenderWindow* window){
    for(int i = 0; i < 6; i++){
        window->draw(getText(i)->text);
    }
    for(int i = 0; i < 3; i++){
        window->draw(getSprite(i)->sprite);
    }
    drawButtons(window);
}

// unused function
void Credits::update(sf::RenderWindow* window){}
