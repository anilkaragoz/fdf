/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:50:30 by akaragoz          #+#    #+#             */
/*   Updated: 2015/12/16 17:51:45 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len-- > 0)
			*(char *)(dst + len) = *(char *)(src + len);
	return (dst);
}
