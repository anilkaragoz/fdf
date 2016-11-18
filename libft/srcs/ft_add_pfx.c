/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pfx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:46:54 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/21 16:46:15 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_pfx_and_base(t_fspec *fspec)
{
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
}

char		*ft_add_pfx(char *str, t_fspec *fspec)
{
	int i;

	i = 0;
	if ((SZERO && ft_strlen(str) > SMAX) || ft_strlen(str) > SMIN)
	{
		if ((SARGT == 'o' || SARGT == 'O'))
			str = ft_strjoin_f2("0", str);
		if ((SARGT == 'x' || SARGT == 'X'))
			str = ft_strjoin_f2("0X", str);
	}
	else if (!SJUSTIFY)
	{
		while (str[i] == ' ')
			i++;
		if ((SARGT == 'o' || SARGT == 'O'))
			str[i - 1] = '0';
		if ((SARGT == 'x' || SARGT == 'X'))
		{
			str[i - 1] = 'x';
			str[i - 2] = '0';
		}
	}
	else
		str = ft_strjoin_f2(SPFX, str);
	return (str);
}
