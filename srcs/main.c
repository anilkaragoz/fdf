/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:43:54 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 13:26:07 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(void)
{
	t_fdf *ptr;

	ptr = (t_fdf*)malloc(sizeof(t_fdf));
	ptr->matrix_lines = 0;
	ptr->matrix_col = 0;
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, WIN_W, WIN_H, "fdf");
	ptr->img = mlx_new_image(ptr->mlx, WIN_W, WIN_H);
	ptr->hud = mlx_new_image(ptr->mlx, HUD_W, HUD_H);
	ptr->img_data = mlx_get_data_addr(ptr->img, &(ptr->bpp),
		&(ptr->size_line), &(ptr->endian));
	ptr->start_x = 300;
	ptr->start_y = 300;
	ptr->color = 0xFFFFFF;
	ptr->zoom = 10;
	ptr->hud_info = (t_hud_info*)malloc(sizeof(t_hud_info));
	ptr->hud_info->color_ratio = 10;
	ptr->hud_info->show_hud = 0;
	ptr->hud_data = mlx_get_data_addr(ptr->hud, &(ptr->hud_info->hud_bpp),
		&(ptr->hud_info->hud_size_line), &(ptr->hud_info->hud_endian));
	return (ptr);
}

t_point	*new_point(int x, int y, int height)
{
	t_point *new;

	new = (t_point*)malloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	new->height = height;
	return (new);
}

void	assign_values(t_fdf *fdf)
{
	int i;
	int j;
	int x;
	int y;

	i = -1;
	while (++i < fdf->matrix_lines)
	{
		j = -1;
		while (++j < fdf->matrix_col)
		{
			x = (START_X + (j * ZOOM)) - i * ZOOM;
			y = (START_Y + (i * ZOOM)) - (fdf->content[i][j]
				* ZOOM / 2) + j * ZOOM;
			fdf->matrix[i][j]->x = x;
			fdf->matrix[i][j]->y = y;
		}
	}
}

void	init_p_matrix(t_fdf *fdf, int **file_content)
{
	int i;
	int j;

	i = -1;
	fdf->matrix = (t_point***)malloc(sizeof(t_point**) * fdf->matrix_lines);
	while (++i < fdf->matrix_lines)
	{
		fdf->matrix[i] = (t_point**)malloc(sizeof(t_point*) * fdf->matrix_col);
		j = -1;
		while (++j < fdf->matrix_col)
			fdf->matrix[i][j] = new_point(0, 0, file_content[i][j]);
	}
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;
	char	*str;
	int		**matrix;
	int		fd;

	if (argc != 2)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	fdf = init_fdf();
	fdf->file_name = argv[1];
	str = get_file_content(fd, fdf);
	matrix = str_to_2d(str, fdf);
	fdf->content = matrix;
	init_p_matrix(fdf, matrix);
	assign_values(fdf);
	redraw(fdf);
	mlx_hook(fdf->win, 2, 1 << 9, handle_keys, fdf);
	mlx_mouse_hook(fdf->win, handle_mouse, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
