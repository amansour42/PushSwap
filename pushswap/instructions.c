/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 13:41:48 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 15:05:05 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(int **p, int n)
{
	int tmp;

	tmp = (*p)[0];
	decale(p, n);
	(*p)[n - 1] = tmp;
	return;
}

void	decale(int **p, int n)
{
	int i;

	i = 0;
	while(++i < n)
		(*p)[i - 1] = (*p)[i];
	return ;
}

void	reverse_rotate(int **p, int n)
{
	int i;
	int tmp;

	i = n;
	tmp = (*p)[n - 1];
	while(--i)
		(*p)[i] = (*p)[i - 1];
	(*p)[0] = tmp;
	return ;
}
