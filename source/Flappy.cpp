#include "Flappy.h"
#include "Wall.h"
#include "ConsoleGraphics.h"

float Y;
float YSpeed;

int   CntAfterPushed = 0;
float IntegrallsTaken = 0;

Wall  Walls[WALLS_AMOUNT];

void CheckWalls();
bool CheckCollision();

void Tick()
{
	static int tickCnt = 0;

	Y -= YSpeed;
	YSpeed -= G;
	if(YSpeed < -MAX_SPEED)
		YSpeed = -MAX_SPEED;

	if(CntAfterPushed > 0)
		CntAfterPushed++;
	if(CntAfterPushed > 5)
		CntAfterPushed = 0;

	tickCnt++;
	if(tickCnt >= 5)
	{
		for(int i=0; i<WALLS_AMOUNT; i++)
		{
			Walls[i].x--;
			tickCnt = 0;
		}
	}

	CheckWalls();
	if(CheckCollision())
	{
		StopMainLoop();
	}

	wchar title[256];
	wsprintf(title, L"<- MATAN BIRD -|- You've already taken %d integralls! -|", (int)(IntegrallsTaken));
	SetConsoleTitle(title);
}

void PushBird()
{
	YSpeed = PUSH_VEL;
	CntAfterPushed = 1; // deal with it
}

void GenerateWall(int i)
{
	int gap;
	
  	gap = WALL_GAP + rand() % WALL_GAP_EPSILON * (rand()%3 - 1);
	
	Walls[i].x = WORLD_WIDTH;
	Walls[i].up = rand() % (WORLD_HEIGHT - gap) + 1;
	//Walls[i].down = gapBottom+1;
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

void CheckWalls()
{
	for(int i=0; i<WALLS_AMOUNT; i++)
	{
		if(Walls[i].x == BIRD_X - 1)
			IntegrallsTaken += 0.2f;

		if(Walls[i].x < 0)
		{
			GenerateWall(i);
		}
	}
}

bool CheckCollision()
{
	if(Y < 0 || Y >= WORLD_HEIGHT)
		return true;

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

void InitGame()
{
	Y = START_Y;
	YSpeed = 0.0f;
}

void Init()
{
	SetProcessInterval(PROCESS_INTERVAL);
	InitGame();	
	InitWalls();
}

void DrawBird()
{
	if(CntAfterPushed == 0)
		WritePosition(BIRD_X, Y, L"^V^");
	else
		WritePosition(BIRD_X, Y, L"vVv");
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