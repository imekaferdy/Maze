#ifndef DRAW_H
#define DRAW_H

/**
 * struct point - Data structure for drawing
 * @x1: represents x1
 * @y1: represents y1
 * @x2: represents x2
 * @y2: represents y2
 * @color: color
 *
 * return: always success
 */

typedef struct point
{
	int x1;
	int y1;
	int x2;
	int y2;
	SDL_Color color;
} POINT;

/* clear scene */
void clear_scene(void);

/* draw scene */
void draw_scene(void);

/* draw circle */
void draw_circle(SDL_Renderer *r, int x0, int y0, int radX, int radY);

/* draw line */
void draw_line(POINT p);

/* render_texture */
void render_texture(SDL_Texture *path, SDL_Renderer *renderer, SDL_Rect /
*src_rect, SDL_Rect dest_rect)

/* load image */
SDL_Texture *load_image(const char *path, SDL_Renderer *renderer);

/* load assets */
void load_assets(void);

#endif /* !DRAW_H */
