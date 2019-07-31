#include "ComboBox.h"

//combo box to choose one option between 1 to 3 with + symbol to open the list and - symbol to hide it 
ComboBox::ComboBox(int min = 1, int max = 3, short left = 0, short top = 0) : TextBox(left, top, 20) {
	this->min = min;
	this->max = max;
	this->openCloseFlag=0;
	isFocused = false; 

	setHeight(3);

	plus.setValue(" + ");			
	plus.setLeft(getLeft()+28);
	plus.setTop(getTop()+1);
	plus.setWidth(3);

	option_1.setValue("option 1");
	option_1.setLeft(getLeft()+6);
	option_1.setTop(getTop()+10);
	option_1.setWidth(30);
	option_1.setBackgroundColor(Color::White);
	option_1.setTextColor(Color::Black);

	option_2.setValue("option 2");
	option_2.setLeft(getLeft()+6);
	option_2.setTop(getTop()+13);
	option_2.setWidth(30);
	option_2.setBackgroundColor(Color::White);
	option_2.setTextColor(Color::Black);


	option_3.setValue("option 3");
	option_3.setLeft(getLeft()+6);
	option_3.setTop(getTop()+16);
	option_3.setWidth(30);
	option_3.setBackgroundColor(Color::White);
	option_3.setTextColor(Color::Black);


	value.setValue("Combo Box");
	value.setLeft(getLeft()+1);
	value.setTop(getTop()+1);
	value.setWidth(25);
	value.setBackgroundColor(Color::White);
	value.setTextColor(Color::Black);

	value.setValue("Combo Box");

	setWidth(32);
}

//set background color and text color to the combo box
void ComboBox::setColor(Color backgroundColor, Color textColor) {
	Control::setColor(backgroundColor, textColor);
	plus.setColor(backgroundColor, textColor);

}

//draw combo box on screen
void ComboBox::draw(Graphics& g) {
	drawIt(g, this);
}

//draw the combo box with + and - symbols
void ComboBox::drawInside(Graphics& g) {
	if(this->openCloseFlag==0){
				
		plus.setValue(" + ");
		value.draw(g);
		plus.draw(g);
	}
	else{
		
		plus.setValue(" - ");
		value.draw(g);
		plus.draw(g);
		option_1.draw(g);
		option_2.draw(g);
		option_3.draw(g);
	}	
}

void ComboBox::mousePressed(int x, int y, bool isLeft) {
	if (isInside(x, y, &plus)){
		if(this->openCloseFlag==0){
			this->openCloseFlag=1;
			setHeight(12);			
		}
		else{
			this->openCloseFlag=0;
			setHeight(3);
		}
	}

	if (isInside(x, y, &option_1)){

		value.setValue("option 1");
		option_1.setBackgroundColor(Color::Green);
		option_2.setBackgroundColor(Color::White);
		option_3.setBackgroundColor(Color::White);

	}

	if (isInside(x, y, &option_2)){

		value.setValue("option 2");
		option_2.setBackgroundColor(Color::Green);
		option_1.setBackgroundColor(Color::White);
		option_3.setBackgroundColor(Color::White);

	}

	if (isInside(x, y, &option_3)){

		value.setValue("option 3");
		option_3.setBackgroundColor(Color::Green);
		option_1.setBackgroundColor(Color::White);
		option_2.setBackgroundColor(Color::White);

	}

}

//default D'tor
ComboBox::~ComboBox(){

};