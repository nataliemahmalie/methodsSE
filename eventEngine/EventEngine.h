#pragma once
#include <windows.h>
#include "../controlBase/ControlBase.h"
#include "../Graphics/Graphics.h"

class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(ControlBase& c);
	virtual ~EventEngine();
private:
	void moveFocus(ControlBase &main, ControlBase *focused);

	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};