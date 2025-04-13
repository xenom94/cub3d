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

	if (x < 0 || y < 0 || x > data->textures.width || y > data->textures.height)
		return (0);
	offset = (y * data->textures.width + x) * \
	(data->textures.image[n].bits_per_pixel / 8);
	if (offset >= 0 && offset < data->textures.width * data->textures.height
		* (data->textures.image[n].bits_per_pixel / 8))
		color = *(int *)(data->textures.image[n].addr + offset);
	else
		color = 0x000000;
	return (color);
}