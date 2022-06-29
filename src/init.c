#include "../headers/Main.h"
#include "../headers/Uses.h"
#include "../headers/Structs.h"

/**
 * init - initiate sdl renderer and window
 * return: true if sdl is created and false if not
 */
bool init(void)
{
	APP game;
	bool is_init = true;
	int flags = 0;
	int renderer_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVS /
	YNC;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) /* Initialize SDL */
	{
		log_error("SDL_INIT_VIDEO");
		is_init = false;
	}

	/* creates a new window */
	game.window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, /
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);

	if (game.window == NULL)
	{
		log_error("SDL_CreateWindow");
		is_init = false;
	}

	/* create a new renderer linked to the window */
	game.renderer = SDL_CreateRenderer(game.window, -1, renderer_flags);
	
	if (game.renderer == NULL)
	{
		log_error("SDL_CreateRenderer");
		is_init = false;
	}
	return (is_init);
}

/**
 * quit - quit sdl window and renderer
 */

void quit(void)
{
	SDL_DestroyerRenderer(game.renderer);
	SDL_DestroyWindow(game.window);
}
