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

bool MenuControlls(int *button)
{
	char key;
	if(KeySinglePressed(&key))
	{
		if(key == 80) // down
			if(MenuItems[SelectedItem].belowItem >= 0)
				SelectedItem = MenuItems[SelectedItem].belowItem;
		if(key == 75) // left
			if(MenuItems[SelectedItem].leftItem >= 0)
				SelectedItem = MenuItems[SelectedItem].leftItem;
		if(key == 77) // right
			if(MenuItems[SelectedItem].rightItem >= 0)
				SelectedItem = MenuItems[SelectedItem].rightItem;
		if(key == 72) // up
			if(MenuItems[SelectedItem].aboveItem >= 0)
				SelectedItem = MenuItems[SelectedItem].aboveItem;

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

void DrawMenu()
{
	for(int i=0; i<MenuItemsSize; i++)
	{
		if(SelectedItem == i)
		{
			WritePosition(MenuItems[i].x-1, MenuItems[i].y, L">");
			WritePosition(MenuItems[i].x+lstrlen(MenuItems[i].caption), MenuItems[i].y, L"<");
		}
		WritePosition(MenuItems[i].x, MenuItems[i].y, MenuItems[i].caption);
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
		if(MenuControlls(&actionButton))
		{
			MainMenuAction(actionButton);
		}

		DrawMenu();
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