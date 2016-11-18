/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:47:52 by akaragoz          #+#    #+#             */
/*   Updated: 2016/03/23 16:04:54 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_justify(char *value, t_fspec *fspec)
{
	char *spaces;

	if (SMIN > ft_strlen(value) && SJUSTIFY)
	{
		spaces = ft_strnew(SMIN - ft_strlen(value));
		ft_memset(spaces, ' ', SMIN - ft_strlen(value));
		value = ft_strjoin_f1(value, spaces);
		free(spaces);
	}
	if (SARGT == 'x' || SARGT == 'p')
		ft_to_lower(value);
	return (value);
}
