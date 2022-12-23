#include "RectShapeObj.h"

// Set parameters for the shape
RectShapeObj::RectShapeObj(sf::Vector2f pos, sf::Vector2f size, sf::Color fillColor, sf::Color outlineColor, float thickness){
    shape.setPosition(pos);
    shape.setSize(size);
    shape.setFillColor(fillColor);
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(thickness);
}

RectShapeObj::~RectShapeObj(){}
