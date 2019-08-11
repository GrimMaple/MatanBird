#include "ConsoleGraphics.h"
#include <string.h>
#include <conio.h>

#define CONSOLE_WIDTH	80
#define CONSOLE_HEIGHT  25

HANDLE   BackBuffer = NULL;
HANDLE	 FrontBuffer = NULL;

uint     LastProcessTime = 0;
uint     ProcessInterval = 33;

bool     Keys[256];

bool     MainLoopStopped = false;

bool InitConsole(wchar *title)
{
	BackBuffer = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	if(!BackBuffer)
		return false;

	FrontBuffer = CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
	if(!FrontBuffer)
		return false;

	SetConsoleActiveScreenBuffer(FrontBuffer);
	SetConsoleTitle(title);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 1;
	SetConsoleCursorInfo(BackBuffer, &cci);
	SetConsoleCursorInfo(FrontBuffer, &cci);

	DiscardProcessingTime();

   return true;
}

void ClearBackBuffer()
{
	for(int i=0; i<80; i++)
	{
		Write(L"\n");
	}
}

void SwapBuffers()
{
	HANDLE tmp;
	tmp =  BackBuffer;
	BackBuffer = FrontBuffer;
	FrontBuffer = tmp;
	SetConsoleActiveScreenBuffer(FrontBuffer);
	ClearBackBuffer();
}

void Write(const wchar *buffer)
{
	WriteConsole(BackBuffer, buffer, lstrlen(buffer), NULL, NULL);
}

void WriteOneSymbol(wchar symbol)
{
	WriteConsole(BackBuffer, &symbol, 1, NULL, NULL);
}

void SetPosition(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(BackBuffer, point);
}

void SetConsoleCaption(wchar *format, ...)
{
	va_list ap;
	wchar   title[256];

	va_start(ap, format);
	wvsprintf(title, format, ap);
	va_end(ap);
	
	SetConsoleTitle(title);
}

void WritePosition(int x, int y, const wchar *buffer)
{
	SetPosition(x, y);
	Write(buffer);
}

void WriteSymbol(int x, int y, wchar symbol)
{
	SetPosition(x, y);
	WriteOneSymbol(symbol);
}

void SetProcessInterval(uint interval)
{
	ProcessInterval = interval;
}

bool MainLoop()
{
	return (!MainLoopStopped);
}

bool ProcessingTime()
{
	if(MainLoopStopped)
		return false;

	uint currentTime = timeGetTime();

	if(currentTime >= LastProcessTime + ProcessInterval)
	{
		LastProcessTime += ProcessInterval;
		return true;
	}

	return false;
}

void DiscardProcessingTime()
{
	LastProcessTime = timeGetTime();
}

void StopMainLoop()
{
	MainLoopStopped = true;
}

void ContinueMainLoop()
{
	MainLoopStopped = false;
}

bool KeyPressed(char *outKey)
{
	if( _kbhit() )
	{
		int key = getch();
		if(key == 224)
			key = getch();
		if(key < 256)
		{
			*outKey = (char)(key);			
			return true;
		}
	}

	return false;
}

bool KeySinglePressed(char *outKey)
{
	if( _kbhit() )
	{
		int key = getch();
		if(key == 224)
			key = getch();
		if(key < 256)
		{
			*outKey = (char)(key);

			if(Keys[key] == true)
				return false;
			Keys[key] = true;
			
			return true;
		}
	}

	memset(Keys, 0, sizeof(Keys));
	return false;
}

void DiscardPressedKeys()
{
	while( _kbhit() )
	{
		int key = getch();
	}
}