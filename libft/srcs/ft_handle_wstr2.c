/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wstr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:51:02 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/21 19:51:21 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wstr_print(wchar_t *value)
{
	int		i;
	int		j;
	char	*tmp;
	char	*mask;

	i = 0;
	while (value[i])
	{
		mask = ft_mask_wstr(value[i]);
		j = 0;
		while (mask[j])
		{
			tmp = ft_strsub(mask, j, 8);
			ft_putchar(ft_bin_to_dec(tmp));
			free(tmp);
			j += 8;
		}
		free(mask);
		i++;
	}
}

char		*ft_mask_wstr(LL value)
{
	int		bits;
	char	*bin;

	bin = ft_ullitoa(value, 2);
	bits = ft_strlen(bin);
	if (bits < 8)
		return (ft_fill_mask(ft_strdup(MASK8), bin));
	else if (bits < 12)
		return (ft_fill_mask(ft_strdup(MASK16), bin));
	else if (bits < 17)
		return (ft_fill_mask(ft_strdup(MASK24), bin));
	else
		return (ft_fill_mask(ft_strdup(MASK32), bin));
}

int			ft_get_wchar_len(wchar_t c)
{
	char	*bin;
	int		bits;

	bin = ft_ullitoa(c, 2);
	bits = ft_strlen(bin);
	free(bin);
	if (bits < 8)
		return (1);
	else if (bits < 12)
		return (2);
	else if (bits < 17)
		return (3);
	else
		return (4);
}

size_t		ft_get_wstr_len(wchar_t *value)
{
	int		i;
	size_t	len;

	len = 0;
	i = -1;
	while (value[++i])
		len += ft_get_wchar_len(value[i]);
	return (len);
}
