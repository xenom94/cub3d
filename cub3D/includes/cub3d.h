/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:35:26 by sisser            #+#    #+#             */
/*   Updated: 2025/04/10 08:35:29 by sisser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

# define WIN_NAME "Cub3d"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
# define PI 3.1415
# define TILE_SIZE 64
# define A_KEY 0
# define D_KEY 2
# define W_KEY 13
# define S_KEY 1
# define KEYDOWN 125
# define KEYUP 126
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define ESC 53
# define FOV 1.0471975512
# define WALL_STRIP_WIDTH 1
# define NUM_RAYS WIN_WIDTH

typedef struct s_player
{
	float	x;
	float	y;
	float	col_x;
	float	col_y;
	float	dx;
	float	dy;
	float	ang;
	int		walkdirection;
	int		turndirection;
	int		straff_direction;
	float	rotationdirection;
	float	movespeed;
	float	rotationspeed;
	t_ray	*rays;
}t_player;


typedef struct s_wall_cordinate
{
	float	top;
	float	bottom;
}			t_wall_cordinate;

typedef struct s_ray
{
	float				ray_angle;
	int					offset_x;
	int					offset_y;
	float				wall_hit_x;
	float				wall_hit_y;
	float				distance;
	float				y_step_h;
	float				x_step_h;
	float				y_step_v;
	float				x_step_v;
	float				distance_to_wall;
	float				y_intercept_h;
	float				x_intercept_h;
	float				y_intercept_v;
	float				x_intercept_v;
	float				distance_pojection_plane;
	float				wall_strip_height;
	bool				player_hit_horizontal_wall;
	bool				player_hit_vertical_wall;
	t_wall_cordinate	wall_cordinate;
}			t_ray;

typedef struct s_map2D
{
        char	**map;
        int	width;
        int	height;
}t_map2D;

typedef struct s_data
{
        char		*north_texture;
        char		*south_texture;
        char		*east_texture;
        char		*west_texture;
        int		floor_color;
        int		ceiling_color;
        t_player        player;
        t_map2D		*map2d;
        t_mlx		*mlx;
}t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

#endif
