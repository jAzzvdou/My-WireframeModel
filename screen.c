/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:05:33 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/11 19:06:47 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if (y > HEIGHT || x > WIDTH - MENU_WIDTH || x < 0 || y < 0)
		return ;
	pixel = fdf->addr + (y * fdf->line_size + x * (fdf->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	mlxputstr(t_fdf *fdf, int y, int color, char *s)
{
	int	pos;

	pos = WIDTH - MENU_WIDTH + 10;
	mlx_string_put(fdf->mlx, fdf->win, pos, y, color, s);
	return (0);
}

void	menu(t_fdf *fdf)
{
	int	i;
	int	pos;
	int	line;
	int	color;

	pos = WIDTH - MENU_WIDTH + 10;
	i = HEIGHT / 2;
	line = HEIGHT;
	while (line--)
	{
		color = paint(i, -(HEIGHT / 2), HEIGHT / 2);
		mlx_pixel_put(fdf->mlx, fdf->win, pos - 10, line, color);
		i--;
	}
	mlxputstr(fdf, 25, paint(-4, -4, 5), "Close: Esc");
	mlxputstr(fdf, 50, paint(-3, -4, 5), "2D/3D: Space");
	mlxputstr(fdf, 75, paint(-2, -4, 5), "Move: > < ^ v");
	mlxputstr(fdf, 100, paint(-1, -4, 5), "Zoom: scroll +/-");
	mlxputstr(fdf, 125, paint(0, -4, 5), "Spin Z: Z/X");
	mlxputstr(fdf, 150, paint(1, -4, 5), "Rotate Z: Q/E");
	mlxputstr(fdf, 175, paint(2, -4, 5), "Rotate X: W/S");
	mlxputstr(fdf, 200, paint(3, -4, 5), "Rotate Y: A/D");
	mlxputstr(fdf, 225, paint(4, -4, 5), "3D Depth: M/N");
	mlxputstr(fdf, 250, paint(5, -4, 5), "Reset: Enter");
}

int	rerender(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH - MENU_WIDTH, HEIGHT);
	put_points(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	menu(fdf);
	return (0);
}

int	make_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "| AZ's FDF |");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH - MENU_WIDTH, HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, \
			&fdf->line_size, &fdf->endian);
	put_points(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	menu(fdf);
	mlx_hook(fdf->win, KEY_PRESS_EVENT, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->win, MOUSE_PRESS_EVENT, 1L << 2, mouse_hook, fdf);
	mlx_hook(fdf->win, DESTROY_EVENT, 1L << 2, end_program, fdf);
	mlx_hook(fdf->win, ENTER_EVENT, 1L << 04, rerender, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
