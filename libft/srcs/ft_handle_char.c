/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:46:24 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 17:11:58 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_char(t_fspec *fspec, va_list ap)
{
	char	c;
	char	*c1;

	if (SARGT == '%')
		c = '%';
	else if (SINTMODIF == 3)
		return (ft_handle_wchar(fspec, ap));
	else
		c = va_arg(ap, int);
	c1 = ft_strnew(1);
	ft_memset(c1, c, 1);
	c1 = ft_str_min(c1, fspec);
	ft_putstr(c1);
	if (!c)
	{
		ft_putchar('\0');
		SLEN += (!SMIN) ? 1 : SMIN;
	}
	else
		SLEN = ft_strlen(c1);
	free(c1);
	free(SSTR);
}

void		ft_handle_invalid(t_fspec *fspec)
{
	char *output;

	output = ft_strnew(1);
	ft_memset(output, SARGT, 1);
	output = ft_str_min(output, fspec);
	ft_putstr(output);
	SLEN = ft_strlen(output);
	free(output);
	free(SSTR);
}

char		*ft_putc_str(char c, char *dst, LL len)
{
	char *tmp;

	if (len < 0)
		return (dst);
	tmp = ft_strnew(len + 1);
	ft_memset(tmp, c, len);
	dst = ft_strjoin_f2(tmp, dst);
	free(tmp);
	return (dst);
}
