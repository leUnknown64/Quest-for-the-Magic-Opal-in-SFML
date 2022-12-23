#ifndef RECT_SHAPE_OBJ
#define RECT_SHAPE_OBJ

#include "../GlobalWrapper.h"

// Class for rectangle shape objects
class RectShapeObj{
private:

public:
    RectShapeObj(sf::Vector2f pos, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, float thickness);
    ~RectShapeObj();
    // Shape object
	sf::RectangleShape shape;
};

#endif
