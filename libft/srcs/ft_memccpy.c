/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:34:01 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/15 17:51:18 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
		{
			s1[i] = s2[i];
			return (&(s1[i + 1]));
		}
		s1[i] = s2[i];
		i++;
	}
	return (NULL);
}
