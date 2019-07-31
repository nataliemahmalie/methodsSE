#include "TextBox.h"

//default C'tor with width = 30
TextBox::TextBox(short left, short top, short width = 30) : Control(left,top){
	this->width = width;
	setBorder(true);
	this->isClicked = true;
}

//add new characters to the text inside the text box
void TextBox::addValue(char newValue)
{
	short tmploca = getCursorLoc();
	if ((short)(this->value.size()) < this->width) {
		this->value.insert(this->value.begin()+ (tmploca++ - getLeft()), newValue); 
		setCursorLoc(tmploca);
	}
}

//backspace deletes text inside textbox
void TextBox::deleteChar(bool type) 
{
	short templocation = getCursorLoc();
	if (this->value.size() && ((templocation - getLeft() > 0 && !type) || (type && (templocation - getLeft())<= (short)(this->value.size())))) {
		if (!type) this->value.erase(--templocation - getLeft(), 1); 
		else this->value.erase(templocation - getLeft(), 1); 
		setCursorLoc(templocation);
	}
}

//press left arrow to move curser to the left side
void TextBox::goLeft(int x)
{
	if (getLeft() <= --x) setCursorLoc(x);	
}

//press right arrow to move curser to the right side
void TextBox::goRight(int x){
	if((short)(this->value.size()) > (x - getLeft())) setCursorLoc(x + 1);
}

//press backspace to delete, right and left arrows to move right or left on the text and the other keys to write characters and numbers
void TextBox::keyDown(int keyCode, char character, Graphics& g)
{
	switch (keyCode)
	{
	case VK_DELETE: 
	case VK_BACK:
		this->deleteChar(VK_DELETE == keyCode);
		return;
	case VK_LEFT:
		this->goLeft(g.GetCursorPosition().X);
		return;

	case VK_RIGHT:		
		this->goRight(g.GetCursorPosition().X);
		return;

	default:
		if (keyCode >= 48 && keyCode <= 126 || keyCode==32)
		this->addValue(character); 
		break;
	}

}

//draw text box on screen
void TextBox::draw(Graphics& g) {
	drawIt(g, this);
}

//draw the text inside the text box
void TextBox::drawInside(Graphics& g) {
	string temp = getValue();
	for (int i = temp.size(); i<getWidth(); i++)
		temp.push_back(' ');
	g.write(getLeft()+10, getTop(), temp);
}

//Destructor 
TextBox::~TextBox(){
	
};