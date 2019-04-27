#include<iostream>
#include<windows.h>

class TextBox
{
    private:
        int x;
        int y;
        int h;
        int w;
        int startX;
        int startY;
    public:
        TextBox(int w,int h);
        void draw();
        void keyboardEvent(KEY_EVENT_RECORD& event);
};