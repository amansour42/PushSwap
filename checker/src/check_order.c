/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:40:45 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 15:56:48 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	check_order(t_stack *p)
{
	t_stack	*tmp;
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
