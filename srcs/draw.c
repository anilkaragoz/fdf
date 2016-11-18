/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:39:42 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 16:17:03 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_draw_line(t_fdf *fdf, int *sx, int *sy, int *err)
{
	int dx;
	int dy;

	dx = ABS(fdf->x1 - fdf->x0);
	dy = ABS(fdf->y1 - fdf->y0);
	*sx = fdf->x0 < fdf->x1 ? 1 : -1;
	*sy = fdf->y0 < fdf->y1 ? 1 : -1;
	*err = (dx > dy ? dx : -dy) / 2;
}

void	draw_line(t_fdf *fdf, int dx, int dy)
{
	int sx;
	int sy;
	int err;
	int e2;

	init_draw_line(fdf, &sx, &sy, &err);
	while (1)
	{
		if ((fdf->x0 > 0 && fdf->x0 < WIN_W) &&
				(fdf->y0 > 0 && fdf->y0 < WIN_H * 2))
			put_pixel_to_img(fdf, fdf->x0, fdf->y0 / 2);
		if (fdf->x0 == fdf->x1 && fdf->y0 == fdf->y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			fdf->x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			fdf->y0 += sy;
		}
	}
}

void	draw_x(t_fdf *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->matrix_lines)
	{
		j = -1;
		while (++j < fdf->matrix_col - 1)
		{
			fdf->x0 = fdf->matrix[i][j]->x;
			fdf->y0 = fdf->matrix[i][j]->y;
			fdf->x1 = fdf->matrix[i][j + 1]->x;
			fdf->y1 = fdf->matrix[i][j + 1]->y;
			draw_line(fdf, ABS(fdf->x1 - fdf->x0), ABS(fdf->y1 - fdf->y0));
		}
	}
}

void	draw_y(t_fdf *fdf)
{
	int i;
	int j;

	j = -1;
	while (++j < fdf->matrix_col)
	{
		i = -1;
		while (++i < fdf->matrix_lines - 1)
		{
			fdf->x0 = fdf->matrix[i][j]->x;
			fdf->y0 = fdf->matrix[i][j]->y;
			fdf->x1 = fdf->matrix[i + 1][j]->x;
			fdf->y1 = fdf->matrix[i + 1][j]->y;
			draw_line(fdf, ABS(fdf->x1 - fdf->x0), ABS(fdf->y1 - fdf->y0));
		}
	}
}

void	redraw(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
	fdf->img_data = mlx_get_data_addr(fdf->img, &(fdf->bpp),
			&(fdf->size_line), &(fdf->endian));
	draw_x(fdf);
	draw_y(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	if (fdf->hud_info->show_hud)
	{
		draw_hud(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->hud, 0, 0);
		draw_text(fdf);
	}
}
