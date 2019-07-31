#pragma once
#include "TextBox.h"
#include "Button.h"
#include <string>
#include "Label.h"







class ComboBox : public TextBox{
protected:
	int min;
	int max;
	int actual;
	Button plus;
	Label value;
	Label option_1;
	Label option_2;
	Label option_3;
	int openCloseFlag;
public:
	ComboBox(int min,int max,short left,short top);
	void setActual(int val) { this->actual = val;}
	int getActual() { return this->actual;}
	virtual void setColor(Color backgroundColor, Color textColor);
	virtual void setParentDimensions(short left, short top){
		this->parentTop = top;
		this->parentLeft = left;
		plus.setParentDimensions(left, top);
		
		this->value.setParentDimensions(left,top);
	};
	virtual void mousePressed(int x, int y, bool isLeft);
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	virtual ~ComboBox();
};








