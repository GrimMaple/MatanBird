#include "Menu.h"
#include "ConsoleGraphics.h"
#include "MenuData.h"
#include "Flappy.h"

#define BUTTON_ENTER  254
#define BUTTON_ESCAPE 255

uint           SelectedItem;
int            TickCnt;

void InitMenu()
{
	SelectedItem = 0;
	TickCnt = 0;
	DiscardPressedKeys();
	DiscardProcessingTime();
}

bool MenuControlls(const MenuItem *menuItems, int *button)
{
	char key;
	if(KeySinglePressed(&key))
	{
		if(key == 80) // down
			if(menuItems[SelectedItem].belowItem >= 0)
				SelectedItem = menuItems[SelectedItem].belowItem;
		if(key == 75) // left
			if(menuItems[SelectedItem].leftItem >= 0)
				SelectedItem = menuItems[SelectedItem].leftItem;
		if(key == 77) // right
			if(menuItems[SelectedItem].rightItem >= 0)
				SelectedItem = menuItems[SelectedItem].rightItem;
		if(key == 72) // up
			if(menuItems[SelectedItem].aboveItem >= 0)
				SelectedItem = menuItems[SelectedItem].aboveItem;

		if(key == '\r' || key == ' ') // enter or space
		{
			*button = SelectedItem;
			return true;
		}

		if(key == 27) // escape
		{
			*button = BUTTON_ESCAPE;
			return true;
		}
	}
	return 0;
}

void DrawMenu(const MenuItem *menuItems, const uint menuItemsSize)
{
	for(int i=0; i<menuItemsSize; i++)
	{
		if(SelectedItem == i)
		{
			WritePosition(menuItems[i].x-1, menuItems[i].y, L">");
			WritePosition(menuItems[i].x+lstrlen(menuItems[i].caption), menuItems[i].y, L"<");
		}
		WritePosition(menuItems[i].x, menuItems[i].y, menuItems[i].caption);
	}
};


// *** *** *** MAIN MENU *** *** ***
void MainMenuAction(int itemId);
void MainMenuDrawBackground();
void DrawMatanInFire(int x, int y);

void MainMenu()
{
	InitMenu();
	SetConsoleCaption(L"<- MATAN BIRD -|- Main Menu -|");

	while(MainLoop())
	{
		int actionButton;
		if(MenuControlls(MAIN_MENU_ITEMS, &actionButton))
		{
			MainMenuAction(actionButton);
		}
		
		if(ProcessingTime())
		{
			TickCnt++;
		}

		MainMenuDrawBackground();
		DrawMatanInFire(20, 10);
		DrawMenu(MAIN_MENU_ITEMS, MAIN_MENU_ITEMS_SIZE);
		SwapBuffers();
	}
}

void MainMenuAction(int itemId)
{
	switch(itemId)
	{
	case BUTTON_PLAY:
		Play();
		InitMenu();
		SetConsoleCaption(L"<- MATAN BIRD -|- Main Menu -|");
		break;

	case BUTTON_EXIT:
	case BUTTON_ESCAPE:
		StopMainLoop();
		break;
	}
}

void MainMenuDrawBackground()
{
	for(int i=0; i<24; i++)
		WritePosition(0, i, MAIN_MENU_BACKGROUND[i]);
}

void DrawMatanInFire(int x, int y)
{
	int phase = TickCnt % 45;

	if(phase < 15)
		for(int i=0; i<8; i++)
			WritePosition(x, y+i, MATAN_IN_FIRE1[i]);
	else if(phase < 30)
		for(int i=0; i<8; i++)
			WritePosition(x, y+i, MATAN_IN_FIRE2[i]);
	else
		for(int i=0; i<8; i++)
			WritePosition(x, y+i, MATAN_IN_FIRE3[i]);
}

// *** *** *** PAUSE MENU *** *** ***
void PauseMenuAction(int itemId);
void DrawPauseMenuBackground();
void DrawBirdLogo(int x, int y);

bool PauseLoop;

void PauseMenu()
{
	InitMenu();
	PauseLoop= true;
	SetConsoleCaption(L"<- MATAN BIRD -|- Pause -|");

	while(MainLoop && PauseLoop)
	{
		int actionButton;
		if(MenuControlls(PAUSE_MENU_ITEMS, &actionButton))
		{
			PauseMenuAction(actionButton);
		}

		if(ProcessingTime())
		{
			TickCnt++;
		}

		DrawPauseMenuBackground();
		DrawBirdLogo(20, 6);
		DrawMenu(PAUSE_MENU_ITEMS, PAUSE_MENU_ITEMS_SIZE);
		SwapBuffers();
	}
}

void PauseMenuAction(int itemId)
{
	switch(itemId)
	{
	case BUTTON_CONTINUE:
	case BUTTON_ESCAPE:
		PauseLoop = false;
		DiscardProcessingTime();
		break;

	case BUTTON_EXIT_TO_MAIN_MENU:
		PauseLoop = false;
		PlayLoop = false;
		break;
	}
}

void DrawPauseMenuBackground()
{
	for(int i=0; i<24; i++)
		WritePosition(0, i, PAUSE_MENU_BACKGROUND[i]);
}

void DrawBirdLogo(int x, int y)
{
	int phase = TickCnt % 60;

	if(phase < 30)
		for(int i=0; i<14; i++)
			WritePosition(x, y+i, BIRD1[i]);
	else
		for(int i=0; i<14; i++)
			WritePosition(x, y+i, BIRD2[i]);
}