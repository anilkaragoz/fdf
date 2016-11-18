/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_wstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:47:30 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/21 19:45:29 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_wstr_min(wchar_t *value, t_fspec *fspec)
{
	char *tmp;

	if (SZERO && !SJUSTIFY)
		tmp = ft_putc_str('0', ft_strdup(""), SMIN - ft_get_wstr_len(value));
	else
		tmp = ft_putc_str(' ', ft_strdup(""), SMIN - ft_get_wstr_len(value));
	return (tmp);
}

static wchar_t	*ft_wstr_max(wchar_t *value, t_fspec *fspec, size_t len)
{
	wchar_t	*tmp;
	size_t	wchar_len;
	int		i;

	i = 0;
	if (SDOT && !SMAX)
		return ((wchar_t*)"\0");
	if (SMAX < len && SMAX)
	{
		tmp = (wchar_t *)malloc(sizeof(wchar_t) * len + 1);
		wchar_len = ft_get_wchar_len(value[i]);
		while (wchar_len <= SMAX)
		{
			tmp[i] = value[i];
			wchar_len += ft_get_wchar_len(value[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (value);
}

void			ft_handle_wstr(t_fspec *fspec, va_list ap)
{
	wchar_t	*output;
	char	*min;

	output = va_arg(ap, wchar_t *);
	if (output == NULL)
	{
		ft_putstr("(null)");
		SLEN += 6;
		return ;
	}
	output = ft_wstr_max(output, fspec, ft_get_wstr_len(output));
	min = ft_wstr_min(output, fspec);
	if (SJUSTIFY)
	{
		ft_wstr_print(output);
		ft_putstr(min);
	}
	else
	{
		ft_putstr(min);
		ft_wstr_print(output);
	}
	SLEN = ft_get_wstr_len(output) + ft_strlen(min);
	free(SSTR);
	free(min);
}
