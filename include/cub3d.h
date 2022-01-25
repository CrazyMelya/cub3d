/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliza <cliza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:17:24 by cliza             #+#    #+#             */
/*   Updated: 2022/01/25 12:50:12 by cliza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx_opengl/mlx.h"

# define HEIGHT 1080
# define WIDTH 1920
# define TEX 240
# define MS 0.1
# define RS 0.07

extern int worldMap[30][24];

typedef struct s_ray
{
	int		check;
	int		hit;
	int		side;
	double	step;
	int		texy;
	int		texx;
	int		mapy;
	int		mapx;
	int		stepy;
	int		stepx;
	double	texpos;
	int		drawend;
	double	camerax;
	double	raydiry;
	double	raydirx;
	double	sidedistx;
	double	sidedisty;
	int		drawstart;
	double	deltadisty;
	double	deltadistx;
	int		lineheight;
	double	perpwalldist;
}			t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_texture
{
	int			x;
	int			y;
	int			size_line;
	int			endian;
	int			bpp;
	void		*img;
	char		*addr;
}				t_texture;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	e;
	int	esc;
	int	left;
	int	right;
}				t_keys;

typedef struct s_cube
{
	void		*mlx;
	void		*win;
	t_keys		*key;
	t_img		*img;
	t_texture	*tex;
	t_ray		*ray;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_cube;

void	move(t_cube *cube);
void	move_right(t_cube *cube);
void	move_left(t_cube *cube);
void	move_backward(t_cube *cube);
void	move_forward(t_cube *cube);
void	rot_right(t_cube *cube);
void	rot_left(t_cube *cube);

void	texturing(t_cube *cube, t_ray *ray, int x);
void	tex_pos_init(t_cube *cube, t_ray *ray);
void	dda(t_ray *ray);
void	step_and_side(t_cube *cube, t_ray *ray);
void	init_ray(t_cube *cube, t_ray *ray, int x);

int		get_color(t_texture *tex, int x, int y);
void	apply_pixel(t_img *img, int x, int y, int color);
int		rgb_channel(t_texture *tex, int x, int y, int i);

int		key_release(int key, t_cube *cube);
int		key_press(int key, t_cube *cube);

int		closer(void);

#endif