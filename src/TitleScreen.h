#ifndef TITLE_H
#define TITLE_H

#include "../GlobalWrapper.h"
#include "Screen.h"

// Class for the title screen
class TitleScreen : public Screen{
private:
	// Flag to start the game (switch to the opening story)
    bool gameStarted;

public:
    TitleScreen();
    ~TitleScreen();

    bool isGameStarted();
    void loadChildren(sf::Font* font);
    void update(sf::RenderWindow* window);
};

#endif
