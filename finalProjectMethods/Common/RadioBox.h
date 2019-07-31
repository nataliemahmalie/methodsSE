#pragma once
#include "Control.h"
#include "Item.h"

class RadioBox: public Control
{
private:
	vector<item> list;
	short itemIndex;
	bool isSelected;
	short selected_index;
	int arrow;

public:
	RadioBox(short left, short top, int optNum);
	RadioBox();

	void keyDown(int keyCode, char character, Graphics& g);
	void upNavigate();
	void downNavigate();
	void tabPress();
	void choose();
	void draw(Graphics& g);
	virtual void drawInside(Graphics& g);
	~RadioBox();
};