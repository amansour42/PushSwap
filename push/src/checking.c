/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:34:45 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 16:02:05 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_order(t_stack *p)
{
	t_stack	*tmp;
	int		nbr;

	tmp = p->next;
	nbr = p->nbr;
	while (tmp)
	{
		if (nbr > tmp->nbr)
			return (FALSE);
		nbr = tmp->nbr;
		tmp = tmp->next;
	}
	return (TRUE);
}

int	check_sup(t_stack *a, int med)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->nbr < med)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}
