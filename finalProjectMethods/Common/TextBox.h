#pragma once
#include "Control.h"

class TextBox : public Control
{
	string value;

public:
	TextBox() : Control(){setBorder(true);}
	TextBox(short left, short top, short width);

	string getValue() { return this->value;}
	void setValue(string value) { this->value = value;}
	void addValue(char newValue);
	void deleteChar(bool type);
	void goLeft(int x);
	void goRight(int x);
	void keyDown(int keyCode, char character, Graphics& g);
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	~TextBox();
};
