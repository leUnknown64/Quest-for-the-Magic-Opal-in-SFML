#include "Game.h"

// Private Functions
// Initializes the window's resolution, then dynamically allocates a window
void Game::initWindow(){
    // Resolution
    videoMode.width = 1024;
    videoMode.height = 768;
    
    window = new sf::RenderWindow(videoMode, "The Quest for the Magic Opal", sf::Style::Titlebar | sf::Style::Close);

    // Limit FPS
    window->setFramerateLimit(60); 
}

// Initialize the font for text
void Game::initFont(){
    if(!font.loadFromFile("res/font/quinque-five/Quinquefive-0Wonv.ttf"))
        throw("failed to load font!");
}

//////////////////////////////////////////////////////

// Public Functions
// Constructor
Game::Game(){
    initWindow();
    initFont();

    // Load in assets for all screens
    titleScreen.loadChildren(&font);
    createIF.loadChildren(&font);
    selectGame.loadChildren(&font);
    dartGame.loadChildren(&font);
    triviaGame.loadChildren(&font);
    gameCredits.loadChildren(&font);
}

// Deconstructor
Game::~Game(){
    // Unload objects from all screens
    titleScreen.unloadChildren();
    createIF.unloadChildren();
    selectGame.unloadChildren();
    dartGame.unloadChildren();
    triviaGame.unloadChildren();
    gameCredits.unloadChildren();
    
    // delete window from heap memory
    delete window; 
}

// Accessors

// Verify that the game window is open
const bool Game::getWindowIsOpen() const{
    return window->isOpen();
}


// Updates
// Event polling - handle closing the window
void Game::pollEvents(){
    while(this->window->pollEvent(event)){
        if(event.type == sf::Event::Closed)
            window->close();
    }
}

// Updates the following on every frame:
// 1. Event polling
void Game::update(){
    pollEvents();
}

// Master render function responsible for
// 1. Clearing the previous frame
// 2. Rendering game objects
// 3. Displaying rendered objects on the next frame
void Game::render(){
    // Set window's color
    window->clear(sf::Color(0,0,200));

    // Start on the title screen
    if(!titleScreen.isGameStarted()){
        titleScreen.update(window);
    }
    else{
        // Switch to the character creation screen
        if(!createIF.isScreenSwitched()){
            createIF.update(window);
        }
        else{
        // Switch to the game select screen
            if(!(gameCredits.getButton("CONTINUE")->isPressed())){
                gameCredits.showStoryScreen(window);
            }
            else{
                // Load in the selected game
                switch(selectGame.getChosenGame()){
                    case 0:
                        selectGame.update(window);
                        break;
                    case 1:
                        dartGame.update(window);
                        break;
                    case 2:
                        triviaGame.update(window);
                        break;
                    case 4:
                        gameCredits.showCreditsScreen(window);
                        break;
                    default:
                        throw("chosen game out of range!");
                }
            }
        }
    }

    window->display();
}
