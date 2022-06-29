#include "../headers/Maini.h"
#include "../headers/Draw.h"
#include "../headers/Struct.h"
#include "../headers/Uses.h"


/**
 * load_image - loads the image
 * @path: path to the file
 * @renderer: renderer
 *
 * return: always success
 */
SDL_Texture *load_image(const char *path, SDL_Renderer *renderer)
{
	SDL_Texture *image_texture = IMG_LoadTexture(renderer, path);

	if (image_texture == NULL)
	{
		log_error("IMG_LoadTexture");
		return (NULL);
	}
	else
	{
		return (image_texture);
	}
}

/**
 * render_texture - renders texture
 * @renderer: renderer
 * @path: path to file
 * @src_rect: src rectangle
 * @dest_rect: dest rectangle
 *
 * returns: SDL_RenderCopy
 */
void render_texture(SDL_Texture *path, SDL_Renderer *renderer, SDL_Rect /
*src_rect, SDL_Rect dest_rect)
{
	SDL_Rect dest;

	if (dest.w == 0 || dest.h == 0)
	{
		dest.x = dest_rect.x;
		dest.y = dest_rect.y;
		SDL_QueryTexture(path, NULL, NULL, &dest.w, &dest.h);
		SDL_RenderCopy(renderer, path, src_rect, &dest);
	}

	SDL_RenderCopy(renderer, path, src_rect, &dest_rect);
}
