#ifndef MAIN_H
#define MAIN_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/* init sdl */
bool init(void);

/* quit window */
void quit(void);

/* events handler */
void input(void);

/* running state */
extern bool is_running;

/* event */
extern SDL_Event event;

#endif /* MAIN_H */
