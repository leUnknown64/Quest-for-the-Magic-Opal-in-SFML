#ifndef CREDITS_H
#define CREDITS_H

#include "../GlobalWrapper.h"
#include "Screen.h"

// Controls the screens for the opening story and the credits page
class Credits : public Screen{
public:
    Credits();
    ~Credits();

    void loadChildren(sf::Font* font);
    void showStoryScreen(sf::RenderWindow* window);
    void showCreditsScreen(sf::RenderWindow* window);
    
    // Unused (abstract classes are weird)
    void update(sf::RenderWindow* window);
};

#endif
