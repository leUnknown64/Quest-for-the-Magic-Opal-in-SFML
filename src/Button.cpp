#include "Button.h"

// Overloaded constructor allows for custom buttons
Button::Button(sf::Font &font, std::string text, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, sf::Vector2f pos){
	// Set parameters for the button's text
    buttonText.setFont(font);
    buttonText.setString(text);
    buttonText.setFillColor(textColor);
    buttonText.setCharacterSize(charSize);
    
	// Set the button's size and position
	button.setSize(size);
	setPosition(pos);

	// Initialize the state to BTN_IDLE and use the idle color
    idleColor = bgColor;
    setBGColor(idleColor);
    currentState = BTN_IDLE;
}

// Set the button's background/fill color
void Button::setBGColor(sf::Color color){
    button.setFillColor(color);
}

// Set the button's position on the screen
void Button::setPosition(sf::Vector2f pos){
    button.setPosition(pos);

    // Center the text in the button
    float xPos = (pos.x + button.getGlobalBounds().width / 2) - (buttonText.getGlobalBounds().width / 2);
    float yPos = (pos.y + button.getGlobalBounds().height / 2) - (buttonText.getGlobalBounds().height / 2);
    buttonText.setPosition(xPos, yPos);
}

// Render the button to the screen
void Button::drawButton(sf::RenderWindow* window){
    window->draw(button);
    window->draw(buttonText);
}

// Check if the mouse cursor is over the button
bool Button::isMouseOver(sf::RenderWindow* window){
    // Get current position of cursor
    float mouseX = sf::Mouse::getPosition(*window).x; 
    float mouseY = sf::Mouse::getPosition(*window).y;

    // Get the button's (X,Y) position and the position of its width and height
    float btnXPos = button.getPosition().x;
    float btnYPos = button.getPosition().y;
    float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
    float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

    return (mouseX < btnXPosWidth && mouseX > btnXPos && mouseY < btnYPosHeight && mouseY > btnYPos);
}

// Update the state of the button (possible states are BTN_IDLE, BTN_PRESSED, and BTN_HOVER)
// Change the button's color, depending on the state
void Button::updateState(sf::RenderWindow* window){
    // First assume button is idle
    currentState = BTN_IDLE;
    setBGColor(idleColor);

    // Check if mouse hovers over button
    if(isMouseOver(window)){
        currentState = BTN_HOVER;
        setBGColor(sf::Color::Blue);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            currentState = BTN_PRESSED;
        }
    }
}

// Check if the button was clicked
bool Button::isPressed(){
    return currentState == BTN_PRESSED;
}
