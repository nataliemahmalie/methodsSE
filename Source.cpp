#include "../Common/Graphics.h"
#include "../Common/Label.h"
#include "../Common/EventEngine.h"
#include "../Common/TextBox.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/CheckList.h"
#include "../Common/NumericBox.h"
#include "../Common/MessageBoxx.h"
#include "../Common/RadioBox.h"
//#include "../Common/ComboBox.h"

int main(int argc, char** argv){
	EventEngine e;
	
	//Panel
	Panel p;
	p.setWidth(60);
	p.setHeight(50);
	p.setTop(6);
	p.setLeft(5);
	p.setBorder(true);				
	p.setColor(Color::White, Color::Black);		


	
	//Label
	string value("Registration form");
	//text in label
	Label l(value, Color::White, Color::Black);
	l.setTop(1);
	l.setLeft(23);
	p.add(&l);


	//TextBox 1
	TextBox tb;
	tb.setColor(Color::White, Color::Black);
	tb.setValue("Enter Name");
	tb.setWidth(30);
	tb.setHeight(1);
	tb.setTop(4);
	tb.setLeft( 0+ (short)value.size() + 1);
	p.add(&tb);


	//Radio Box
	RadioBox rb(21, 7, 5);
	rb.setColor(Color::White, Color::Black);
	p.add(&rb);

	CheckList cl(21, 14, 5);
	cl.setColor(Color::White, Color::Black);
	p.add(&cl);
	

	//NumericBox
	NumericBox nb(18, 99, 21, 21);
	nb.setColor(Color::White, Color::Black);
	p.add(&nb);

	//MessageBox
	MessageBoxx mb("GENDER", Color::White, Color::Black, 21, 25);
	p.add(&mb);


	//Button
	string test_val("Submit");				//text in button
	Button b2(test_val, Color::White, Color::Black);
	b2.setTop(31);
	b2.setLeft(27);
	p.add(&b2);

	/*
	//comboBox
	vector<string> JobTitle;
	JobTitle.push_back("software engineer");
	JobTitle.push_back("designer");
	JobTitle.push_back("civil engineer");

	ComboBox JobTitleTest(10, JobTitle);
	JobTitleTest.setBorder(BorderType::Single);
	p.add(&JobTitleTest);

	*/
	//Show Panel with controls on screen
	e.run(p);


}
