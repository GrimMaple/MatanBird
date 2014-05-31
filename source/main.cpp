#include <stdio.h>
#include "ConsoleGraphics.h"
#include "Flappy.h"

int main()
{
	if(!InitConsole(L"MATAN BIRD"))
	{
		MessageBox(NULL, L"Fuck! Why did it happen!?..", L"Oh, Fuck!..", MB_ICONERROR);
		return 0;
	}

	Init();
	
	while(true)
	{
		char key;

		if(MainLoop())
		{
			Tick();

			if(KeySinglePressed(&key))
			{
				if(key == ' ') // space
					PushBird();

				if(key == 27) // escape
					break;

			}
				
			Draw();
			SwapBuffers();
		}
	}

	return 0;
}