#include<iostream>
#include<windows.h>
#include "TextBox.h"




int main()
{

    TextBox t(20,10);
    t.draw();
    auto handle = GetStdHandle(STD_INPUT_HANDLE);
    

        while(1)
        {
            INPUT_RECORD ir;
            DWORD count;
            ReadConsoleInput(handle, &ir, 1, &count);
            if(ir.EventType==1)
            {
                t.keyboardEvent(ir.Event.KeyEvent);
            }
        }

    return 1;
}
