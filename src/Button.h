#ifndef BUTTON_H
#define BUTTON_H

#include "../GlobalWrapper.h"

// Class for a button object
class Button{
private:
	// Buttons are rectangular
    sf::RectangleShape button;
	// Button's text
    sf::Text buttonText;
	// The color for a button's idle state
    sf::Color idleColor;

    // Button states
    enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};
    unsigned short currentState;

public:
    Button(sf::Font &font, std::string text, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, sf::Vector2f pos);
    
    void setBGColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    void drawButton(sf::RenderWindow* window);
    bool isMouseOver(sf::RenderWindow* window);
    bool isPressed();
    void updateState(sf::RenderWindow* window);
};

#endif
