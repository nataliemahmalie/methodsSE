#include "Control.h"


Control* Control::focused = NULL;

void Control::draw(Graphics& g) {
	this->drawIt(g,this);
	for(int i=0;i<this->controls.size();i++){
		if(this->controls[i]!=NULL){
			this->controls[i]->draw(g);
		}
	}
}

void Control::drawIt(Graphics& g, Control* control) {
	Color oldBack = g.getBackgroundColor();
	Color oldFore = g.getTextColor();
	g.setBackgroundColor(control->getBackgroundColor());
	g.setTextColor(control->getTextColor());
	string temp = " ";
	temp.resize(control->getWidth());
	for (short i = 0; i < control->getHeight(); i++)
		g.write(control->getLeft(), control->getTop() + i, temp);
	if (control->hasBorder()) 
	{ 
		control->drawSingleBorder(g,control);
		
	}
	//else if(control->hasBorder() && ...........)
	//	{
	//	control->drawDoubleBorder(g,control);
	//	}
	else
			control->drawNoneBorder(g,control);

	control->drawInside(g);
	g.setBackgroundColor(oldBack);
	g.setTextColor(oldFore);
}

//draw single border frame
void Control::drawSingleBorder(Graphics& g, Control* control){
	g.write(control->getLeft() - 1, control->getTop() - 1, "\xDA"); 
	g.write(control->getLeft() + control->getWidth(), control->getTop() - 1, "\xBF"); 
	g.write(control->getLeft() - 1, control->getTop()+control->getHeight(), "\xC0"); 
	g.write(control->getLeft() + control->getWidth(), control->getTop()+control->getHeight(), "\xD9"); 

	for (short i = 0; i < control->getHeight(); i++) { 
		g.write(control->getLeft() - 1, control->getTop() + i, "\xB3");
		g.write(control->getLeft() + control->getWidth(), control->getTop() + i, "\xB3");
	}
	for (short i = 0; i < width; i++){ 
		g.write(control->getLeft() + i, control->getTop() - 1, "\xC4");
		g.write(control->getLeft() + i, control->getTop() + control->getHeight(), "\xC4");
	}
	g.moveTo(control->getLeft(), control->getTop());
}

//draw double border frame
void Control:: drawDoubleBorder(Graphics& g, Control* control){
	g.write(control->getLeft() - 1, control->getTop() - 1, "\xC9"); 
	g.write(control->getLeft() + control->getWidth(), control->getTop() - 1, "\xBB"); 
	g.write(control->getLeft() - 1, control->getTop()+control->getHeight(), "\xC8"); 
	g.write(control->getLeft() + control->getWidth(), control->getTop()+control->getHeight(), "\xBC"); 

	for (short i = 0; i < control->getHeight(); i++) { 
		g.write(control->getLeft() - 1, control->getTop() + i, "\xBA");
		g.write(control->getLeft() + control->getWidth(), control->getTop() + i, "\xBA");
	}
	for (short i = 0; i < width; i++){ 
		g.write(control->getLeft() + i, control->getTop() - 1, "\xCD");
		g.write(control->getLeft() + i, control->getTop() + control->getHeight(), "\xCD");
	}
	g.moveTo(control->getLeft(), control->getTop());
}

// draw none border frame
void Control::drawNoneBorder(Graphics& g, Control* control){
	g.write(control->getLeft() - 1, control->getTop() - 1, "\x20"); 
	g.write(control->getLeft() + control->getWidth(), control->getTop() - 1, "\x20"); 
	g.write(control->getLeft() - 1, control->getTop()+control->getHeight(), "\x20"); 
	g.write(control->getLeft() + control->getWidth(), control->getTop()+control->getHeight(), "\x20"); 

	for (short i = 0; i < control->getHeight(); i++) { 
		g.write(control->getLeft() - 1, control->getTop() + i, "\x20");
		g.write(control->getLeft() + control->getWidth(), control->getTop() + i, "\x20");
	}
	for (short i = 0; i < width; i++){ 
		g.write(control->getLeft() + i, control->getTop() - 1, "\x20");
		g.write(control->getLeft() + i, control->getTop() + control->getHeight(), "\x20");
	}
	g.moveTo(control->getLeft(), control->getTop());
}

void Control::getAllControls(vector<Control*>* controlsCopy) {
	for (size_t i = 0; i < controls.size(); i++)
		(*controlsCopy).push_back(controls[i]);
};

void Control::add(Control* newControl){
	if (newControl) {
		newControl->setParentDimensions(this->getLeft(),this->getTop());
		this->controls.push_back(newControl);
	}
}

//set background color and text color 
void Control::setColor(Color backgroundColor, Color textColor){
	this->backgroundColor = backgroundColor;
	this->textColor = textColor;
}

void Control::setConnectedControl(Control *c)
{
	connected_control = c;
}
bool Control::isInside(int x, int y,Control* control){
	x -= control->getLeft();
	y -= control->getTop(); 
	return x >= 0 && y >= 0 && x < control->getWidth() && y < control->getHeight();
}

void Control::mousePressed(int x, int y, bool isLeft) {
	if (isLeft)
	{
		for(int i=0;i<this->controls.size();i++){
		
			if(this->controls[i]->isClicked && isInside(x,y,this->controls[i])){
				return this->controls[i]->mousePressed(x, y,isLeft);
			}
		}
	}
}

//focus every time on one spot
void Control::setFocus(int x, int y) {
	for(int i=0;i<this->controls.size();i++)
	{
		if(this->controls[i]->canGetFocus() && isInside(x,y,this->controls[i]))
		{
			setFocus(*this->controls[i]);
		}		
	}
}

// D'tor
Control::~Control() {
	for(int i=0;i<this->controls.size();i++){
		if(this->controls[i]!=NULL){
			delete this->controls[i];
		}
	}
}