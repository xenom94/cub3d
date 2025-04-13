#include "../../includes/cub3d.h"


void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
 

// get the color of the texture to do later
int	get_texture_pixel_color(int x, int y, t_data *data, int n)
{
	int	offset;
	int	color;

	if (x < 0 || y < 0 || x > data->texture_width || y > data->texture_height)
		return (0);
	offset = (y * data->texture_height + x) * \
	(data->image[n].bits_per_pixel / 8);
	if (offset >= 0 && offset < data->texture_width * data->texture_height
		* (data->image[n].bits_per_pixel / 8))
		color = *(int *)(data->image[n].addr + offset);
	else
		color = 0x000000;
	return (color);
}

int	quit(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	exit(0);
	return (0);
}
