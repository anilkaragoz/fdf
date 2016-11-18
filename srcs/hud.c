/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:01:32 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 16:31:03 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_square(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < HUD_H)
	{
		if (i == 0 || i == HUD_H - 1)
		{
			j = 0;
			while (j < HUD_W)
			{
				put_pixel_to_hud(fdf, j, i, 0xFFFFFF);
				j++;
			}
		}
		else
		{
			put_pixel_to_hud(fdf, 0, i, 0xFFFFFF);
			put_pixel_to_hud(fdf, HUD_W - 1, i, 0xFFFFFF);
		}
		i++;
	}
}

void	selected_color(t_fdf *fdf)
{
	int x;
	int y;
	int i;
	int j;

	x = 230;
	y = 35;
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 130)
		{
			put_pixel_to_hud(fdf, x + j, y + i, COLOR);
			j++;
		}
		i++;
	}
}

char	*ft_padding(char *str)
{
	int length;

	length = ft_strlen(str);
	if (length == 1)
		return (ft_strjoin_f2("  ", str));
	if (length == 2)
		return (ft_strjoin_f2(" ", str));
	return (str);
}

void	draw_text(t_fdf *fdf)
{
	char	*string_red;
	char	*string_green;
	char	*string_blue;

	string_red = ft_strjoin_f1(ft_strjoin_f2("Red   - ",
				ft_padding(ft_itoa(RED))), " +");
	string_green = ft_strjoin_f1(ft_strjoin_f2("Green - ",
				ft_padding(ft_itoa(GREEN))), " +");
	string_blue = ft_strjoin_f1(ft_strjoin_f2("Blue  - ",
				ft_padding(ft_itoa(BLUE))), " +");
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFFFFFF, string_red);
	mlx_string_put(fdf->mlx, fdf->win, 10, 35, 0xFFFFFF, string_green);
	mlx_string_put(fdf->mlx, fdf->win, 10, 60, 0xFFFFFF, string_blue);
	mlx_string_put(fdf->mlx, fdf->win, 230, 10, 0xFFFFFF, "Current color");
	mlx_string_put(fdf->mlx, fdf->win, 158, 10, 0xFFFFFF, "Ratio");
	mlx_string_put(fdf->mlx, fdf->win, 170, 31, 0xFFFFFF, "1");
	mlx_string_put(fdf->mlx, fdf->win, 167, 47, 0xFFFFFF, "10");
	mlx_string_put(fdf->mlx, fdf->win, 162, 62, 0xFFFFFF, "100");
	mlx_string_put(fdf->mlx, fdf->win, 10, 85, 0xFFFFF, fdf->file_name);
	free(string_red);
	free(string_green);
	free(string_blue);
}

void	draw_hud(t_fdf *fdf)
{
	draw_square(fdf);
	selected_color(fdf);
}
