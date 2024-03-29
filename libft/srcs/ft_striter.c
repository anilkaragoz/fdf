/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:16:48 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/09 18:15:09 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int i;

	if (!s || !f)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		f(&s[i]);
		i++;
	}
}
