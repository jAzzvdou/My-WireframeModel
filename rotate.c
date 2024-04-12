/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:03:15 by jazevedo          #+#    #+#             */
/*   Updated: 2024/04/11 19:06:41 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotate_alpha(t_bresenham *bres, t_fdf *fdf)
{
	bres->y[2] = bres->y[0];
	bres->z[2] = bres->z[0] * fdf->z;
	bres->y[0] = bres->y[2] * cos(fdf->alpha) - bres->z[2] * sin(fdf->alpha);
	bres->z[0] = bres->y[2] * sin(fdf->alpha) + bres->z[2] * cos(fdf->alpha);
	bres->y[2] = bres->y[1];
	bres->z[2] = bres->z[1] * fdf->z;
	bres->y[1] = bres->y[2] * cos(fdf->alpha) - bres->z[2] * sin(fdf->alpha);
	bres->z[1] = bres->y[2] * sin(fdf->alpha) + bres->z[2] * cos(fdf->alpha);
}

static void	rotate_beta(t_bresenham *bres, t_fdf *fdf)
{
	bres->x[2] = bres->x[0];
	bres->z[2] = bres->z[0] * fdf->z;
	bres->x[0] = bres->x[2] * cos(fdf->beta) + bres->z[2] * sin(fdf->beta);
	bres->z[0] = -bres->x[2] * sin(fdf->beta) + bres->z[2] * cos(fdf->beta);
	bres->x[2] = bres->x[1];
	bres->z[2] = bres->z[1] * fdf->z;
	bres->x[1] = bres->x[2] * cos(fdf->beta) + bres->z[2] * sin(fdf->beta);
	bres->z[1] = -bres->x[2] * sin(fdf->beta) + bres->z[2] * cos(fdf->beta);
}

static void	rotate_gamma(t_bresenham *bres, t_fdf *fdf)
{
	bres->x[2] = bres->x[0];
	bres->y[2] = bres->y[0];
	bres->x[0] = bres->x[2] * cos(fdf->gamma) - bres->y[2] * sin(fdf->gamma);
	bres->y[0] = bres->x[2] * sin(fdf->gamma) + bres->y[2] * cos(fdf->gamma);
	bres->x[2] = bres->x[1];
	bres->y[2] = bres->y[1];
	bres->x[1] = bres->x[2] * cos(fdf->gamma) - bres->y[2] * sin(fdf->gamma);
	bres->y[1] = bres->x[2] * sin(fdf->gamma) + bres->y[2] * cos(fdf->gamma);
}

void	rotate(t_bresenham *bres, t_fdf *fdf)
{
	rotate_alpha(bres, fdf);
	rotate_beta(bres, fdf);
	rotate_gamma(bres, fdf);
}
