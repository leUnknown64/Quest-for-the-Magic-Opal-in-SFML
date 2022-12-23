#ifndef GAME_H
#define GAME_H

#include "../GlobalWrapper.h"
#include "TitleScreen.h"
#include "SelectGame.h"
#include "CreationScreen.h"
#include "DartThrow.h"
#include "TriviaNight.h"
#include "Credits.h"

// Game engine class. Wrapper class.
class Game{
private:
    // Variables
    // Window
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    // Game screens
    TitleScreen titleScreen;
    SelectGame selectGame;
    CreationScreen createIF;
    DartThrow dartGame;
    TriviaNight triviaGame;
    Credits gameCredits;

    // Font
    sf::Font font;

    // Private functions
    void initWindow();
    void initFont();

public:
    Game();
    ~Game();

    // Accessors
    const bool getWindowIsOpen() const;

    // Updates
    void pollEvents();
    void update();

    // Rendering
    void render();
};

#endif