#include "../headers/Uses.c"

/**
 * log_error - logs error to the console
 * @type: error type
 */

void log_error(const char *type)
{
	SDL_Log("%s Error: %s\n", type, SDL_GetError());
}

/**
 * rad_to_degree - convert radian to degree
 * @rad: radian value
 *
 * return: degree
 */

int rad_to_degree(double rad)
{
	return ((rad * 180) / M_PI);
}
