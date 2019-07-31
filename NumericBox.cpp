#include "NumericBox.h"

//numeric box to choose number between 18 and 120 with + and - symbols  
NumericBox::NumericBox(int min = 18, int max = 120, short left = 0, short top = 0) : TextBox(left, top, (short)(to_string(max).size()) + 1) {
	this->min = min;
	this->max = max;
	setActual(min);
	isFocused = false; 
	if (min >= 18) setValue(" " + to_string(min));
	else setValue(to_string(min));
	setHeight(3);

	plus.setValue(" + ");			
	plus.setLeft(getLeft()+1);
	plus.setTop(getTop()+1);
	plus.setWidth(3);

	value.setValue("20");
	value.setLeft(plus.getLeft()+5);
	value.setTop(getTop()+1);
	value.setWidth(3);
	value.setBackgroundColor(Color::White);
	value.setTextColor(Color::Black);

	minus.setValue(" - ");				
	minus.setLeft(value.getLeft()+6);
	minus.setTop(getTop()+1);
	minus.setWidth(3);
	setWidth(plus.getWidth() + minus.getWidth() + getWidth() +6);
}

//set background color and text color to the numeric box
void NumericBox::setColor(Color backgroundColor, Color textColor) {
	Control::setColor(backgroundColor, textColor);
	plus.setColor(backgroundColor, textColor);
	minus.setColor(backgroundColor, textColor);
}

//draw numeric box on screen
void NumericBox::draw(Graphics& g) {
	drawIt(g, this);
}

//draw the numeric box with + and - symbols
void NumericBox::drawInside(Graphics& g) {
	//TextBox::drawInside(g);
	value.setValue(TextBox::getValue());
	plus.draw(g);
	minus.draw(g);
	value.draw(g);
}

void NumericBox::mousePressed(int x, int y, bool isLeft) {
	int actual = getActual();
	if (isInside(x, y, &plus) && actual < max) setActual(++actual);
	else if (isInside(x, y, &minus) && actual > min)setActual(--actual);

	if (actual >= -9) setValue(" " + to_string(actual));
	else setValue(to_string(actual));
}

//default D'tor
NumericBox::~NumericBox(){

};