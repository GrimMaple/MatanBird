#ifndef CONSOLE_GRAPHICS_H_
#define CONSOLE_GRAPHICS_H_

#include <windows.h>

typedef wchar_t wchar;
typedef unsigned long uint;

bool InitConsole(wchar *title);
void SwapBuffers();
void Write(wchar *buffer);
void WritePosition(int x, int y, wchar *buffer);
void WriteSymbol(int x, int y, wchar symbol);
void SetPosition(int x, int y);
void SetProcessInterval(uint interval);
bool MainLoop();
void StopMainLoop();

bool KeyPressed(char *outKey);
bool KeySinglePressed(char *outKey);

#endif // CONSOLE_GRAPHICS_H_