/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 16:40:59 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/18 16:42:34 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define DEBUG ft_putstr("debug\n");
# define WIN_W 800
# define WIN_H 800
# define HUD_W 380
# define HUD_H 120
# define COLOR fdf->color
# define RED   ((fdf->color & 0xFF0000) >> 16)
# define GREEN ((fdf->color & 0x00FF00) >> 8)
# define BLUE  (fdf->color & 0x0000FF)

# define START_X fdf->start_x
# define START_Y fdf->start_y
# define ZOOM fdf->zoom
# define ABS(x) ((x)<0 ? -(x) : (x))
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include <limits.h>
# include "../mlx/mlx.h"

typedef struct	s_point
{
	int	x;
	int y;
	int height;
}				t_point;

typedef struct	s_hud_info
{
	int color_ratio;
	int show_hud;
	int hud_bpp;
	int hud_size_line;
	int hud_endian;
}				t_hud_info;

typedef struct	s_fdf
{
	char		*file_name;
	int			matrix_lines;
	int			matrix_col;
	t_point		***matrix;
	int			**content;
	void		*img;
	void		*hud;
	char		*img_data;
	char		*hud_data;
	int			bpp;
	int			size_line;
	int			endian;
	void		*win;
	void		*mlx;
	int			start_x;
	int			start_y;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			zoom;
	int			color;
	t_hud_info	*hud_info;
}				t_fdf;

char			*get_file_content(int fd, t_fdf *fdf);
int				**str_to_2d(char *str, t_fdf *fdf);
void			line(t_fdf *fdf, int x0, int y0, int x1, int y1);
void			draw_x(t_fdf *fdf);
void			draw_y(t_fdf *fdf);
int				handle_keys(int keycode, t_fdf *fdf);
void			redraw(t_fdf *fdf);
void			init_p_matrix(t_fdf *fdf, int **file_content);
void			assign_values(t_fdf *fdf);
void			put_pixel_to_img(t_fdf *fdf, int x, int y);
void			put_pixel_to_hud(t_fdf *fdf, int x, int y, int color);
void			draw_hud(t_fdf *fdf);
void			draw_text(t_fdf *fdf);
int				handle_mouse(int button, int x, int y, t_fdf *fdf);

#endif
