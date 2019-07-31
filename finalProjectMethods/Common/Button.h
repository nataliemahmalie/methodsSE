#pragma once
#include "Label.h"

//button inherits from label for the text on the button
class Button : public Label {
public:
	Button();
	Button(string s);
	Button(string value, Color backgroundColor, Color textColor);
	virtual void mousePressed(int x, int y, bool isLeft);
	virtual ~Button();
};

