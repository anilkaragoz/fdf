/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:44:05 by akaragoz          #+#    #+#             */
/*   Updated: 2015/11/24 15:51:51 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z' ? 1 : 0);
}