#pragma once
#include "Control.h"
#include <string>
#include <iostream>

using namespace std;

class Label : public Control
{
private:
	string value;
	
public:
	Label();
	Label(string value);
	Label(string value, Color backgroundColor, Color textColor);
	Label(string value, Color backgroundColor, Color textColor, short left, short top);
	string getValue(){ return this->value;}
	void setValue(string value){
	this->setWidth((short)(value.size()));
	this->setHeight(1);
	this->value = value;}
	void setTextColor(Color color) { this->textColor = color; }
	void setBackgroundColor(Color color) { this->backgroundColor= color; }
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	~Label();
};