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
#define BUTTON_SCORE 1
#define BUTTON_EXIT 2

const MenuItem MAIN_MENU_ITEMS[] = 
{

/*0*/{ L"Play", 5, 2, -1,  BUTTON_SCORE,    -1, -1 },
/*1*/{ L"HI-SCORE", 34, 2, BUTTON_PLAY,   BUTTON_EXIT, -1, -1 },
/*2*/ {L"Exit", 70, 2,     BUTTON_SCORE,    -1, -1,  -1},

};
const uint MAIN_MENU_ITEMS_SIZE = _MENU_ITEMS_NUMBER(MAIN_MENU_ITEMS);

const wchar MAIN_MENU_BACKGROUND[24][79] =
{
	L"                                                                              ",
	L"   +------+                     +----------+                        +------+  ",
	L"   | PLAY |                     | HI-SCORE |                        | EXIT |  ",
	L"   +------+                     +----------+                        +------+  ",
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
	L"  (                                  )  ",
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
	L"   (                                *   ", 
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
	L"   )(      )      *        (/(     (    ",
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

/*0*/ {L"Continue", 5, 2, -1, BUTTON_EXIT_TO_MAIN_MENU, -1, -1},
/*1*/ {L"Exit to main menu", 57, 2, BUTTON_CONTINUE, -1, -1, -1},

};
const uint PAUSE_MENU_ITEMS_SIZE = _MENU_ITEMS_NUMBER(PAUSE_MENU_ITEMS);

const wchar PAUSE_MENU_BACKGROUND[24][79] =
{
	L"                                                                              ",
	L"   +----------+                                        +-------------------+  ",
	L"   | CONTINUE |                                        | EXIT TO MAIN MENU |  ",
	L"   +----------+                                        +-------------------+  ",
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

const wchar BIRD1[14][50] = 
{
	L"      .--,                   .--,       ",
	L"     :   /\\                 :   /\\      ",
	L"    /   ,  \\               /   ,  \\     ",
	L"   /   /    \\             /   /    \\    ",
	L"  ;   /  ,   \\           ;   /  ,   \\   ",
	L" /   /  / \\   \\    .---./   /  / \\   \\  ",
	L"/   ;  /\\  \\   \\ /.  .//   ;  /\\  \\   \\ ",
	L"\\\"\"\"\\ /  \\  \\ ;.-' . ' \\\"\"\"\\ /  \\  \\ ;  ",
	L" `---`    `--`/___/ \\: |`---`    `--`   ",
	L"              .   \\  ' .                ",
	L"               \\   \\   '                ",
	L"                \\   \\                   ",
	L"                 \\   \\ |                ",
	L"                  '---\"                 ",
};

const wchar BIRD2[14][50] = 
{
	L"                                    ",
	L"                                    ",
	L"                                    ",
	L"          ,---.               ,---. ",
	L"         /__./|              /__./| ",
	L"    ,---.;  ; |    .---.,---.;  ; | ",
	L"   /___/ \\  | |  /.  .//___/ \\  | | ",
	L"   \\   ;  \\ ' |.-' . ' \\   ;  \\ ' | ",
	L"    \\   \\  \\: /___/ \\: |\\   \\  \\: | ",
	L"     ;   \\  ' .   \\  ' . ;   \\  ' . ",
	L"      \\   \\   '\\   \\   '  \\   \\   ' ",
	L"       \\   `  ; \\   \\      \\   `  ; ",
	L"        :   \\ |  \\   \\ |    :   \\ | ",
	L"         '---\"    '---\"      '---\"  ",
};


// *** *** *** SCORE ITEMS *** *** ***

const wchar SCORE_MENU_BACKGROUND[24][79] =
{
	L"                                                                              ",
	L"                                  +------+                                    ",
	L"                                  | EXIT |                                    ",
	L"                                  +------+                                    ",
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

#define BUTTON_SCORE_EXIT 0

const MenuItem SCORE_MENU_ITEMS[] =
{
	/*0*/{ L"Exit", 36, 2, -1, -1, -1, -1 },
};

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