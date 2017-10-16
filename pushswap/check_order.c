/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:40:45 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 15:52:51 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_order(int *p, int n)
{
	int i;
	int nb;

	i = 0;
	nb = *p;
	while (++i < n)
	{
		if (nb > p[i])
			return (0);
		nb = p[i];
	}
	return (1);
}

int check_invorder(int *p, int n)
{
	int i;
	int nb;

	i = 0;
	nb = *p;
	while (++i < n)
	{
		if (nb < p[i])
			return (0);
		nb = p[i];
	}
	return (1);
}              
