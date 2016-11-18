/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 13:30:31 by akaragoz          #+#    #+#             */
/*   Updated: 2016/05/20 15:07:00 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	ft_fdlst_pback(t_fdlist **alst, t_fdlist *newelem)
{
	t_fdlist *tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newelem;
}

static	int		ft_i(char *bf)
{
	int i;

	i = 0;
	while (bf[i])
	{
		if (bf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static t_fdlist	*ft_find_link(int fd, t_fdlist **begin_list)
{
	t_fdlist *tmplink;
	t_fdlist *newelem;

	if (!(*begin_list))
	{
		if (!((*begin_list) = (t_fdlist*)malloc(sizeof(t_fdlist))))
			return (NULL);
		(*begin_list)->bf = ft_strdup("");
		(*begin_list)->fd = fd;
		(*begin_list)->next = NULL;
	}
	tmplink = *begin_list;
	while (tmplink)
	{
		if (tmplink->fd == fd)
			return (tmplink);
		tmplink = tmplink->next;
	}
	if (!(newelem = (t_fdlist*)malloc(sizeof(t_fdlist))))
		return (NULL);
	newelem->bf = ft_strdup("");
	newelem->fd = fd;
	newelem->next = NULL;
	ft_fdlst_pback(begin_list, newelem);
	return (newelem);
}

static	void	ft_readstuff(char *buffer, t_fdlist *l, int *ret, int fd)
{
	char *tmp;

	while ((*ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[*ret] = '\0';
		tmp = l->bf;
		l->bf = ft_strjoin(l->bf, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
}

int				get_next_line(int const fd, char **line)
{
	char			*buffer;
	int				ret;
	static t_fdlist	*begin_list = NULL;
	t_fdlist		*l;
	char			*tmp;

	if (!(buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) || fd < 0)
		return (-1);
	l = ft_find_link(fd, &begin_list);
	ft_readstuff(buffer, l, &ret, fd);
	if (ret == -1)
		return (-1);
	*line = ft_strsub(l->bf, 0, ft_i(l->bf));
	if (*(l->bf) == '\0' && ret == 0)
	{
		free(buffer);
		return (0);
	}
	tmp = l->bf;
	l->bf = ft_strsub(l->bf, ft_i(l->bf) + 1, ft_strlen(l->bf) - ft_i(l->bf));
	free(tmp);
	free(buffer);
	return (1);
}
