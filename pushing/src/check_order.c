/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:40:45 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 15:01:53 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_order(t_int *p)
{
	t_int	*tmp;
	int		nbr;

	tmp = p->next;
	nbr = p->nbr;
	while (tmp)
	{
		if (nbr > tmp->nbr)
			return (0);
		nbr = tmp->nbr;
		tmp = tmp->next;
	}
	return (1);
}

int	check_invorder(t_int *p)
{
	t_int	*tmp;
	int		nbr;

	if (!p)
        return (0);
    tmp = p->next;
	nbr = p->nbr;
	while (tmp)
	{
		if (nbr < tmp->nbr)
			return (0);
		nbr = tmp->nbr;
		tmp = tmp->next;
	}
	return (1);
} 
