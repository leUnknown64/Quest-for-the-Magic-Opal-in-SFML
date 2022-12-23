#include "DartThrow.h"

DartThrow::DartThrow(){
    // Initialize game logic variables
	// (global timer is not really in seconds)
    points = 0;
    globalTimerSeconds = 1;

    // A balloon spawns every 25 "seconds" and only 6 are rendered at once
    balloonSpawnTimerMaxSeconds = 25;
    balloonSpawnTimerSeconds = balloonSpawnTimerMaxSeconds;
    maxBalloons = 6;
}

// Delete balloons from memory after shutdown
DartThrow::~DartThrow(){
    for(SpriteObj* b : balloons){
        delete b;
    }
}

// Load all required resources into memory
void DartThrow::loadChildren(sf::Font* font){
    // Set up sprites
    addSprite(new SpriteObj("res/img/carnival.png", sf::Vector2f(0, 0), sf::Vector2f(1, 1)));
    addSprite(new SpriteObj("res/img/imaginaryFriend.png", sf::Vector2f(120, 120), sf::Vector2f(0.4, 0.4)));
    addSprite(new SpriteObj("res/img/dart.png", sf::Vector2f(110, 150), sf::Vector2f(1, 1)));

    // Set up text
    addText(new TextObj(*font, "Points:", sf::Vector2f(5, 20), 26, sf::Color(0,0,0)));
    addText(new TextObj(*font, "0", sf::Vector2f(240, 20), 26, sf::Color(0,0,0)));
    
    // (Last two text boxes are reserved for the game over screen)
	addText(new TextObj(*font, "", sf::Vector2f(350, 160), 28, sf::Color(230,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(20, 220), 18, sf::Color(0,0,0)));
}

// Master update function
// Updates mouse cursor position and game processes
void DartThrow::update(sf::RenderWindow* window){
	updateMousePositions(window);
    gameLoop(window);
}

// Spawns a balloon
void DartThrow::spawnBalloon(){
    // Generate a random sprite scale value between 0.4 and 0.7
    float randScale = 0.4 + static_cast<float> (rand()) / (static_cast<float> (RAND_MAX/(0.3)));
    // Generate a random position for the sprite 
	// The boundaries for the spawn region are 80 < x < 880 and 180 < y < 520
    float randXpos = 80 + (rand() % 801);
    float randYPos = 180 + (rand() % 341);

    balloons.push_back(new SpriteObj("res/img/balloon.png", sf::Vector2f(randXpos, randYPos), sf::Vector2f(randScale, randScale)));
}

// Renders spawned balloons to the screen
void DartThrow::drawBalloons(sf::RenderWindow* window){
    for(SpriteObj* b : balloons){
        window->draw(b->sprite);
    }
}

// Update the position of the mouse cursor
void DartThrow::updateMousePositions(sf::RenderWindow* window){
    // Fetch the cursor's screen coordinates
	mousePosWindow = sf::Mouse::getPosition(*window);
    mousePosView = window->mapPixelToCoords(mousePosWindow);

    // A character holding a dart follows the mouse cursor
    getSprite(1)->sprite.setPosition(mousePosView);
    getSprite(2)->sprite.setPosition(mousePosView);
}

// Display the Game Over screen
void DartThrow::showGameOver(sf::RenderWindow* window){
	// Add text to the two reserved text boxes
	getText(2)->changeString("Game Over!");
    getText(3)->changeString("Press ESC to return to the game select screen");
    window->draw(getText(0)->text);
    window->draw(getText(1)->text);
    window->draw(getText(2)->text);
    window->draw(getText(3)->text);
}

// Controls and updates the game state of Dart Throw
void DartThrow::gameLoop(sf::RenderWindow* window){
    if(globalTimerSeconds > 1000){
        // Game Over after 1000 "seconds"
		showGameOver(window);
    }
    else{
		// Render all objects to the screen
        drawChildren(window);
		drawBalloons(window);

        // Spawn balloons (must be in the circus tent)
        if(balloons.size() < maxBalloons){
            if(balloonSpawnTimerSeconds >= balloonSpawnTimerMaxSeconds){
                // Spawn a balloon and reset the spawn timer to 0
                spawnBalloon();
                balloonSpawnTimerSeconds = 0;
            }
            else{
                balloonSpawnTimerSeconds += 1;
            }
        }
    
        // If a balloon is popped or "deleted", set this flag to true
        bool deleted = false;

		// For every spawned balloon
        for(unsigned int i = 0; i < balloons.size(); i++){
            deleted = false;

            // Award two points to the player if they popped a balloon with the mouse
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(balloons[i]->sprite.getGlobalBounds().contains(mousePosView)){
                    deleted = true;
                    points += 2;
                }
            }
            // Delete popped balloons from memory
            if(deleted){
                balloons.erase(balloons.begin() + i);
            }
        }

        // If the balloon is on the screen for 60 seconds, delete it without awarding
		// points to the player
        if(globalTimerSeconds % 60 == 0 && !balloons.empty()){
            balloons.erase(balloons.begin());
        }

        // Update the points counter
        getText(1)->changeString(std::to_string(points));
    }
    // Increment the global timer (used to track in-game time and balloon despawning)
    globalTimerSeconds++;
}
