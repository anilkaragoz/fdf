/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:48:23 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/21 16:13:14 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ptr_min(char *value, t_fspec *fspec, UL i)
{
	if (SZERO)
	{
		value = ft_putc_str('0', value, SMIN - ft_strlen(value) - 2);
		value = ft_strjoin_f2("0x", value);
		ft_to_lower(value);
		return (value);
	}
	else if ((i || SMIN) && !SJUSTIFY)
	{
		value = ft_strjoin_f2("0x", value);
		value = ft_putc_str(' ', value, SMIN - ft_strlen(value));
		return (ft_justify(value, fspec));
	}
	else if (!i && SDOT && !SMIN && !SMAX)
		return (ft_justify(ft_strdup("0x"), fspec));
	else
		value = ft_strjoin_f2("0x", value);
	return (ft_justify(value, fspec));
}

static char		*ft_ptr_max(char *value, t_fspec *fspec, ULL i)
{
	if (SMAX)
		value = ft_putc_str('0', value, SMAX - ft_strlen(value));
	return (ft_ptr_min(value, fspec, i));
}

void			ft_handle_ptr(t_fspec *fspec, va_list ap)
{
	size_t		value;
	char		*c_value;

	value = va_arg(ap, UL);
	c_value = ft_ullitoa(value, 16);
	c_value = ft_ptr_max(c_value, fspec, value);
	ft_putstr(c_value);
	SLEN = ft_strlen(c_value);
	free(c_value);
	free(SSTR);
}
