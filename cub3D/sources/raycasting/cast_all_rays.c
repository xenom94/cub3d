#include "../../includes/cub3d.h"

void	cast_all_rays(t_data *data)
{
	float	ray_angle;
	int		i;

	i = 0;
	data->player.rays = (t_ray *) malloc(NUM_RAYS * sizeof(t_ray));
	ray_angle = angles_normalizer(data->player.ang - (FOV / 2));
	while (i < NUM_RAYS)
	{
		data->player.rays[i].ray_angle = angles_normalizer(ray_angle);
		cast_ray(&data->player.rays[i], data);
		ray_angle += FOV / NUM_RAYS;
		i++;
	}
}
