/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:49:49 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/14 16:49:51 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static UI	ft_get_len_int(ULL n, ULL b)
{
	UI	size;

	size = 1;
	while (n > b - 1)
	{
		n = n / b;
		size++;
	}
	return (size);
}

char		*ft_ullitoa(ULL i, ULL base)
{
	char	*str;
	ILL		len;

	len = ft_get_len_int(i, base);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (i % base < 10) ? (i % base) + '0' : (i % base) - 10 + 'A';
		i = i / base;
	}
	return (str);
}
