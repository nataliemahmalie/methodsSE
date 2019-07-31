#pragma once

#include <string>
#include <windows.h>

using namespace std;

enum class Color { Black, Blue, Green, Red, Cyan, Purple, Orange, White, Grey };

class Graphics
{
	public:
		Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
		void clearScreen();
		void moveTo(int x, int y);
		void setBackgroundColor(Color color);
		void setTextColor(Color color);
		void write(string s);
		void write(int x, int y, string s);
		void write(wstring s);
		void write(int x, int y, wstring s);
		void setCursorVisibility(bool isVisible);
		COORD GetCursorPosition();
		Color getBackgroundColor() { return backgroundColor; }
		Color getTextColor() { return textColor; }

	private:
		HANDLE _console;
		Color backgroundColor, textColor;
		void updateConsoleAttributes();
};

bool isInside(int x, int y, int left, int top, int width, int height);