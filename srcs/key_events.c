/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 17:40:03 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 16:32:53 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(t_fdf *fdf, int keycode)
{
	int sign;
	int i;
	int j;

	sign = (keycode == 123) ? -10 : 10;
	i = -1;
	while (++i < fdf->matrix_lines)
	{
		j = -1;
		while (++j < fdf->matrix_col)
			fdf->matrix[i][j]->x += sign;
	}
	START_X = fdf->matrix[0][0]->x;
	redraw(fdf);
}

void	move_y(t_fdf *fdf, int keycode)
{
	int sign;
	int i;
	int j;

	sign = (keycode == 126) ? -20 : 20;
	i = -1;
	while (++i < fdf->matrix_lines)
	{
		j = -1;
		while (++j < fdf->matrix_col)
			fdf->matrix[i][j]->y += sign;
	}
	START_Y = fdf->matrix[0][0]->y;
	redraw(fdf);
}

void	zoom(t_fdf *fdf, int keycode)
{
	ZOOM += (keycode == 27) ? 1 : -1;
	if (ZOOM < 0)
		ZOOM = 0;
	if (ZOOM > 99)
		ZOOM = 99;
	assign_values(fdf);
	redraw(fdf);
}

void	exit_properly(t_fdf *fdf)
{
	int i;

	i = 0;
	free(fdf->hud_info);
	while (i < fdf->matrix_lines)
	{
		free(fdf->content[i]);
		i++;
	}
	free(fdf->content);
	mlx_destroy_image(fdf->mlx, fdf->hud);
	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf);
	exit(1);
}

int		handle_keys(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit_properly(fdf);
	if (keycode == 123 || keycode == 124)
		move_x(fdf, keycode);
	if (keycode == 125 || keycode == 126)
		move_y(fdf, keycode);
	if (keycode == 27 || keycode == 24)
		zoom(fdf, keycode);
	if (keycode == 4)
	{
		fdf->hud_info->show_hud = !(fdf->hud_info->show_hud);
		redraw(fdf);
	}
	if (keycode == 50)
	{
		ZOOM = 10;
		START_Y = 300;
		START_X = 300;
		assign_values(fdf);
		redraw(fdf);
	}
	return (0);
}
