#include "Button.h"

Button::Button() : Label(){ 
	this->isFocused = false;
	this->isClicked = true;
	setWidth((short)(getValue().size()));
	setHeight(1);
	setBorder(true);
}

// default C'tor getting string
Button::Button(string value) : Label(value){
	setWidth((short)(getValue().size()));
	this->isClicked = true;
	setHeight(1);
	setBorder(true);
}

//default C'tor getting value,background color and text color parameters
Button::Button(string value, Color backgroundColor, Color textColor) : Label(value,backgroundColor,textColor){
	setWidth((short)(getValue().size()));
	this->isClicked = true;
	setHeight(1);
	setBorder(true);
}

void Button::mousePressed(int x, int y, bool isLeft) {
	setColor(Color::Green, Color::White);
}

//default D'tor
Button::~Button(){

};