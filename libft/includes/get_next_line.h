/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:32:09 by akaragoz          #+#    #+#             */
/*   Updated: 2016/11/03 12:57:31 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 16384
# include "libft.h"
# include <fcntl.h>

typedef struct	s_fdlist
{
	char			*bf;
	int				fd;
	struct s_fdlist *next;

}				t_fdlist;

int				get_next_line(int const fd, char **line);

#endif
