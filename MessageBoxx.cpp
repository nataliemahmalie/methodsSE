#include "MessageBoxx.h"

MessageBoxx::MessageBoxx(string value, Color backgroundColor, Color textColor, short left, short top) : Label(value, backgroundColor, textColor, left, top) {
	string leftButton = " female ";
	string rightButton = " male ";
	setBorder(true);
	this->isFocused = false;
	this->isClicked = true;
	lb.setValue(leftButton);
	lb.setLeft(getLeft()+1);
	lb.setTop(getTop()+2);
	lb.setWidth((short)(leftButton.size()));
	lb.setColor(backgroundColor, textColor);
	rb.setColor(backgroundColor, textColor);
	rb.setValue(rightButton);
	rb.setLeft(lb.getLeft() + lb.getWidth() +2);
	rb.setTop(lb.getTop());
	rb.setWidth((short)(rightButton.size()));
	if (((short)(value.size()) > lb.getWidth() + rb.getWidth())) setWidth((short)(value.size()) + 3);
	else setWidth(lb.getWidth() + rb.getWidth() + 4);
	setHeight(4);
}

//set the background color and the text color
void MessageBoxx::setColor(Color backgroundColor, Color textColor) {
	Control::setColor(backgroundColor, textColor);
	lb.setColor(backgroundColor, textColor);
	rb.setColor(backgroundColor, textColor);
}

//draw message box on screen
void MessageBoxx::draw(Graphics& g) {
	drawIt(g, this);
}
//draw label and two button inside the messageBox
void MessageBoxx::drawInside(Graphics& g) {
	Label::drawInside(g);
	lb.draw(g);
	rb.draw(g);
}

void MessageBoxx::mousePressed(int x, int y, bool isLeft){
	lb.setColor(getBackgroundColor(), getTextColor()); 
	rb.setColor(getBackgroundColor(), getTextColor()); 
	if (isInside(x, y, &lb)) lb.setColor(Color::Grey,Color::White);
	else if (isInside(x, y, &rb)) rb.setColor(Color::Grey, Color::White);
}

//default D'tor
MessageBoxx::~MessageBoxx(){
};
