/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:37:18 by akaragoz          #+#    #+#             */
/*   Updated: 2015/11/26 15:43:53 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
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
			while (s1[i] == s2[j] && s1[i] != '\0')
			{
				i++;
				j++;
			}
			if (s2[j] == '\0')
				return ((char *)&s1[i - j]);
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
