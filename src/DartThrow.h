#ifndef DART_THROW_H
#define DART_THROW_H

#include "../GlobalWrapper.h"
#include "Screen.h"

// Class for the Dart Throw screen and game processes 
class DartThrow : public Screen{
private:
    // Game logic variables
    unsigned int points, balloonSpawnTimerMaxSeconds, balloonSpawnTimerSeconds, maxBalloons, globalTimerSeconds;
    // Holds spawned balloons
    std::vector<SpriteObj*> balloons;
    // Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    void spawnBalloon();
    void drawBalloons(sf::RenderWindow* window);
    void updateMousePositions(sf::RenderWindow* window);
    void showGameOver(sf::RenderWindow* window);
    void gameLoop(sf::RenderWindow* window);

public:
    DartThrow();
    ~DartThrow();
    
    void loadChildren(sf::Font* font);
    void update(sf::RenderWindow* window);
};

#endif
