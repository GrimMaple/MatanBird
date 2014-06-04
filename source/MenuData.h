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

// *** *** *** MAIN MENU *** *** ***
#define BUTTON_PLAY 0
#define BUTTON_EXIT 1

const MenuItem MAIN_MENU_ITEMS[] = 
{

/*0*/ {L"Play", 5, 2,  -1,            BUTTON_EXIT, -1,  -1},
/*1*/ {L"Exit", 70, 2,  BUTTON_PLAY,  -1,          -1,  -1},

};
const uint MAIN_MENU_ITEMS_SIZE = _MENU_ITEMS_NUMBER(MAIN_MENU_ITEMS);

const wchar MAIN_MENU_BACKGROUND[24][79] =
{
	L"                                                                              ",
	L"   +------+                                                         +------+  ",
	L"   | PLAY |                                                         | EXIT |  ",
	L"   +------+                                                         +------+  ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
};

const wchar MATAN_IN_FIRE1[8][41] =
{
	L"   *                                 )  ",
	L" (  `     (       *   )    (      ( /(  ",
	L" )\\))(    )\\    ` )  /(    )\\     )\\()) ",
	L"((_)()\\((((_)(   ( )(_))((((_)(  ((_)\\  ",
	L"(_()((_))\\ _ )\\ (_(_())  )\\ _ )\\  _((_) ",
	L"|  \\/  |(_)_\\(_)|_   _|  (_)_\\(_)| \\| | ",
	L"| |\\/| | / _ \\    | |     / _ \\  | .` | ",
	L"|_|  |_|/_/ \\_\\   |_|    /_/ \\_\\ |_|\\_| ",                        
};

const wchar MATAN_IN_FIRE2[8][41] =
{
	L"   *                                *   ", 
	L"  ((       *       (       *   ) (  ` ) ", 
	L" ())\\      `)      )\\    ` )  /(  )\\))( ",
	L" (((_)( ((_)()\\ ((((_)(   ( )(_))((_)()\\",
	L"/\\ _ )\\(_()((_)  )\\ _ )\\ (_(_()) (_()(_)",
	L"|  \\/  |(_)_\\(_)|_   _|  (_)_\\(_)| \\| | ",
	L"| |\\/| | / _ \\    | |     / _ \\  | .` | ",
	L"|_|  |_|/_/ \\_\\   |_|    /_/ \\_\\ |_|\\_| ",
};
                                        
const wchar MATAN_IN_FIRE3[8][41] =
{
	L"    )                         )  ",
	L"   )((     )      *        (/(     (    ",
	L"    )\\   )\\())  )\\))(     ))\\())   )\\   ",
	L" /((_)(  (((_)\\((_)()\\   (/((_)\\((((_)( ",
	L"/)\\ _ )\\((/_((_)(_()((_)(//_((_) )\\ _ )\\",
	L"|  \\/  |(_)_\\(_)|_   _|  (_)_\\(_)| \\| | ",
	L"| |\\/| | / _ \\    | |     / _ \\  | .` | ",
	L"|_|  |_|/_/ \\_\\   |_|    /_/ \\_\\ |_|\\_| ",
};

/*
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
	L"                                                                              ",
*/

// *** *** *** PAUSE MENU *** *** ***
#define BUTTON_CONTINUE          0
#define BUTTON_EXIT_TO_MAIN_MENU 1

const MenuItem PAUSE_MENU_ITEMS[] =
{

/*0*/ {L"Continue", 10, 10, -1, -1, -1, BUTTON_EXIT_TO_MAIN_MENU},
/*1*/ {L"Exit to main menu", 10, 12, -1, -1, BUTTON_CONTINUE, -1},

};
const uint PAUSE_MENU_ITEMS_SIZE = _MENU_ITEMS_NUMBER(PAUSE_MENU_ITEMS);

/* LOGO
 _____ ______   ________  _________  ________  ________           ________  ___  ________  ________     
|\   _ \  _   \|\   __  \|\___   ___\\   __  \|\   ___  \        |\   __  \|\  \|\   __  \|\   ___ \    
\ \  \\\__\ \  \ \  \|\  \|___ \  \_\ \  \|\  \ \  \\ \  \       \ \  \|\ /\ \  \ \  \|\  \ \  \_|\ \   
 \ \  \\|__| \  \ \   __  \   \ \  \ \ \   __  \ \  \\ \  \       \ \   __  \ \  \ \   _  _\ \  \ \\ \  
  \ \  \    \ \  \ \  \ \  \   \ \  \ \ \  \ \  \ \  \\ \  \       \ \  \|\  \ \  \ \  \\  \\ \  \_\\ \ 
   \ \__\    \ \__\ \__\ \__\   \ \__\ \ \__\ \__\ \__\\ \__\       \ \_______\ \__\ \__\\ _\\ \_______\
    \|__|     \|__|\|__|\|__|    \|__|  \|__|\|__|\|__| \|__|        \|_______|\|__|\|__|\|__|\|_______|
                                                                                                        
                                                                                                        
                                                                                                        
																										*/

#endif