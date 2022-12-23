#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include "../GlobalWrapper.h"

// Class for text objects
class TextObj{
private:

public:
    TextObj(sf::Font &font, std::string textString, sf::Vector2f pos, int fontSize, sf::Color textColor);
    ~TextObj();

    void changeString(std::string text);
    sf::Text text;
};

#endif
