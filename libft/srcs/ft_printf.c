/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:48:59 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 16:08:55 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_handlers(va_list ap, t_fspec *fspec)
{
	if (SARGT == 'c' || SARGT == '%')
		ft_handle_char(fspec, ap);
	else if (SARGT == 'C')
		ft_handle_wchar(fspec, ap);
	else if (SARGT == 's')
		ft_handle_str(fspec, ap);
	else if (SARGT == 'S')
		ft_handle_wstr(fspec, ap);
	else if (SARGT == 'd' || SARGT == 'i' || SARGT == 'D')
		ft_handle_int(fspec, ap);
	else if (SARGT == 'u' || SARGT == 'U' || SARGT == 'o' || SARGT == 'O'
			|| SARGT == 'x' || SARGT == 'X')
		ft_handle_uint(fspec, ap);
	else if (SARGT == 'p')
		ft_handle_ptr(fspec, ap);
	else
		ft_handle_invalid(fspec);
}

static	void	ft_parse_sp(t_fspec *fspec, va_list ap)
{
	ft_parse_flag(fspec);
	SBASE = 10;
	SPFX = "";
	SLEN = 0;
	SHTAG = ft_strchr(SSTR, '#') ? 1 : 0;
	SPLUS = ft_strchr(SSTR, '+') ? 1 : 0;
	SSPACE = ft_strchr(SSTR, ' ') ? 1 : 0;
	SZERO = (SZERO && SDOT && SHTAG) ? 0 : SZERO;
	SZERO = (ft_strchr("diouxX", SARGT) && SDOT) ? 0 : SZERO;
	if (SARGT == 'o' || SARGT == 'O')
	{
		if (SHTAG)
			SPFX = "0";
		SBASE = 8;
	}
	else if (SARGT == 'x' || SARGT == 'X')
	{
		if (SHTAG)
			SPFX = "0x";
		SBASE = 16;
	}
	SLENPFX = ft_strlen(SPFX);
	ft_handlers(ap, fspec);
}

int				ft_handle_sp(const char *fm, va_list ap, t_fspec *fspec, int *i)
{
	int begin_flag;

	begin_flag = *i;
	while (fm[++*i] && !ft_strchr(FLAG_END, fm[*i]))
	{
		if (!ft_strchr(VALID, fm[*i]))
			break ;
	}
	if (!fm[*i])
		return (0);
	else if (fm[*i])
		SSTR = ft_strsub(fm, begin_flag, (*i + 1) - begin_flag);
	ft_parse_sp(fspec, ap);
	*i += 1;
	return (SLEN);
}

static int		ft_parse_format(const char *format, va_list ap)
{
	t_fspec	*fspec;
	int		len;
	int		i;

	fspec = (t_fspec *)malloc(sizeof(t_fspec));
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			len += ft_handle_sp(format, ap, fspec, &i);
		else
		{
			if (format[i] != '%' && format[i])
			{
				ft_putchar(format[i]);
				len++;
			}
			i++;
		}
	}
	free(fspec);
	return (len);
}

int				ft_printf(char const *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	len = ft_parse_format(format, ap);
	va_end(ap);
	return (len);
}
