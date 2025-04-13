/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabboudi <iabboudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 08:35:26 by sisser            #+#    #+#             */
/*   Updated: 2025/04/13 21:08:11 by iabboudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "printf/ft_printf.h"

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "../includes/minilibx/mlx.h"
#include <stdbool.h>

# define WIN_NAME "Cub3d"
# define WIN_WIDTH 1080
# define WIN_HEIGHT 720
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


typedef struct s_map2D
{
        char	**map;
        int	width;
        int	height;
}t_map2D;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;


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

typedef struct s_data
{
        char		*north_texture;
        char		*south_texture;
        char		*east_texture;
        char		*west_texture;
        int		floor_color;
        int		ceiling_color;
		int		texture_height;
		int		texture_width;
        t_player        player;
        t_map2D		*map2d;
        t_mlx		*mlx;
		t_image	image[4];
}t_data;

int	init_game(t_data **data);
int     count_correct_sides(t_map2D *map2d, int x, int y);
int     can_exit_map_from_pos(t_map2D *map2d, size_t x, size_t y);
int     check_map(t_data *map);
size_t  get_map_height_1(char **map);
size_t  get_map_width_1(char **map);
int     get_player(char **map, t_player *player);
t_map2D *dup_map2d(t_map2D *map2d);
int skip_spaces(char *line, int i);
int     line_value_size(char *line, int i);
char    *get_line_value(int prefix_len, char *line);
char    *extract_texture(char *line, t_data *map);
int     find_chr(char *str, char c);
void    *extract_color(char *line, t_data *map);
int	free_map2d(t_map2D *map2d);
void    *free_data(t_data *map);
void free_rgb(char *rgb_line, char **rgb);
char	*parse_file_map(char *file_path, t_data *data);
t_data	*setup_game(char *file_path);
int     extract_map_data(int map_fd, char **line, t_data *data);
int     check_map_extension(char *file_path);
char    *parse_file_map(char *file_path, t_data *data);
int  get_map_height(char *line);
int  get_map_width(char *line);
char    **alloc_map(char *map_line);
char    **parse_map_line(char *map_line);
char    *decimal_to_hexadecimal(int decimal);
int     check_rgb_string_format(char *rgb_string);
char    **rgb_string_to_array(char *rgb);
char    *rgb_to_hex(char *rgb);
size_t  ft_strlcpy2(char *dst, const char *src, size_t size);
int     ft_is_only(char *line, char c);
char    *ft_strappend(char **dest, char const *str);
int     ft_is_empty(char *line);
int     ft_str_contains(char *str, char c);
int     check_map_line(char *line);
int     map_content_valid(char *line);
int     valid_data(t_data *map);
char    *get_map_content(int map_fd, char **line, t_data *data);
int	has_wall_at(t_data *data, float x, float y);
void	playermovement(t_data *data);
void	draw_wall(t_data *data, int i, int j);
void	rendring(t_data *data);
int	render2dmap(t_data *data);
void	cast_all_rays(t_data *data);
int	keypressed(int keycode, t_data *data);
int	keyreleased(int keycode, t_data *data);
t_mlx	*mlx_initializer(void);
void	initplayer(t_data **data);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int	get_texture_pixel_color(int x, int y, t_data *data, int n);
void	cast_ray(t_ray *ray, t_data *data);
void	calculate_horizontal_intercept(t_ray *ray, t_data *data);
void	check_horizontal_intersections(t_ray *ray, t_data *data);
void	calculate_vertical_intercept(t_ray *ray, t_data *data);
void	check_vertical_intersections(t_ray *ray, t_data *data);
void	calculate_wall_coordinate(t_data *data, int i);
void	rays_parameters(t_data *data);
double	distance_between_points(double x1, double y1, double x2, double y2);
void	distance_to_wall(t_ray *ray, t_data *data);
int	quit(t_data *data);













#endif
