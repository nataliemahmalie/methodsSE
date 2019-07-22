#include <string>
#include <windows.h>
#include <vector>
#include "../Graphics/Graphics.h"

using namespace std;

enum Border{None, Single, Double};

class ControlBase
{
    private:
        short height;
        short width;
        short top;
        short left;
        short borderOffset;

        bool cursorVisible;

        Border borderType;
        Color textColor;
        Color backgroundColor;

        COORD cursorPosition;
        string value;


    public:
        ControlBase(short height, short width, short top, short left, Color textColor, Color backgroundColor, Border borderType, bool cursorVisible,short borderOffset, string value);
	    
        virtual void draw(Graphics& g, int x, int y, size_t z) {};
        virtual void draw();
        void drawSingleBorder();
        void drawDoubleBorder();
        
        //static ControlBase* getFocus() { return NULL; }
        
        string getValue(){return value;}
        Border getBorder(){return borderType;}
        short getHeight(){return height;}
        short getWidth(){return width;}
        short getTop(){return top;}
        short getLeft(){return left;}
        short getBorderOffset(){return borderOffset;}
        Color getTextColor(){return textColor;}
        Color getBackgroundColor(){return backgroundColor;}
        bool getCursorVisible(){return cursorVisible;}
        COORD getCursorPosition(){return cursorPosition;}
	    //virtual void getAllControls(vector<ControlBase*>* controls) {};

       //
        virtual bool canGetFocus() { return FALSE; };
        virtual void mousePressed(int x, int y, bool isLeft) {};
        virtual void keyDown(int keyCode, char charecter) {};
       //
        void setValue(string NewValue){value = NewValue;}
        void setBorder(Border NewBorderType){borderType = NewBorderType;}
        void setHeight(short NewHeight){height = NewHeight;}
        void setWidth(short NewWidth){width = NewWidth;}
        void setTop(short NewTop){top = NewTop;}
        void setLeft(short NewLeft){left = NewLeft;}
        void setBorderOffset(short NewBorderOffset){borderOffset = NewBorderOffset;}
        void setTextColor(Color NewTextColor){textColor = NewTextColor;}
        void setBackgroundColor(Color NewBackgroundColor){backgroundColor = NewBackgroundColor;}
        void setCursorVisible(bool NewCursorVisible){cursorVisible = NewCursorVisible;}
        void SetCursorPosition(COORD NewCursorPosition){cursorPosition = NewCursorPosition;}

        virtual ~ControlBase()=0;
};