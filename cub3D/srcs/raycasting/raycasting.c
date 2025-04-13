#include "../../includes/cub3d.h"

void	cast_ray(t_ray *ray, t_data *data)
{
	calculate_horizontal_intercept(ray, data);
	calculate_vertical_intercept(ray, data);
	check_horizontal_intersections(ray, data);
	check_vertical_intersections(ray, data);
	distance_to_wall(ray, data);
}

void	calculate_horizontal_intercept(t_ray *ray, t_data *data)
{
	double	arc_tan;

	arc_tan = -1 / tan(ray->ray_angle);
	if (ray->ray_angle > M_PI)
	{
		ray->y_intercept_h = (int)(data->player.y / TILE_SIZE) * \
		TILE_SIZE - 0.001;
		ray->x_intercept_h = (data->player.y - ray->y_intercept_h) * \
		arc_tan + data->player.x;
		ray->y_step_h = -TILE_SIZE;
	}
	else if (ray->ray_angle < M_PI)
	{
		ray->y_intercept_h = (int)(data->player.y / TILE_SIZE) * \
		TILE_SIZE + TILE_SIZE;
		ray->x_intercept_h = (data->player.y - ray->y_intercept_h) * \
		arc_tan + data->player.x;
		ray->y_step_h = TILE_SIZE;
	}
	else if (ray->ray_angle == 0 || ray->ray_angle == M_PI)
	{
		ray->y_intercept_h = data->player.y;
		ray->x_intercept_h = data->player.x;
	}
	ray->x_step_h = -ray->y_step_h * arc_tan;
}

void	check_horizontal_intersections(t_ray *ray, t_data *data)
{
	while (ray->x_intercept_h >= 0 && ray->x_intercept_h <= WIN_WIDTH * \
		TILE_SIZE && ray->y_intercept_h >= 0 && \
		ray->y_intercept_h <= WIN_HEIGHT * TILE_SIZE)
	{
		if (has_wall_at(data, ray->x_intercept_h, ray->y_intercept_h))
			break ;
		else
		{
			ray->x_intercept_h += ray->x_step_h;
			ray->y_intercept_h += ray->y_step_h;
		}
	}
}

void	calculate_vertical_intercept(t_ray *ray, t_data *data)
{
	double	arc_tan;

	arc_tan = -tan(ray->ray_angle);
	if (ray->ray_angle > M_PI / 2 && ray->ray_angle < 3 * M_PI / 2)
	{
		ray->x_intercept_v = (int)(data->player.x / TILE_SIZE) * \
		TILE_SIZE - 0.001;
		ray->y_intercept_v = (data->player.x - ray->x_intercept_v) * \
		arc_tan + data->player.y;
		ray->x_step_v = -TILE_SIZE;
	}
	else if (ray->ray_angle < M_PI / 2 || ray->ray_angle > 3 * M_PI / 2)
	{
		ray->x_intercept_v = (int)(data->player.x / TILE_SIZE) * \
		TILE_SIZE + TILE_SIZE;
		ray->y_intercept_v = (data->player.x - ray->x_intercept_v) * \
		arc_tan + data->player.y;
		ray->x_step_v = TILE_SIZE;
	}
	else if (ray->ray_angle == M_PI / 2 || ray->ray_angle == 3 * M_PI / 2)
	{
		ray->x_intercept_v = data->player.x;
		ray->y_intercept_v = data->player.y;
	}
	ray->y_step_v = -ray->x_step_v * arc_tan;
}

void	check_vertical_intersections(t_ray *ray, t_data *data)
{
	while (ray->x_intercept_v >= 0 && ray->x_intercept_v <= WIN_WIDTH * \
		TILE_SIZE && ray->y_intercept_v >= 0 && \
		ray->y_intercept_v <= WIN_HEIGHT * TILE_SIZE)
	{
		if (has_wall_at(data, ray->x_intercept_v, ray->y_intercept_v))
			break ;
		else
		{
			ray->x_intercept_v += ray->x_step_v;
			ray->y_intercept_v += ray->y_step_v;
		}
	}
	ray->player_hit_vertical_wall = 0;
}
