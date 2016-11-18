/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:46:31 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 15:02:38 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Modifier int value
**  default -> 0;
**  h -> 1;
**  hh -> 2;
**  l -> 3;
**  ll -> 4;
**  z -> 5;
**  j -> 6;
*/

static int		ft_get_modif_int(char *s)
{
	int res;

	res = 0;
	if (ft_strlen(s) == 2)
	{
		if (s[0] == 'h')
			res = 2;
		else
			res = 4;
	}
	else if (ft_strlen(s) == 1)
	{
		if (s[0] == 'h')
			res = 1;
		if (s[0] == 'l')
			res = 3;
		if (s[0] == 'z')
			res = 5;
		if (s[0] == 'j')
			res = 6;
	}
	free(s);
	return (res);
}

static int		ft_parse_modifier(int index, t_fspec *fspec)
{
	int len;
	int i;

	i = index;
	while (ft_strchr("hjzl", SSTR[i]))
		i++;
	SMODIF = ft_strsub(SSTR, index, i - index);
	SINTMODIF = ft_get_modif_int(SMODIF);
	len = ft_strlen(SSTR) - 1;
	SARGT = SSTR[len];
	return (len + 1);
}

static int		ft_parse_max(int index, t_fspec *fspec)
{
	int		i;
	char	*tmp;

	SDOT = 0;
	SMAX = 0;
	if (SSTR[index] != '.')
		return (ft_parse_modifier(index, fspec));
	SDOT = 1;
	i = index + 1;
	while (ft_isdigit(SSTR[i]))
		i++;
	if (i != index + 1)
	{
		tmp = ft_strsub(SSTR, index + 1, i - index);
		SMAX = ft_atoi(tmp);
		free(tmp);
	}
	return (ft_parse_modifier(i, fspec));
}

static int		ft_parse_min(int index, t_fspec *fspec)
{
	int		i;
	char	*tmp;

	i = index;
	SMIN = 0;
	while (ft_isdigit(SSTR[i]))
		i++;
	if (i != index)
	{
		tmp = ft_strsub(SSTR, index, i - index);
		SMIN = ft_atoi(tmp);
		free(tmp);
	}
	return (ft_parse_max(i, fspec));
}

void			ft_parse_flag(t_fspec *fspec)
{
	char	*flag;
	int		i;

	i = 1;
	flag = "-0+ #%";
	while (ft_strchr(flag, SSTR[i]) != NULL)
		i++;
	SFLAG = (i > 1) ? ft_strsub(SSTR, 1, i - 1) : ft_strdup("");
	SZERO = (ft_strchr(SFLAG, '0') && !ft_strchr(SFLAG, '-')) ? 1 : 0;
	SJUSTIFY = ft_strchr(SFLAG, '-') ? 1 : 0;
	free(SFLAG);
	ft_parse_min(i, fspec);
}
