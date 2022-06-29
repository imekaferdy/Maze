#include "../headers/Main.h"
#include "../headers/Draw.h"
#include "../headers/Player.h"

/* APP */
APP game;

/* map */
int map[10][10];

/* player object */
PLAYER player = {
	2, /* player y */
	2, /* player x */
	5, /* player size */
	0, /* player move speed */
	0.5, /* player speed */
	0, /* player move angle */
	M_PI / 2, /* player angle */
	M_PI / 1, /* player rotation */
	{255, 0, 0, 0} /* player color */
};

SDL_Rect q = {2, 2, 8, 8};
SDL_Color pos_color = {0, 0, 0, 0};

/**
 * check_collision - checks for collision
 * @x: value
 * @y: value
 *
 * return: success
 */
bool check_collision(int x, int y)
{
	bool is_wall = false;

	if (map[x][y] != 0)
	{
		is_wall = true;
	}
	return (is_wall);
}

/**
 * update_player - checks position
 *
 * return: always success
 */
void update_player(void)
{
	double x, y, move;

	player.angle += player.moveAngle * player.angleRotation;
	move = player.speed * player.moveSpeed;

	y = player.y + sin(player.angle) * move;
	x = player.x + cos(player.angle) * move;

	if (!check_collision(y, x))
	{
		player.y = y;
		player.x = x;
	}
}

/**
 * draw_player - draws player on the screen
 *
 * return: player drawn
 */
void draw_player(void)
{
	int x, y;
	POINT pos;

	update_player();
	SDL_SetRenderDrawColor(game.renderer, 255, 0, 0, 0);
	x = player.x * SIZE;
	y = player.h * SIZE;
	draw_circle(game.renderer, x, y, player.size, player.size);
	pos.x1 = x + 2;
	pos.y1 = y;
	pos.x2 = x + cos(player.angle) * 15;
	pos.y2 = y + sin(player.angle) * 15;
	draw_line(pos);
}
