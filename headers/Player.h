#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include "Structs.h"

/**
 * struct player - Player structure
 * @x: x
 * @y: y
 * @size: length
 * @move_speed: move_speed
 * @speed: speed
 * @move_angle: move_angle
 * @angle_rotation: angle_rotation
 * @color: color
 * @angle: angle
 *
 * return: always success
 */

typedef struct player
{
	int x;
	int y;
	int size;
	int move_speed;
	double speed;
	int move_angle;
	double angle_rotation;
	double angle;
	SDL_Color color;
} PLAYER;

extern PLAYER player;

/* update player */
void update_player(void);

/* draw player */
void draw_player(void);

/* check if there is collision */
bool check_collision(int x, int y);

#endif /* PLAYER_H */
