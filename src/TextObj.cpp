#include "TextObj.h"

// Set parameters for a text objects
TextObj::TextObj(sf::Font &font, std::string textString, sf::Vector2f pos, int fontSize, sf::Color textColor){
    text.setFont(font);
    text.setString(textString);
    text.setPosition(pos);
    text.setCharacterSize(fontSize);
    text.setFillColor(textColor);
}

// Change the text string of a text object
void TextObj::changeString(std::string textString){
    text.setString(textString);
}

TextObj::~TextObj(){}
