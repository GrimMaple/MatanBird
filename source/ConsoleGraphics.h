#ifndef CONSOLE_GRAPHICS_H_
#define CONSOLE_GRAPHICS_H_

#include <windows.h>

typedef wchar_t wchar;
typedef unsigned long uint;

bool InitConsole(wchar *title);
void SwapBuffers();
void Write(const wchar *buffer);
void WritePosition(int x, int y, const wchar *buffer);
void WriteSymbol(int x, int y, wchar symbol);
void SetPosition(int x, int y);

void SetConsoleCaption(const wchar *title);

bool ProcessingTime();
void SetProcessInterval(uint interval);
void DiscardProcessingTime();
bool MainLoop();
void StopMainLoop();
void ContinueMainLoop();

bool KeyPressed(char *outKey);
bool KeySinglePressed(char *outKey);
void DiscardPressedKeys();

#endif // CONSOLE_GRAPHICS_H_