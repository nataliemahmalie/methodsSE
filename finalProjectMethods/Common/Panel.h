#pragma once
#include "Control.h"

class Panel : public Control {
public:
	Panel();
	bool hasPanel() { return false;}
	virtual void drawInside(Graphics& g) {};
	~Panel();

};

