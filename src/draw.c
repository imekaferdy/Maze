#include "../headers/Main.h"
#include "../headers/Map.h"
#include "../headers/Draw.h"
#include "../headers/Struct.h"
#include "../headers/Player.h"


/**
 * clear_scene - clear screen
 *
 * return success
 */
void clear_scene(void)
{
	SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, 0);
	SDL_RenderClear(game.renderer);
}

/**
 * draw_scene - draws texture on the screen
 *
 * returns: success
 */
void draw_scene(void)
{
	/* APP */
	APP game;

	clearScene();
	SDL_RenderDrawColor(game.renderer, 120, 20, 120, 0);
	draw_map();
	draw_player();
	SDL_RenderPresent(game.renderer);
	SDL_Delay(10);
}

/**
 * draw_line - draws a line
 * @p: value to be entered
 *
 * return: success
 */
void draw_line(POINT p)
{
	/* APP */
	APP game;

	SDL_SetRenderDrawColor(game.renderer, p.color.r, p.color.g, /
	p.color.b, p.color.a);
	SDL_RenderDrawLine(game.renderer, p.x1, p.y1, p.x2, p.y2);
}

/**
 * draw_circle - draws a circle
 * @r: first value
 * @x0: second value
 * @y0: third value
 * @radiusX: rad value for x
 * @radiusY: rad value for y
 *
 * return: success
 */
void draw_circle(SDL_Renderer *r, int x0, int y0, int radiusX, int radiusY)
{
float pi  = 3.14159265358979323846264338327950288419716939937510;
float pih = pi / 2.0;

/* draw  28 lines with   4x4  circle with precision of 150 0ms */
/* draw 132 lines with  25x14 circle with precision of 150 0ms */
/* draw 152 lines with 100x50 circle with precision of 150 3ms */
/* precision value; value of 1 will draw a diamond, 27 makes */
/* pretty smooth circles. */

const int prec = 27;
float theta = 0; /* angle that will be increased each loo */

/* starting point */

int x  = (float)radiusX * cos(theta);
int y  = (float)radiusY * sin(theta);
int x1 = x;
int y1 = y;

/* repeat until theta >= 90 */
float step = pih / (float)prec;

for (theta = step;  theta <= pih;  theta += step)
{
/* get new point location */
x1 = (float)radiusX * cosf(theta) + 0.5;
y1 = (float)radiusY * sinf(theta) + 0.5;

/* draw line from previous point to new point, */
/* ONLY if point incremented */

if ((x != x1) || (y != y1))
{
SDL_RenderDrawLine(r, x0 + x, y0 - y, x0 + x1, y0 - y1); /* quadrant TR */
SDL_RenderDrawLine(r, x0 - x, y0 - y, x0 - x1, y0 - y1); /* quadrant TL */
SDL_RenderDrawLine(r, x0 - x, y0 + y, x0 - x1, y0 + y1); /* quadrant BL */
SDL_RenderDrawLine(r, x0 + x, y0 + y, x0 + x1, y0 + y1); /* quadrant BR */
}

/* save previous points */
x = x1;
y = y1;
}

/* arc did not finish because of rounding, so finish the arc */
if (x != 0)
{
x = 0;
SDL_RenderDrawLine(r, x0 + x, y0 - y, x0 + x1, y0 - y1); /* quadrant TR */
SDL_RenderDrawLine(r, x0 - x, y0 - y, x0 - x1, y0 - y1); /* quadrant TL */
SDL_RenderDrawLine(r, x0 - x, y0 + y, x0 - x1, y0 + y1); /* quadrant BL */
SDL_RenderDrawLine(r, x0 + x, y0 + y, x0 + x1, y0 + y1); /* quadrant BR */
}
}
