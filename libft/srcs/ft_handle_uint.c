/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:50:53 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 15:47:15 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Modifier value
**  0 -> UI
**  1 -> h;
**  2 -> hh;
**  3 -> l;
**  4 -> ll;
**  5 -> z;
**  6 -> j;
*/

static size_t	ft_recup_unsigned_value(t_fspec *fspec, va_list ap)
{
	if (SINTMODIF == 1 && !ft_isupper(SARGT))
		return ((unsigned short)va_arg(ap, UI));
	if (SINTMODIF == 2 && (SARGT == 'X' || SARGT == 'o' ||
		SARGT == 'u' || SARGT == 'x'))
		return ((unsigned char)va_arg(ap, UI));
	else if (SINTMODIF == 2 && ft_isupper(SARGT))
		return ((unsigned short)va_arg(ap, UI));
	else if (SINTMODIF == 3 || SINTMODIF == 4 || SINTMODIF == 6
			|| SARGT == 'O' || SARGT == 'U' || SARGT == 'p')
		return (va_arg(ap, UL));
	else if (SINTMODIF == 5)
		return (va_arg(ap, size_t));
	else
		return (va_arg(ap, UI));
}

static char		*ft_uint_pfx(char *test, t_fspec *fspec, ULL v)
{
	int		i;

	i = 0;
	if (!v && !SMAX && SDOT && !SMIN && SARGT != 'o' && SARGT != 'O')
	{
		free(test);
		return (ft_justify(ft_strdup(""), fspec));
	}
	else if (!v && SHTAG)
		return (ft_justify(test, fspec));
	if (!v && !SMAX && SDOT && !SHTAG &&
		(SARGT != 'o' || SARGT != 'O') && !SMIN)
	{
		free(test);
		return (ft_justify(ft_strdup(""), fspec));
	}
	if (SHTAG)
		test = ft_add_pfx(test, fspec);
	return (ft_justify(test, fspec));
}

static char		*ft_uint_min(char *value, t_fspec *fspec, ULL i)
{
	size_t	len;

	len = ft_strlen(value);
	if (SMIN < len || SJUSTIFY)
		return (ft_uint_pfx(value, fspec, i));
	if (!SMAX && SDOT && !i)
	{
		free(value);
		value = ft_putc_str(' ', ft_strdup(" "), SMIN - len);
	}
	else if (SZERO)
		value = ft_putc_str('0', value, SMIN - len - SLENPFX);
	else
		value = ft_putc_str(' ', value, SMIN - len);
	return (ft_uint_pfx(value, fspec, i));
}

static char		*ft_uint_max(char *value, t_fspec *fspec, ULL i)
{
	size_t	len;

	len = ft_strlen(value);
	if (!i && !SMAX && SDOT)
		return (ft_uint_min(value, fspec, i));
	if (SMAX > len)
	{
		if (SHTAG && SARGT == 'o')
			value = ft_putc_str('0', value, SMAX - len - SLENPFX);
		else
			value = ft_putc_str('0', value, SMAX - len);
	}
	return (ft_uint_min(value, fspec, i));
}

void			ft_handle_uint(t_fspec *fspec, va_list ap)
{
	size_t	value;
	char	*c_value;

	value = ft_recup_unsigned_value(fspec, ap);
	ft_get_pfx_and_base(fspec);
	c_value = ft_ullitoa(value, SBASE);
	c_value = ft_uint_max(c_value, fspec, value);
	ft_putstr(c_value);
	SLEN = ft_strlen(c_value);
	free(c_value);
	free(SSTR);
}
