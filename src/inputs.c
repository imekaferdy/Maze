#include "../headers/Main.h"
#include "../headers/Map.h"
#include "../headers/Draw.h"
#include "../headers/Player.h"


/**
 * input - SDL_Event
 *
 * return: success
 */
void input(void)
{
	PLAYER player;
	SDL_Event event;
	bool is_running = true;

	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
			case SDL_QUIT:
				is_running = false;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
						player.moveSpeed = -1;
						break;

					case SDLK_DOWN:
						player.movespeed = 1;
						break;

					case SDLK_LEFT:
						player.moveAngle = -1;
						break;

					case SDLK_RIGHT:
						player.moveAngle = 1;
						break;
				}
				break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
					case SDLK_UP:
                                                player.moveSpeed = 0;
                                                break;

                                        case SDLK_DOWN:
                                                player.movespeed = 0;
                                                break;

                                        case SDLK_LEFT:
                                                player.moveAngle = 0;
                                                break;

                                        case SDLK_RIGHT:
                                                player.moveAngle = 0;
                                                break;
				}
				break;
		}
	}
}
