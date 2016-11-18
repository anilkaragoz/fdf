/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:48:01 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/16 16:26:22 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static UI	ft_getnbrsize(LL n, int base)
{
	UI size;

	size = 1;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n > base - 1)
	{
		n = n / base;
		size++;
	}
	return (size);
}

char		*ft_llitoa(LL n, int base)
{
	int		size;
	char	*str;
	int		minus;

	if (n < -9223372036854775807)
		return (ft_strjoin("-", ft_ullitoa(-n, base)));
	minus = 0;
	size = ft_getnbrsize(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		minus = 1;
		n = -n;
	}
	while (--size >= 0)
	{
		str[size] = (n % base < 10) ? (n % base) + '0' : (n % base) - 10 + 'A';
		n = n / base;
	}
	if (minus)
		str[0] = '-';
	return (str);
}
