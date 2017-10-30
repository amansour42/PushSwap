/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:38:21 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 15:27:23 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(int *tab, int a, int b)
{
	int tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
	return ;
}

void		quicksort(int *tab, int len)
{
	int left;
	int rigth;
	int pivot;

	if (len <= 1)
		return ;
	pivot = tab[1];
	rigth = len - 1;
	left = 0;
	while (1)
	{
		while (tab[rigth] > pivot)
			--rigth;
		while (tab[left] < pivot)
			++left;
		if (left < rigth)
			swap(tab, left, rigth);
		else
			break ;
	}
	quicksort(tab, left);
	quicksort(tab + left, len - left);
}
