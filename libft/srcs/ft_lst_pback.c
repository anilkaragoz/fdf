/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:21:18 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/09 18:30:16 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pback(t_list **alst, void const *c, size_t c_size)
{
	t_list *new_lst;

	new_lst = *alst;
	if (*alst)
	{
		while (new_lst->next)
			new_lst = new_lst->next;
		new_lst->next = ft_lstnew(c, c_size);
	}
	else
		*alst = ft_lstnew(c, c_size);
}
