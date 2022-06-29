#include "../headers/Main.h"
#include "../headers/Draw.h"

/**
 * main - Game Loop
 * @argc: arg count
 * @argv: args
 * Return: 0
 */

int main(int argc __attribute__((unused)), char *argv[] __attribute__ : /
	((unused)))
{
	bool is_running;

	if (!init() != 0)
		exit(1);

	atexit(quit);

	while (is_running)
	{
		input();
		drawScene();
		SDL_Delay(10);
	}

	return (0);
}
