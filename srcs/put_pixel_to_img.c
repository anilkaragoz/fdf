/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:21:25 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 16:33:19 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_img(t_fdf *fdf, int x, int y)
{
	int i;

	i = (x * 4) + (fdf->size_line * y);
	fdf->img_data[i] = mlx_get_color_value(fdf->mlx, COLOR);
	fdf->img_data[i + 1] = mlx_get_color_value(fdf->mlx, COLOR) >> 8;
	fdf->img_data[i + 2] = mlx_get_color_value(fdf->mlx, COLOR) >> 16;
}

void	put_pixel_to_hud(t_fdf *fdf, int x, int y, int color)
{
	int i;

	i = (x * 4) + ((fdf->hud_info->hud_size_line) * y);
	fdf->hud_data[i] = mlx_get_color_value(fdf->mlx, color);
	fdf->hud_data[i + 1] = mlx_get_color_value(fdf->mlx, color) >> 8;
	fdf->hud_data[i + 2] = mlx_get_color_value(fdf->mlx, color) >> 16;
}
