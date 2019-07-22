#include "controlBase.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

ControlBase::ControlBase(short height, short width, short top, short left, Color textColor, Color backgroundColor, Border borderType,bool cursorVisible,short borderOffset, string value):
    height(height), width(width),top(top), left(left), textColor(textColor), backgroundColor(backgroundColor), borderType(borderType), cursorVisible(false),borderOffset(0) { };


void ControlBase::draw() {
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(handle, &cursorInfo);

    cursorInfo.bVisible = !cursorVisible;
    SetConsoleCursorInfo(handle, &cursorInfo);

 switch(borderType){
        case None:
            borderOffset = 0;
            break;
        case Single:
            borderOffset = 1;
            drawSingleBorder();
            break;
        case Double:
            borderOffset = 2;
            drawDoubleBorder();
            break;
    }
    void ControlBase::drawSingleBorder() {
        auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

    }
    void ControlBase::drawDoubleBorder() {
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    }




    ControlBase::~ControlBase(){

    }
}