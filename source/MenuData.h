#ifndef _MENU_DATA_H_
#define _MENU_DATA_H_

#include "ConsoleGraphics.h"

struct MenuItem
{
	wchar caption[256];
	int  x, y;
	int  leftItem, rightItem;
	int  aboveItem, belowItem;
};

#define _MENU_ITEMS_NUMBER(menu_items_arr) (sizeof(menu_items_arr)/sizeof(MenuItem));

#define BUTTON_PLAY 0
#define BUTTON_EXIT 1
const MenuItem MAIN_MENU_ITEMS[] = 
{

/*0*/ {L"Play", 10, 10,  -1,  -1, -1,  BUTTON_EXIT},
/*1*/ {L"Exit", 10, 12,  -1,  -1,  BUTTON_PLAY,  -1},

};
const uint MAIN_MENU_ITEMS_SIZE = _MENU_ITEMS_NUMBER(MAIN_MENU_ITEMS);

#endif