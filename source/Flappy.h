#ifndef _FLAPPY_H_
#define _FLAPPY_H_

#define START_Y           10
#define BIRD_X            5

#define G                 0.06f
#define MAX_SPEED         1.1f
#define PUSH_VEL          0.8f
#define PROCESS_INTERVAL  33

#define WORLD_HEIGHT      25
#define WORLD_WIDTH       79

#define WALL_GAP          15
#define WALL_GAP_EPSILON  2
#define WALL_DIST         10
#define WALLS_AMOUNT      8

void Init();
void Tick();
void PushBird();
void Draw();

#endif