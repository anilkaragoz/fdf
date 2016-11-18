/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:54:53 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/16 17:53:08 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_getnbrsize(int n)
{
	unsigned int	size;

	size = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	int		size;
	char	*str;
	int		neg;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_getnbrsize(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (--size >= 0)
	{
		str[size] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
