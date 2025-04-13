#include "../includes/cub3d.h"

int main()
{
printf("             _    ____  _____    _____           _           _    \n");
printf("            | |  |___ \|  __ \  |  __ \         (_)         | |   \n");
printf("   ___ _   _| |__  __) | |  | | | |__) | __ ___  _  ___  ___| |_  \n");
printf("  / __| | | | '_ \|__ <| |  | | |  ___/ '__/ _ \| |/ _ \/ __| __| \n");
printf(" | (__| |_| | |_) |__) | |__| | | |   | | | (_) | |  __/ (__| |_  \n");
printf("  \___|\__,_|_.__/____/|_____/  |_|   |_|  \___/| |\___|\___|\__| \n");
printf("                                               _/ |               \n");
printf("                                            |__/                   \n");

t_data	data;

	init_game(&data);
	initplayer(&data);
	mlx_loop_hook(data.mlx->mlx_ptr, render2dmap, &data);
	mlx_hook(data.mlx->win, 02, (1L << 0), keypressed, &data);
	mlx_hook(data.mlx->win, 03, (1L << 1), keyreleased, &data);
	mlx_hook(data.mlx->win, 17, 0, &quit, &data);
	mlx_loop(data.mlx->mlx_ptr);
}