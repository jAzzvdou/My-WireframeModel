#include "fdf.h"

void	bresenham(t_fdf *fdf, t_bresenham bres)
{
	if (bres.z[0] == 0)
		fdf->color = 0x00FF00;
	else if (bres.z[0] > 0)
		fdf->color = 0xFF0000;
	else if (bres.z[0] < 0)
		fdf->color = 0x0000FF;
	add_zoom(&bres, fdf->zoom);
	if (fdf->projection % 2 == 0)
	{
		rotate(&bres, fdf);
		add_3d(&bres, fdf);
	}
	add_position(&bres, fdf);
	add_steps(&bres);
	while ((int)(bres.x[0] - bres.x[1]) || (int)(bres.y[0] - bres.y[1]))
	{
		my_mlx_pixel_put(fdf, bres.x[0], bres.y[0], fdf->color);
		bres.x[0] += bres.dx;
		bres.y[0] += bres.dy;
	}
}

void	bres_caller(t_bresenham *bres, t_fdf *fdf)
{
	bres->x[1] = bres->x[0] + 1;
	bres->y[1] = bres->y[0];
	if (bres->x[0] < fdf->width - 1)
	{
		bres->z[0] = fdf->matrix[(int)bres->y[0]][(int)bres->x[0]];
		bres->z[1] = fdf->matrix[(int)bres->y[1]][(int)bres->x[1]];
		bresenham(fdf, *bres);
	}
	bres->y[1] = bres->y[0] + 1;
	bres->x[1] -= 1;
	if (bres->y[0] < fdf->height - 1)
	{
		bres->z[0] = fdf->matrix[(int)bres->y[0]][(int)bres->x[0]];
		bres->z[1] = fdf->matrix[(int)bres->y[1]][(int)bres->x[1]];
		bresenham(fdf, *bres);
	}
}

void	put_points(t_fdf *fdf)
{
	t_bresenham	bres;

	bres.y[0] = -1;
	while (++bres.y[0] < fdf->height)
	{
		bres.x[0] = -1;
		while (++bres.x[0] < fdf->width)
			bres_caller(&bres, fdf);
	}
}
