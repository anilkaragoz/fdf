/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpychr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:04:08 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/21 17:05:37 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpychr(char const *s, int start, char c)
{
	char			*returned;
	unsigned int	i;

	i = 0;
	while (s[start + i] != c && s[start + i])
		i++;
	returned = ft_strsub(s, start, i);
	return (returned);
}
