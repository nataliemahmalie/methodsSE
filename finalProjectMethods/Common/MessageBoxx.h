#pragma once
#include "Label.h"
#include "Button.h"
#include <string>


class MessageBoxx : public Label {
protected:
	Button lb;
	Button rb;
public:
	MessageBoxx(string value, Color backgroundColor, Color textColor, short left, short top);
	virtual void setColor(Color backgroundColor, Color textColor);
	virtual void setParentDimensions(short left, short top) { 
		this->parentTop = top; 
		this->parentLeft = left; 
		lb.setParentDimensions(left, top);
		rb.setParentDimensions(left, top);
	};
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual ~MessageBoxx();
};
