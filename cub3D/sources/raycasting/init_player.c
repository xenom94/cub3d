#include "../../includes/cub3d.h"

t_mlx	*mlx_initializer(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *) malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	return (mlx);
}

void	initplayer(t_data *data)
{
	data->player.x *= TILE_SIZE ;
	data->player.y *= TILE_SIZE ;
	data->player.turndirection = 0;
	data->player.walkdirection = 0;
	data->player.straff_direction = 0;
	data->player.movespeed = 4.5;
	data->player.rotationspeed = 3.5 * (PI / 180);
}
