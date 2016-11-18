/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:25:43 by akaragoz          #+#    #+#             */
/*   Updated: 2016/05/17 15:17:11 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	unsigned int i;
	unsigned int count;

	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && i < ft_strlen(s))
				i++;
		}
		i++;
	}
	return (count);
}

static int	ft_countwordletters(char const *s, char c)
{
	unsigned int count;

	count = 0;
	while (s[count] != c && s[count])
	{
		count++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	words;
	unsigned int	i;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	i = 0;
	while (words)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_countwordletters(s, c))))
			return (NULL);
		s += ft_countwordletters(s, c);
		i++;
		words--;
	}
	tab[i] = NULL;
	return (tab);
}
