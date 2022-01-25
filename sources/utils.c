#include "../include/cub3d.h"

int	key_press(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 1;
	if (key == 1)
		cube->key->s = 1;
	if (key == 0)
		cube->key->a = 1;
	if (key == 2)
		cube->key->d = 1;
	if (key == 123)
		cube->key->left = 1;
	if (key == 124)
		cube->key->right = 1;
	if (key == 53)
		closer();
	return (0);
}

int	key_release(int key, t_cube *cube)
{
	if (key == 13)
		cube->key->w = 0;
	if (key == 1)
		cube->key->s = 0;
	if (key == 0)
		cube->key->a = 0;
	if (key == 2)
		cube->key->d = 0;
	if (key == 123)
		cube->key->left = 0;
	if (key == 124)
		cube->key->right = 0;
	return (0);
}

int	rgb_channel(t_texture *tex, int x, int y, int i)
{
	char			*dst;
	unsigned char	color;

	dst = tex->addr + ((y * tex->size_line) + x * (tex->bpp / 8));
	color = *(dst + i);
	
	return (color);
}

int	get_color(t_texture *tex, int x, int y)
{
	int	r;
	int	g;
	int	b;

	r = rgb_channel(tex, x, y, 2);
	g = rgb_channel(tex, x, y, 1);
	b = rgb_channel(tex, x, y, 0);
	return (r << 16 | g << 8 | b);
}

void	apply_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
