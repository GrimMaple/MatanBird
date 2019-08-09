#include "Menu.h"
#include "ConsoleGraphics.h"
#include "MenuData.h"
#include "Flappy.h"

#include <stdio.h>

#define BUTTON_ENTER  254
#define BUTTON_ESCAPE 255

uint           SelectedItem;
int            TickCnt;
extern int     Score;

HiScoreEntry HiScores[10];

void ScoreMenu();
void LoadScores();
void GenerateScores();
void InputMenu();

void SaveScores()
{
	FILE *f = fopen("scores.dat", "wb");
	if (f == NULL)
		return;

	for (int i = 0; i < 10; i++)
	{
		fwrite(&HiScores[i].score, sizeof(int), 1, f);
		char buffer[256];
		wcstombs(buffer, HiScores[i].name, 256);
		fwrite(buffer, sizeof(char), strlen(buffer) + 1, f);
	}

	fclose(f);
}

int CompareScores(const void * a, const void * b)
{
	HiScoreEntry entry1 = *(HiScoreEntry*)a;
	HiScoreEntry entry2 = *(HiScoreEntry*)b;
	return (entry1.score > entry2.score) ? -1 : 1;
}

void SortScores()
{
	qsort(HiScores, 10, sizeof(HiScoreEntry), CompareScores);
}

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
	return false;
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

void LoadScores()
{
	wchar_t brk = '\0';
	FILE *f = fopen("scores.dat", "rb");
	if (f == NULL)
	{
		GenerateScores();
		LoadScores();
		return;
	}
	int score;
	char buffer[256];
	int s = 0;
	for (int i = 0; i < 10; i++)
	{
		s = 0;
		fread(&score, sizeof(int), 1, f);
		do
		{
			fread(buffer+s, sizeof(char), 1, f);
			s++;
		} while (*(buffer + s - 1) != 0);
		HiScores[i].score = score;
		wchar_t str[256];
		mbstowcs(str, buffer, 256);
		lstrcpyW(HiScores[i].name, str);
	}
}

void GenerateScores()
{
	char names[10][256];
	int scores[10] = { 295680, 10000, 8000, 7000, 5000, 2000, 1000, 500, 250, 100 };
	strcpy(names[0], "Kozhukhov I.B.");
	strcpy(names[1], "Sokolova T.V.");
	strcpy(names[2], "Alfimov G.V.");
	strcpy(names[3], "Khakhalin S.Y.");
	strcpy(names[4], "Shevchenko A.I.");
	strcpy(names[5], "Nazarov M.N.");
	strcpy(names[6], "Kalinnikova S.S.");
	strcpy(names[7], "Reshetnikov A.V.");
	strcpy(names[8], "Rzhavinskaya E.V.");
	strcpy(names[9], "Stukalov");

	FILE *f = fopen("scores.dat", "wb");
	if (f == NULL)
		return;

	for (int i = 0; i < 10; i++)
	{
		fwrite(&scores[i], sizeof(int), 1, f);
		fwrite(names[i], sizeof(char), strlen(names[i]) + 1, f);
	}

	fclose(f);
}


// *** *** *** MAIN MENU *** *** ***
void MainMenuAction(int itemId);
void MainMenuDrawBackground();
void DrawMatanInFire(int x, int y);
void DrawVersionInfo(int x, int y);

void MainMenu()
{
	LoadScores();
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
		DrawVersionInfo(52, 19);
		SwapBuffers();
	}
}

void MainMenuAction(int itemId)
{
	switch(itemId)
	{
	case BUTTON_PLAY:
		Play();
		if (Score > HiScores[9].score)
		{
			InputMenu();
		}
		InitMenu();
		SetConsoleCaption(L"<- MATAN BIRD -|- Main Menu -|");
		break;

	case BUTTON_SCORE:
		ScoreMenu();
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

void DrawVersionInfo(int x, int y)
{
	for (int i = 0; i<6; i++)
		WritePosition(x, y + i, VERSION[i]);
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


// *** *** *** SCORE MENU *** *** ***
void ScoreMenuDrawBackground();
void ScoreMenuAction(int itemId);

void ScoreMenu()
{
	InitMenu();
	SetConsoleCaption(L"<- MATAN BIRD -|- HI-SCORE -|");

	while (MainLoop())
	{
		int actionButton;
		if (MenuControlls(SCORE_MENU_ITEMS, &actionButton))
		{
			ScoreMenuAction(actionButton);
		}

		if (ProcessingTime())
		{
			TickCnt++;
		}

		ScoreMenuDrawBackground();
		DrawMenu(SCORE_MENU_ITEMS, SCORE_MENU_ITEMS_SIZE);
		SwapBuffers();
	}
}

void ScoreMenuDrawBackground()
{
	for (int i = 0; i<24; i++)
		WritePosition(0, i, SCORE_MENU_BACKGROUND[i]);
	int t = 4;

	for (int i = 0; i < 10; i++)
	{
		wchar_t buffer[256];
		wsprintf(buffer, L"%d. %s", i+1, HiScores[i].name);
		WritePosition(2, t, buffer);
		wsprintf(buffer, L"%d", HiScores[i].score);
		WritePosition(60, t, buffer);
		t += 2;
	}
}

void ScoreMenuAction(int itemId)
{
	switch (itemId)
	{
	case BUTTON_SCORE_EXIT:
		MainMenu();
		break;
	}
}

// *** *** *** INPUT MENU *** *** ***
void InputMenuDrawBackground();
void InputMenuAction();
void UpdateScores();

void InputMenu()
{
	InitMenu();
	SetConsoleCaption(L"<- MATAN BIRD -|- HI-SCORE -|");

	while (MainLoop())
	{
		int actionButton;

		InputMenuAction();

		if (ProcessingTime())
		{
			TickCnt++;
		}

		InputMenuDrawBackground();
		
		SwapBuffers();
	}
}

void InputMenuDrawBackground()
{
	for (int i = 0; i<24; i++)
		WritePosition(0, i, INPUT_MENU_BACKGROUND[i]);
	wchar_t buff[256];
	mbstowcs(buff, Name, 256);
	WritePosition(9, 9, buff);
}

void InputMenuAction()
{
	char key;
	if (KeySinglePressed(&key))
	{
		if ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'))
		{
			Name[NameLength] = key;
			NameLength++;
			Name[NameLength] = '\0';
		}
		if (key == 8)	// Backspace
		{
			if (NameLength == 0)
				return;
			NameLength--;
			Name[NameLength] = '\0';
		}
		if (key == 13)	// Enter
		{
			UpdateScores();
			MainMenu();
		}
	}
}

void UpdateScores()
{
	if (Score > HiScores[9].score)
	{
		HiScores[9].score = Score;
		wchar_t buff[256];
		mbstowcs(buff, Name, 256);
		wsprintf(HiScores[9].name, buff);
		SortScores();
		SaveScores();
	}
}