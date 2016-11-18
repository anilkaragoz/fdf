/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:00:11 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/09 18:14:22 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		l->content = NULL;
		l->content_size = 0;
	}
	else
	{
		l->content_size = content_size;
		if (!(l->content = (void *)malloc(content_size)))
			return (NULL);
		l->content = ft_memcpy(l->content, content, content_size);
	}
	l->next = NULL;
	return (l);
}
