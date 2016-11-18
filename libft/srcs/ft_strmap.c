/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:23:45 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/09 18:15:21 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*newstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	if (!(newstr = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (i < ft_strlen(s))
	{
		newstr[i] = f(s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
