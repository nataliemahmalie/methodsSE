#pragma once
#include "Control.h"
#include "Item.h"

class CheckList: public Control{
private:
	vector<item> list;
	int arrow;
public:
	CheckList();
	CheckList(short left, short top, int optNum);

	void keyDown(int keyCode, char character, Graphics& g);
	void upNavigate();
	void downNavigate();
	void tabPress();
	void choose();
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	~CheckList();

};

