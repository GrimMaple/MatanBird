#include "Flappy.h"
#include "Wall.h"
#include "ConsoleGraphics.h"

enum BIRD_STATE
{
	BS_FLY = 0,
	BS_PUSH
};

float      Y;
float      YSpeed;
BIRD_STATE BirdState;

int CntAfterPushed = 0;
int Score = 0;

Wall  Walls[WALLS_AMOUNT];

void CheckScore();
void CheckWalls();
bool CheckCollision();
void CheckBirdState();
void MoveWalls();

void Tick()
{
	static int tickCnt = 0;

	Y -= YSpeed;
	YSpeed -= G;
	if(YSpeed < -MAX_SPEED)
		YSpeed = -MAX_SPEED;

	CheckBirdState();

	tickCnt++;
	if(tickCnt >= 5)
	{
		MoveWalls();
		CheckScore();
		tickCnt = 0;
	}

	CheckWalls();
	if(CheckCollision())
	{
		StopMainLoop();
	}

	wchar title[256];
	wsprintf(title, L"<- MATAN BIRD -|- You've already taken %d integralls! -|", Score);
	SetConsoleTitle(title);
}

void PushBird()
{
	YSpeed = PUSH_VEL;
	BirdState = BS_PUSH;
	CntAfterPushed = 0;
}

void GenerateWall(int i)
{
	int gap;
	
  	gap = WALL_GAP + rand() % WALL_GAP_EPSILON * (rand()%3 - 1);
	
	Walls[i].x = WORLD_WIDTH;
	Walls[i].up = rand() % (WORLD_HEIGHT - gap) + 1;
	Walls[i].down = WORLD_HEIGHT - gap - Walls[i].up;
}

void InitWalls()
{
	for(int i=0; i<WALLS_AMOUNT; i++)
	{
		GenerateWall(i);
		Walls[i].x += WALL_DIST * i;
	}
}

void MoveWalls()
{
	for(int i=0; i<WALLS_AMOUNT; i++)
	{
		Walls[i].x--;
	}
}

void CheckWalls()
{
	for(int i=0; i<WALLS_AMOUNT; i++)
	{
		if(Walls[i].x < 0)
		{
			GenerateWall(i);
		}
	}
}

void CheckScore()
{
	for(int i=0; i<WALLS_AMOUNT; i++)
		if(Walls[i].x == BIRD_X - 1)
			Score += 1;
}

bool CheckCollision()
{
	if(Y > WORLD_HEIGHT)
		return true;

	if(Y < 0)
		Y = 0;

	for(int i=0; i<WALLS_AMOUNT; i++)
	{
		if(BIRD_X <= Walls[i].x && Walls[i].x <= BIRD_X + 2)
		{
			if(!(Walls[i].up < Y && Y < WORLD_HEIGHT - Walls[i].down))
				return true;
		}
	}
	return false;
}

void CheckBirdState()
{
	switch (BirdState)
	{
	case BS_FLY:
		
		break;

	case BS_PUSH:
		CntAfterPushed++;
		if(CntAfterPushed >= PUSHING_TIME)
		{
			BirdState = BS_FLY;
		}
		break;
	}
}

void InitGame()
{
	Y = START_Y;
	YSpeed = 0.0f;
	BirdState = BS_FLY;
}

void Init()
{
	SetProcessInterval(PROCESS_INTERVAL);
	InitGame();	
	InitWalls();
}

void DrawBird()
{
	switch (BirdState)
	{
	case BS_FLY:
		WritePosition(BIRD_X, Y, L"vVv");
		break;

	case BS_PUSH:
		WritePosition(BIRD_X, Y, L"^V^");
		break;
	}
}

void DrawWalls()
{
	for(int i=0; i<WALLS_AMOUNT; i++)
	{
		if(Walls[i].x < WORLD_WIDTH-1)
		{
			for(int j=0; j<Walls[i].up; j++)
				WritePosition(Walls[i].x, j, L"v");
			for(int j=0; j<Walls[i].down; j++)
				WritePosition(Walls[i].x, WORLD_HEIGHT - 1 - j, L"^");
		}
	}
}

void Draw()
{
	DrawBird();
	DrawWalls();
}