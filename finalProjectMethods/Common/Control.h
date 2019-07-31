#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{
	static Control* focused;

protected:
	vector<Control*> controls;
	short left;
	short top;
	short width;
	short height;
	short parentLeft;
	short parentTop;
	short cursorLoc;
	bool isFocused;
	bool isClicked;
	bool isBorder;
	bool isLast;
	Color backgroundColor;
	Color textColor;
	Control* connected_control;

public:
	Control() : isLast(false), left(1), top(1),cursorLoc(2), isFocused(true), isClicked(false), width(0), height(0), isBorder(false),parentTop(0),parentLeft(0), connected_control(NULL),backgroundColor(Color::Black),textColor(Color::White){};

	Control(short left, short top) : isFocused(true), isClicked(false), width(0), height(0), parentTop(0), parentLeft(0), isBorder(false), connected_control(NULL), backgroundColor(Color::Black), textColor(Color::White) {
		this->left = left; 
		this->top = top; 
		this->cursorLoc = getLeft()+1; 
	}
	
	static Control* getFocus() { return focused; };
	void setFocus(int x,int y);

	static void setFocus(Control& control) { focused = &control; };

	void drawIt(Graphics& g, Control* control);
	virtual void add(Control* newControl);
	virtual void draw(Graphics& g);
	virtual void mousePressed(int x, int y, bool isLeft);

	virtual void keyDown(int keyCode, char charecter, Graphics& g) {};
	virtual short getLeft() { return left+parentLeft;}
	virtual short getTop() { return top+parentTop; }
	virtual short getHeight() { return height; }
	virtual Color getBackgroundColor() { return backgroundColor; }
	virtual Color getTextColor() { return textColor; }
	virtual short getWidth() { return width; }
	virtual void getAllControls(vector<Control*>* controls);
	virtual short getCursorLoc() { return this->cursorLoc+parentLeft; }
	virtual bool getIsLast() { return isLast; }
	virtual void setParentDimensions(short left, short top) { this->parentTop = top; this->parentLeft = left; }
	virtual void setHeight(short height) { this->height = height; }
	virtual void setWidth(short width) { this->width = width; }
	virtual void setTop(short top) { this->top = top; }
	virtual void setLeft(short left) { this->left = left; setCursorLoc(left); }
	virtual void setBorder(bool border) { this->isBorder = border; }
	virtual void setIsLast(bool state) { isLast = state; }
	virtual void setCursorLoc(short value) { this->cursorLoc = value-parentLeft; }
	virtual bool canGetFocus() { return isFocused; }
	virtual bool canClick() { return isClicked; }
	virtual bool hasBorder() { return isBorder; }
	virtual bool isInside(int x, int y, Control* control);

	virtual void drawSingleBorder(Graphics& g, Control* control);
	virtual void drawDoubleBorder(Graphics& g, Control* control);
	virtual void drawNoneBorder(Graphics& g, Control* control);

	virtual void setColor(Color backgroundColor, Color textColor);
	void setConnectedControl(Control* c);
	virtual void drawInside(Graphics& g) = 0;
	~Control();
};
