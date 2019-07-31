#include "../Common/Graphics.h"
#include "../Common/Control.h"
#include "../Common/EventEngine.h"
#include "../Common/Panel.h"
#include "../Common/Label.h"
#include "../Common/TextBox.h"
#include "../Common/RadioBox.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include "../Common/MessageBoxx.h"
#include "../Common/Button.h"
#include "../Common/ComboBox.h"

int main(int argc, char** argv){
	//screen size 
	system("mode 74,52");
	HWND consoleWindow = GetConsoleWindow(); 
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	EventEngine event;
	

	//Panel 
	Panel panel;
	panel.setWidth(64);
	panel.setHeight(42);
	panel.setTop(6);
	panel.setLeft(5);
	panel.setBorder(true);
	panel.setColor(Color::White, Color::Black);		

	
	//Label
	string value("Registration form");
	Label label(value, Color::White, Color::Red);
	label.setTop(1);
	label.setLeft(25);
	panel.add(&label);


	//Text Box 
	TextBox textBox;
	textBox.setColor(Color::White, Color::Black);
	textBox.setValue("Enter Name");
	textBox.setWidth(30);
	textBox.setHeight(1);
	textBox.setTop(4);
	textBox.setLeft( 0+ (short)value.size() + 1);
	panel.add(&textBox);


	//Radio Box
	RadioBox radioBox(21, 7, 5);
	radioBox.setColor(Color::White, Color::Black);
	panel.add(&radioBox);


	//Check List
	CheckList checkList(21, 14, 5);
	checkList.setColor(Color::White, Color::Black);
	panel.add(&checkList);


	//Numeric Box
	NumericBox numericBox(18, 120, 25, 26);
	numericBox.setColor(Color::White, Color::Black);
	panel.add(&numericBox);


	//Message Box
	MessageBoxx messageBox("GENDER", Color::White, Color::Black, 24, 31);
	panel.add(&messageBox);


	//combo box
	ComboBox comboBox(18, 120, 17, 21);
	comboBox.setColor(Color::White, Color::Black);
	panel.add(&comboBox);


	//Button
	string buttonText("Submit");	
	Button button(buttonText, Color::White, Color::Black);
	button.setTop(37);
	button.setLeft(30);
	panel.add(&button);




	event.run(panel);
}
