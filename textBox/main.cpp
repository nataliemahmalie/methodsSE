#include<iostream>
#include<windows.h>
#include "TextBox.h"




int main()
{

    TextBox t(20,10);
    t.draw();
    auto handle = GetStdHandle(STD_INPUT_HANDLE);

    //auto handleout = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleCursorPosition(handleout, {0,0});
    //SetConsoleTextAttribute(handleout, (FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY) | (0 << 4));
    //int x=0;
    //int y=0;
    


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