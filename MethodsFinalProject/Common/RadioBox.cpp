#include "RadioBox.h"

//list of option to select from
RadioBox::RadioBox(short left, short top, int optNum) : Control(left, top), arrow(0) {
	this->isClicked = true;
	isLast = false;
	this->list.push_back({ "Shenkar"  , false });
	this->list.push_back({ "Tel Aviv University"  , false });
	this->list.push_back({ "Technion"  , false });
	this->list.push_back({ "Haifa University"  , false });
	this->list.push_back({ "Afeka"  , false });	this->height = optNum;
	this->width = this->list.at(0).name.size();
};

//choose and mark the selected item
RadioBox::RadioBox() : Control(), arrow(0) {
	this->isClicked = true;
	isLast = false;
		this->list.push_back({ "Shenkar"  , false });
		this->list.push_back({ "Tel Aviv University"  , false });
		this->list.push_back({ "Technion"  , false });
		this->list.push_back({ "Haifa University"  , false });
		this->list.push_back({ "Afeka"  , false });

	this->height = 5;
	this->width = this->list.at(0).name.size();
}

//checks which key was pressed
void RadioBox::keyDown(int keyCode, char character, Graphics& g) {
	if (keyCode == VK_DOWN) this->downNavigate();
	else if (keyCode == VK_UP) this->upNavigate();
	else if (keyCode == VK_TAB) this->tabPress();
	else if (keyCode == VK_SPACE) this->choose();
}

//move cursor up by pressing the up arrow key
void RadioBox::upNavigate() { 
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
}

//move cursor down by pressing the down arrow key
void RadioBox::downNavigate() { 
	arrow = ++arrow % list.size();
}

// move arrow down by pressing the Tab key
void RadioBox::tabPress() { 
	if (arrow + 1 == list.size()) isLast = true;
	else this->downNavigate();
}

//Choose one item from the list
void RadioBox::choose() { 
	for (size_t i = 0; i < this->list.size(); i++)
		list.at(i).selectedItem = false;
	list.at(arrow).selectedItem = true;
}

//draw radio box on screen
void RadioBox::draw(Graphics& g) {
	drawIt(g, this);
}

//draw selected mark on the selected item
void RadioBox::drawInside(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selectedItem) ? "(*) " : "( ) ") + list.at(i).name + ((i == arrow) ? "  <<" : "");

		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}

//default D'tor
RadioBox::~RadioBox(){
};