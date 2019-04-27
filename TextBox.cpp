#include<iostream>
#include "TextBox.h"
#include<windows.h>



TextBox::TextBox(int w,int h)
{
   this->x=0;
   this->y=0;
   this->w=w;
   this->h=h;
   this->startX=5;
   this->startY=5;
}


void TextBox::keyboardEvent(KEY_EVENT_RECORD& event)
{
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(event.bKeyDown==1)
        return;


    if(event.wVirtualKeyCode==37)
    {
        if(this->x>this->startX+1)
        {
            this->x--;
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }else if(this->x==this->startX+1){
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }
    }
    else if(event.wVirtualKeyCode==39)
    {
        if(this->startX+this->w>this->x)
        {
            this->x++;
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }

    }
    else if(event.wVirtualKeyCode==38)
    {

        if(this->startY+1<this->y)
        {
            this->y--;
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }

    }
    else if(event.wVirtualKeyCode==40)
    {
        if(this->startY+this->h>this->y)
        {
            this->y++;
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }

    }
    else if(  event.wVirtualKeyCode>=32 && event.wVirtualKeyCode<=126 )
    {

        if(this->startX+this->w>=this->x)
        {
            std::cout<<(char)event.wVirtualKeyCode;
            this->x++;
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }
        else if(this->startX+this->w+1==this->x)
        {
           
            if(this->startY+this->h>this->y)
            {
                
                this->x=this->startX+1;
                this->y++;
                SetConsoleCursorPosition(handle, {this->x,this->y});
                std::cout<<(char)event.wVirtualKeyCode;
                this->x++;
                SetConsoleCursorPosition(handle, {this->x,this->y});
                
            }


        }

    }
    else if(event.wVirtualKeyCode==8)
    {
        if( (this->startX+this->w+1>=this->x) && (this->x>=this->startX+2) )
        {
            this->x--;
            SetConsoleCursorPosition(handle, {this->x,this->y});
            std::cout<<" ";
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }
        else if( (this->x==this->startX+1) && (this->y>this->startY+1) )
        {
            this->y--;
            this->x=this->startX+this->w;
            SetConsoleCursorPosition(handle, {this->x,this->y});
            std::cout<<" ";
            SetConsoleCursorPosition(handle, {this->x,this->y});
        }
    }
}



void TextBox::draw()
{   
    this->y=this->startY;
    this->x=this->startX;

    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(handle, {this->x,this->y});
    std::cout<< (char) 0xC9;
    this->x++;
    SetConsoleCursorPosition(handle, {this->x,this->y});
    for(int i=0;i<this->w;i++)
    {
        std::cout<<(char)0xCD;
        this->x++;
        SetConsoleCursorPosition(handle, {this->x,this->y});
    }
    std::cout<<(char)0xBB;
    this->y++;
  
    SetConsoleCursorPosition(handle, {this->x,this->y});
    for(int i=0;i<this->h;i++)
    {
        std::cout<<(char)0xBA;
        this->y++;
        SetConsoleCursorPosition(handle, {this->x,this->y});
    }

    std::cout<<(char)0xBC;
    this->x--;
    SetConsoleCursorPosition(handle, {this->x,this->y});

    for(int i=0;i<this->w;i++)
    {
        std::cout<<(char)0xCD;
        this->x--;
        SetConsoleCursorPosition(handle, {this->x,this->y});
    }
    
    std::cout<<(char)0xC8;
    this->y--;
    SetConsoleCursorPosition(handle, {this->x,this->y});

    for(int i=0;i<this->h;i++)
    {
        std::cout<<(char)0xBA;
        this->y--;
        SetConsoleCursorPosition(handle, {this->x,this->y});
    }
    this->y++;
    this->x++;
    SetConsoleCursorPosition(handle, {this->x,this->y});
   
}





