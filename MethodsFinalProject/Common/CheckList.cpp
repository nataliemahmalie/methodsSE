#include "CheckList.h"

//list of option to select from
CheckList::CheckList(short left, short top, int optNum) : Control(left, top), arrow(0) { 
	this->isClicked = true;
	isLast = false;
	
		this->list.push_back({ "web"  , false });
		this->list.push_back({ "cloud"  , false });
		this->list.push_back({ "algorithems"  , false });
		this->list.push_back({ "cyber"  , false });
		this->list.push_back({ "smart system"  , false });
		this->height = optNum;
		this->width = this->list.at(0).name.size();
};

//choose and mark the selected items
CheckList::CheckList() : Control(), arrow(0) {
	this->isClicked = true;
	isLast = false;
		this->list.push_back({ "web"  , false });
		this->list.push_back({ "cloud"  , false });
		this->list.push_back({ "algorithems"  , false });
		this->list.push_back({ "cyber"  , false });
		this->list.push_back({ "smart system"  , false });

	this->height = 5;
	this->width = this->list.at(0).name.size();

}

//draw check list on screen
void CheckList::draw(Graphics& g) {
	drawIt(g, this);
}

//draws selected items marks on the selected items
void CheckList::drawInside(Graphics& g) {
	string temp;
	for (size_t i = 0; i < this->list.size(); i++) {
		temp = ((list.at(i).selectedItem) ? "[x] " : "[ ] ") + list.at(i).name + ((i == arrow) ? "  <<" : "");
		g.write(this->getLeft(), this->getTop() + i, temp);
	}
}

//move cursor up by pressing the up arrow key
void CheckList::upNavigate() {
	if (arrow == 0) arrow = list.size();
	arrow = --arrow % list.size();
}

//move cursor down by pressing the down arrow key
void CheckList::downNavigate() { 
	arrow = ++arrow % list.size();
}

//move arrow down by pressing the Tab key
void CheckList::tabPress() {
	if (arrow + 1 == list.size()) isLast = true;
	else this->downNavigate();
}

//Choose one or more items from the list
void CheckList::choose() { 
	list.at(arrow).selectedItem = !list.at(arrow).selectedItem;
}

//checks which key was pressed
void CheckList::keyDown(int keyCode, char character, Graphics& g){
	if (keyCode == VK_DOWN ) this->downNavigate();
	else if (keyCode == VK_UP) this->upNavigate();
	else if (keyCode == VK_TAB) this->tabPress();
	else if (keyCode == VK_SPACE) this->choose();
}

//default D'tor
CheckList::~CheckList()
{

}