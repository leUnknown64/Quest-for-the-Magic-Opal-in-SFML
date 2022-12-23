#ifndef CREATION_H
#define CREATION_H

#include "../GlobalWrapper.h"
#include "Screen.h"

// Class for the character creation screen
class CreationScreen : public Screen{
private:
	// Flag for switching to the next screen (Game Select)
    bool switchScreen;

public:
    CreationScreen();
    ~CreationScreen();

    bool isScreenSwitched();
    void loadChildren(sf::Font* font);
    void update(sf::RenderWindow* window);
};

#endif
