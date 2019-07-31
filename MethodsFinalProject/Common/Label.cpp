#include "Label.h"
#include <iostream>

Label::Label() : Control(){ this->isFocused = false; }

//label size is determined according to the text length
Label::Label(string value) : Control(), value(value) {
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocused = false;
};

//adding background color and text color to the label
Label::Label(string value, Color backgroundColor, Color textColor) : Control(), value(value) {setColor(backgroundColor, textColor);
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocused = false;

};

Label::Label(string value, Color backgroundColor, Color textColor, short left, short top) : Control(left, top), value(value) {
	setColor(backgroundColor, textColor);
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->isFocused = false;
};

//draw Label on screen
void Label::draw(Graphics& g) { 
	drawIt(g, this);
}
void Label::drawInside(Graphics& g) {
	g.write(getLeft(), getTop(), this->value);
}

//default destructor
Label::~Label(){

};