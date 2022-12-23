#ifndef SELECT_H
#define SELECT_H

#include "../GlobalWrapper.h"
#include "Screen.h"

// Class for the Game Select screen
class SelectGame : public Screen{
private:
    // Value of chosenGame refers to the game selected
    // 0 = Game Select screen
    // 1 = Dart Throw game
    // 2 = Trivia Night game
    // 3 = unused
    // 4 = Credits screen
    // There is a better way to do this, but I ran out of time
    int chosenGame;

public:
    SelectGame();
    ~SelectGame();

    void loadChildren(sf::Font* font);
    int getChosenGame();
    void update(sf::RenderWindow* window);
};

#endif
