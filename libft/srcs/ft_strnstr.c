/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:47:03 by akaragoz          #+#    #+#             */
/*   Updated: 2015/11/26 15:59:51 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (i < ft_strlen(s1))
	{
		if (s1[i] == s2[j])
		{
			while (s1[i] == s2[j] && i < n)
			{
				i++;
				j++;
				if (s2[j] == '\0')
					return ((char *)&s1[i - j]);
			}
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
