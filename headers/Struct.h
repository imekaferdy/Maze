#ifndef STRUCT_H
#define STRUCT_H

/* Window width */
#define SCREEN_WIDTH 800

/* Window Height */
#define SCREEN_HEIGHT 600

/**
 * struct Game - Windows structure
 * @window: window
 * @renderer: renderer
 *
 * return: always success
 */
typedef struct Game
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} App;

/* game */
extern App game;

#endif /* STRUCT_H */
