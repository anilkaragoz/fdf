/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:31:59 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/09 17:50:09 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (ft_strcmp(s1, s2) == 0)
		return (1);
	return (0);
}
