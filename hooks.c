#include "fdf.h"

static void	key_hook_rotate(int keycode, t_fdf *mlx)
{
	if (keycode == W_KEY)
		mlx->alpha += 0.1;
	else if (keycode == S_KEY)
		mlx->alpha -= 0.1;
	else if (keycode == E_KEY)
		mlx->gamma += 0.1;
	else if (keycode == Q_KEY)
		mlx->gamma -= 0.1;
	else if (keycode == A_KEY)
		mlx->beta -= 0.1;
	else if (keycode == D_KEY)
		mlx->beta += 0.1;
	else if (keycode == Z_KEY)
		mlx->angle += 0.1;
	else if (keycode == X_KEY)
		mlx->angle -= 0.1;
	else if (keycode == M_KEY)
		mlx->z += 0.1;
	else if (keycode == N_KEY)
		mlx->z -= 0.1;
}

int	key_hook(int keycode, t_fdf *mlx)
{
	if (keycode == ESC)
		end_program(mlx);
	else if (keycode == UP)
		mlx->yaxis += 30;
	else if (keycode == DOWN)
		mlx->yaxis -= 30;
	else if (keycode == LEFT)
		mlx->xaxis += 30;
	else if (keycode == RIGHT)
		mlx->xaxis -= 30;
	else if (keycode == PLUS_KEY)
		mlx->zoom += 1;
	else if (keycode == MINUS_KEY && mlx->zoom > 2)
		mlx->zoom -= 1;
	else if (keycode == SPACE)
		mlx->projection += 1;
	else if (keycode == ENTER_KEY)
		fill_fdf(mlx);
	else if (keycode == W_KEY || keycode == S_KEY || keycode == E_KEY
		|| keycode == Q_KEY || keycode == A_KEY || keycode == D_KEY
		|| keycode == Z_KEY || keycode == X_KEY || keycode == M_KEY
		|| keycode == N_KEY)
		key_hook_rotate(keycode, mlx);
	return (rerender(mlx), 0);
}

int	mouse_hook(int keycode, int x, int y, t_fdf *mlx)
{
	(void)y;
	(void)x;
	if (keycode == 5 && mlx->zoom > 2)
		mlx->zoom -= 1;
	else if (keycode == 4)
		mlx->zoom += 1;
	rerender(mlx);
	return (0);
}
