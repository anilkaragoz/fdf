/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:47:22 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 16:21:52 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_wchar_min(t_fspec *fspec, int len)
{
	char *tmp;

	if (SMIN < (UI)len)
		return (ft_strdup(""));
	if (SZERO)
		tmp = ft_putc_str('0', ft_strdup(""), SMIN - len);
	else
		tmp = ft_putc_str(' ', ft_strdup(""), SMIN - len);
	SLEN += SMIN - len;
	return (tmp);
}

char		*ft_fill_mask(char *s1, char *s2)
{
	int i;
	int j;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (j >= 0)
	{
		if (s1[i] == 'x')
		{
			s1[i] = s2[j];
			j--;
		}
		i--;
	}
	while (i >= 0)
	{
		if (s1[i] == 'x')
			s1[i] = '0';
		i--;
	}
	free(s2);
	return (s1);
}

int			ft_bin_to_dec(char *str)
{
	int power;
	int res;
	int i;

	power = 1;
	res = 0;
	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] == '1')
			res += power;
		power = power << 1;
	}
	return (res);
}

void		ft_wchar_print(char *mask, char *bin, t_fspec *fspec)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	mask = ft_fill_mask(mask, bin);
	tmp = ft_wchar_min(fspec, ft_strlen(mask) / 8);
	if (!SJUSTIFY && SMIN)
		ft_putstr(tmp);
	while (mask[i])
	{
		tmp2 = ft_strsub(mask, i, 8);
		ft_putchar(ft_bin_to_dec(tmp2));
		free(tmp2);
		i += 8;
	}
	if (SJUSTIFY && SMIN)
		ft_putstr(tmp);
	SLEN += i / 8;
	free(tmp);
	free(mask);
}

void		ft_handle_wchar(t_fspec *fspec, va_list ap)
{
	int		bits;
	LL		value;
	char	*bin;

	value = va_arg(ap, wchar_t);
	bin = ft_ullitoa(value, 2);
	bits = ft_strlen(bin);
	if (bits < 8)
		ft_wchar_print(ft_strdup(MASK8), bin, fspec);
	else if (bits < 12)
		ft_wchar_print(ft_strdup(MASK16), bin, fspec);
	else if (bits < 17)
		ft_wchar_print(ft_strdup(MASK24), bin, fspec);
	else
		ft_wchar_print(ft_strdup(MASK32), bin, fspec);
	free(SSTR);
}
