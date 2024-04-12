/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:32:38 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/11 19:03:37 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_zoom(t_bresenham *bres, int zoom)
{
	bres->x[0] *= zoom;
	bres->x[1] *= zoom;
	bres->y[0] *= zoom;
	bres->y[1] *= zoom;
}

void	add_position(t_bresenham *bres, t_fdf *fdf)
{
	bres->x[0] += fdf->xaxis + fdf->start;
	bres->x[1] += fdf->xaxis + fdf->start;
	bres->y[0] += fdf->yaxis + fdf->start;
	bres->y[1] += fdf->yaxis + fdf->start;
}

void	add_steps(t_bresenham *bres)
{
	int	steps;

	bres->dx = bres->x[1] - bres->x[0];
	bres->dy = bres->y[1] - bres->y[0];
	steps = (nmax(fabs(bres->dx), fabs(bres->dy)));
	bres->dx /= steps;
	bres->dy /= steps;
}

void	add_3d(t_bresenham *bres, t_fdf *fdf)
{
	float	temp_x;
	float	temp_y;

	temp_x = (bres->x[0] - bres->y[0]) * cos(fdf->angle);
	temp_y = (bres->x[0] + bres->y[0]) * sin(fdf->angle) \
	- (bres->z[0] * fdf->z);
	bres->x[0] = temp_x;
	bres->y[0] = temp_y;
	temp_x = (bres->x[1] - bres->y[1]) * cos(fdf->angle);
	temp_y = (bres->x[1] + bres->y[1]) * sin(fdf->angle) \
	- (bres->z[1] * fdf->z);
	bres->x[1] = temp_x;
	bres->y[1] = temp_y;
}
