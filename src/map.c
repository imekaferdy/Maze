#include "../headers/Main.h"
#include "../headers/Structs.h"
#include "../headers/Map.h"

/**
 * draw_map - draws a 2d map
 */
void draw_map(void)
{
	/* map */
        int map[10][10] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                {1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int i, k;
	APP game;

	/* map rectangle */
	SDL_Rect rectangle;
	/* map color */
	SDL_Color map_color = {16, 16, 16, 0};

	rectangle.w = SIZE;
	rectangle.h = SIZE;

	SDL_SetRendererDrawColor(game.renderer, map_color.r, map_color.g, /
	map_color.b, map_color.a);

	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
		{
			if (map[i][k] == 1)
			{
				rectangle.x = k * SIZE;
				rectangle.y = i * SIZE;
				SDL_RenderFillRect(game.renderer, &rectangle);
			}
		}
	}
}
