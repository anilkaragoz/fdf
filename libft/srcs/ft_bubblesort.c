/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:11:25 by akaragoz          #+#    #+#             */
/*   Updated: 2016/04/04 15:36:55 by akaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		swap(int *t, int x, int y)
{
	int temp;

	temp = t[x];
	t[x] = t[y];
	t[y] = temp;
}

void			ft_bubblesort(int *t, int size)
{
	int i;
	int j;
	int sorted;

	i = size - 1;
	while (i > 0)
	{
		sorted = 1;
		j = 0;
		while (j <= i - 1)
		{
			if (t[j + 1] < t[j])
			{
				swap(t, j + 1, j);
				sorted = 0;
			}
			j++;
		}
		i--;
		if (sorted)
			break ;
	}
}
