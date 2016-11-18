/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:21:30 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 16:16:55 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		rgb_to_hex(unsigned char r, unsigned char g, unsigned char b)
{
	int res;

	res = b;
	res = (((res >> 8) | g) << 8) | res;
	res = (((res >> 16) | r) << 16) | res;
	return (res);
}

int		handle_mouse(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	if (fdf->hud_info->show_hud)
	{
		if (x > 66 && x < 85 && y > 16 && y < 30)
			COLOR = rgb_to_hex(RED - fdf->hud_info->color_ratio, GREEN, BLUE);
		else if (x > 130 && x < 144 && y > 16 && y < 30)
			COLOR = rgb_to_hex(RED + fdf->hud_info->color_ratio, GREEN, BLUE);
		else if (x > 66 && x < 85 && y > 40 && y < 57)
			COLOR = rgb_to_hex(RED, GREEN - fdf->hud_info->color_ratio, BLUE);
		else if (x > 130 && x < 144 && y > 40 && y < 57)
			COLOR = rgb_to_hex(RED, GREEN + fdf->hud_info->color_ratio, BLUE);
		else if (x > 66 && x < 85 && y > 66 && y < 79)
			COLOR = rgb_to_hex(RED, GREEN, BLUE - fdf->hud_info->color_ratio);
		else if (x > 130 && x < 144 && y > 66 && y < 79)
			COLOR = rgb_to_hex(RED, GREEN, BLUE + fdf->hud_info->color_ratio);
		else if (x > 167 && x < 189 && y > 35 && y < 50)
			fdf->hud_info->color_ratio = 1;
		else if (x > 164 && x < 192 && y > 53 && y < 65)
			fdf->hud_info->color_ratio = 10;
		else if (x > 161 && x < 193 && y > 68 && y < 81)
			fdf->hud_info->color_ratio = 100;
		redraw(fdf);
	}
	return (0);
}
