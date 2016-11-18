/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:50:31 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 12:20:20 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_int_min(char *value, t_fspec *fspec, LL i)
{
	size_t	len;

	len = ft_strlen(value);
	if (SMIN < len || SJUSTIFY)
		return (ft_justify(value, fspec));
	if (SZERO && (i < 0 || SPLUS))
	{
		free(value);
		value = (i < 0) ? ft_llitoa(-i, SBASE) : ft_llitoa(i, SBASE);
		len = ft_strlen(value);
		value = ft_putc_str('0', value, SMIN - len - 1);
		value = (i < 0) ? ft_strjoin_f2("-", value) : ft_strjoin_f2("+", value);
		return (value);
	}
	else if ((SMIN < SMAX || !SMAX) && !SSPACE && SZERO)
		value = ft_putc_str('0', value, SMIN - len);
	else if (SSPACE && SZERO && !SDOT)
	{
		value = ft_putc_str('0', value, SMIN - len - 1);
		value = ft_strjoin_f2(" ", value);
	}
	else
		value = ft_putc_str(' ', value, SMIN - len);
	return (ft_justify(value, fspec));
}

static char		*ft_flag_int(char *value, t_fspec *fspec, LL i)
{
	char *tmp;

	tmp = value;
	if (SPLUS && i >= 0)
		tmp = ft_strjoin_f2("+", value);
	else if (SSPACE && !SPLUS && ((!SZERO && i >= 0) || (SZERO && i > 0)))
		tmp = ft_strjoin_f2(" ", value);
	return (ft_int_min(tmp, fspec, i));
}

static char		*ft_int_max(char *value, t_fspec *fspec, LL i)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(value);
	if (!i && !SMAX && SDOT)
	{
		free(value);
		return (ft_flag_int(ft_strdup(""), fspec, i));
	}
	if (i >= 0 && SMAX > len)
	{
		tmp = ft_putc_str('0', value, SMAX - len);
		return (ft_flag_int(tmp, fspec, i));
	}
	if (i < 0 && SMAX)
	{
		free(value);
		value = ft_llitoa(-i, SBASE);
		len = ft_strlen(value);
		tmp = ft_putc_str('0', value, SMAX - len);
		value = ft_strjoin_f2("-", tmp);
	}
	return (ft_flag_int(value, fspec, i));
}

static size_t	ft_recup_signed_value(t_fspec *fspec, va_list ap)
{
	if (SINTMODIF == 1 && SARGT != 'D')
		return ((short)va_arg(ap, int));
	if (SINTMODIF == 2 && SARGT != 'D')
		return ((signed char)va_arg(ap, int));
	if (SINTMODIF == 3)
		return (va_arg(ap, long));
	if (SINTMODIF == 4)
		return (va_arg(ap, LL));
	else if (SINTMODIF == 5)
		return (va_arg(ap, size_t));
	else if (SINTMODIF == 6)
		return (va_arg(ap, long));
	else if (ft_isupper(SARGT) && SINTMODIF != 1)
		return (va_arg(ap, long));
	else
		return (va_arg(ap, int));
}

void			ft_handle_int(t_fspec *fspec, va_list ap)
{
	char	*c_value;
	size_t	value;

	value = ft_recup_signed_value(fspec, ap);
	c_value = ft_llitoa(value, SBASE);
	c_value = ft_int_max(c_value, fspec, value);
	ft_putstr(c_value);
	SLEN = ft_strlen(c_value);
	free(c_value);
	free(SSTR);
}
