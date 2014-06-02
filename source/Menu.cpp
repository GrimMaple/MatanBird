#include "Menu.h"
#include "ConsoleGraphics.h"
#include "MenuData.h"
#include "Flappy.h"

#define BUTTON_ENTER  254
#define BUTTON_ESCAPE 255

const MenuItem *MenuItems;
uint           MenuItemsSize;
uint           SelectedItem;

void InitMenu()
{
	SelectedItem = 0;
	DiscardPressedKeys();
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

void MainMenu()
{
	InitMenu();
	MenuItems = MAIN_MENU_ITEMS;
	MenuItemsSize = MAIN_MENU_ITEMS_SIZE;

	while(MainLoop())
	{
		int actionButton;
		if(MenuControlls(MAIN_MENU_ITEMS, &actionButton))
		{
			MainMenuAction(actionButton);
		}

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
		break;

	case BUTTON_EXIT:
	case BUTTON_ESCAPE:
		StopMainLoop();
		break;
	}
}

// *** *** *** PAUSE MENU *** *** ***
void PauseMenuAction(int itemId);

bool PauseLoop;

void PauseMenu()
{
	InitMenu();
	MenuItems = PAUSE_MENU_ITEMS;
	MenuItemsSize = PAUSE_MENU_ITEMS_SIZE;
	PauseLoop= true;

	while(MainLoop && PauseLoop)
	{
		int actionButton;
		if(MenuControlls(PAUSE_MENU_ITEMS, &actionButton))
		{
			PauseMenuAction(actionButton);
		}

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