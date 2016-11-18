/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaragoz <akaragoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 16:17:57 by akaragoz          #+#    #+#             */
/*   Updated: 2016/04/04 14:11:55 by akaragoz         ###   ########.fr       */
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

static int		partition(int *t, int start, int end)
{
	int p;
	int s;
	int e;

	p = t[start];
	s = start + 1;
	e = end;
	while (s < e)
	{
		while (s < e && t[e] >= p)
			e--;
		while (s < e && t[s] <= p)
			s++;
		swap(t, s, e);
	}
	if (t[s] > p)
		s--;
	t[start] = t[e];
	t[s] = p;
	return (s);
}

void			ft_quicksort(int *t, int start, int end)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(t, start, end);
		ft_quicksort(t, start, pivot - 1);
		ft_quicksort(t, pivot + 1, end);
	}
}
