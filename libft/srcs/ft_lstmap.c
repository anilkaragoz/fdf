/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:24:58 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/09 17:57:54 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_link;
	t_list *first_link;

	if (!lst || !f)
		return (NULL);
	first_link = f(lst);
	new_link = first_link;
	lst = lst->next;
	while (lst)
	{
		new_link->next = f(lst);
		new_link = new_link->next;
		lst = lst->next;
	}
	return (first_link);
}
