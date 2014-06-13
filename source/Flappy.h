#ifndef _FLAPPY_H_
#define _FLAPPY_H_

#define START_Y           5
#define BIRD_X            5

#define G                 0.05f
#define MAX_SPEED         1.1f
#define PUSH_VEL          0.57f
#define PROCESS_INTERVAL  33
#define PUSHING_TIME      8       // influences only on animation

#define WORLD_HEIGHT      25
#define WORLD_WIDTH       79

#define WALL_GAP          8 
#define WALL_GAP_EPSILON  2
#define WALL_DIST         10
#define WALLS_AMOUNT      8

typedef struct HiScoreEntry
{
	wchar_t name[256];
	int score;
};

extern int Score;
extern HiScoreEntry HiScores[10];

void Play();

#endif