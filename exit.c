#include "fdf.h"

int	end_program(t_fdf *mlx)
{
	int	y;

	y = 0;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	while (y < mlx->height)
	{
		free(mlx->matrix[y]);
		y++;
	}
	free(mlx->matrix);
	exit(0);
	return (0);
}
