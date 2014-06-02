#include <cstdlib>
#include <ctime>
#include "ConsoleGraphics.h"
#include "Flappy.h"
#include "Menu.h"

int main()
{
	srand(time(NULL));

	if(!InitConsole(L"MATAN BIRD"))
	{
		MessageBox(NULL, L"Fuck! Why did it happen!?..", L"Oh, Fuck!..", MB_ICONERROR);
		return 0;
	}

	MainMenu();

	return 0;
}