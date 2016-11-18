/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 17:13:49 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 13:26:41 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			count_numbers(char *str)
{
	char	**tab;
	int		i;
	int		count;

	tab = ft_strsplit(str, ' ');
	i = -1;
	count = 0;
	while (tab[++i])
	{
		count++;
		free(tab[i]);
	}
	free(tab);
	return (count);
}

void		parsing_error(t_fdf *fdf, char *file_content)
{
	int i;

	i = -1;
	free(file_content);
	free(fdf->hud_info);
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf);
	write(2, "Parsing error.\n", 15);
	exit(0);
}

char		*get_file_content(int fd, t_fdf *fdf)
{
	char	*line;
	char	*file_content;
	int		count;

	file_content = ft_strdup("");
	while (get_next_line(fd, &line) == 1)
	{
		count = count_numbers(line);
		if (fdf->matrix_col != 0 && fdf->matrix_col != count)
			parsing_error(fdf, file_content);
		fdf->matrix_col = count_numbers(line);
		fdf->matrix_lines++;
		file_content = ft_strjoin_f3(file_content, line);
		file_content = ft_strjoin_f3(file_content, ft_strdup(" "));
	}
	free(line);
	return (file_content);
}

int			**str_to_2d(char *str, t_fdf *fdf)
{
	char	**content;
	int		**tab;
	int		i;
	int		j;
	int		k;

	content = ft_strsplit(str, ' ');
	if (!(tab = (int**)malloc(sizeof(int*) * (fdf->matrix_lines))))
		return (0);
	i = -1;
	k = -1;
	while (++i < fdf->matrix_lines)
	{
		j = -1;
		tab[i] = (int*)malloc(sizeof(int) * fdf->matrix_col);
		while (++j < fdf->matrix_col)
		{
			tab[i][j] = ft_atoi(content[++k]);
			free(content[k]);
		}
	}
	free(content);
	free(str);
	return (tab);
}
