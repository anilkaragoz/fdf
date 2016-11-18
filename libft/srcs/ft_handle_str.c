/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:50:38 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 12:21:46 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_str_min(char *str, t_fspec *fspec)
{
	int len;

	len = (SARGT == 'c') ? 1 : ft_strlen(str);
	if (SMIN < ft_strlen(str) || SJUSTIFY)
		return (ft_justify(str, fspec));
	else if (SZERO)
		str = ft_putc_str('0', str, SMIN - len);
	else
		str = ft_putc_str(' ', str, SMIN - len);
	return (ft_justify(str, fspec));
}

static char	*ft_str_max(char *str, t_fspec *fspec)
{
	char *tmp;

	if (str && SDOT)
	{
		tmp = ft_strsub(str, 0, SMAX);
		free(str);
		return (ft_str_min(tmp, fspec));
	}
	return (ft_str_min(str, fspec));
}

void		ft_handle_str(t_fspec *fspec, va_list ap)
{
	char	*str;

	if (SINTMODIF == 3)
		return (ft_handle_wstr(fspec, ap));
	str = va_arg(ap, char *);
	if (str == NULL && !SDOT && !SMIN)
	{
		ft_putstr("(null)");
		SLEN += 6;
		free(SSTR);
		return ;
	}
	else if (str == NULL && !SMIN && !SDOT)
		str = ft_str_max(ft_strdup(""), fspec);
	else if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = ft_str_max(str, fspec);
	ft_putstr(str);
	SLEN += ft_strlen(str);
	free(str);
	free(SSTR);
}
