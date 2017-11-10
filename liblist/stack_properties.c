/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:49:51 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 10:03:45 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

int	length(t_stack *p)
{
	int		i;
	t_stack	*tmp;

	tmp = p;
	i = 0;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}

int	min(t_stack *p)
{
	int		min;
	t_stack	*tmp;

	tmp = p->next;
	min = p->nbr;
	while (tmp)
	{
		if (min > tmp->nbr)
			min = tmp->nbr;
		tmp = tmp->next;
	}
	return (min);
}

int	max(t_stack *p)
{
	int		max;
	t_stack	*tmp;

	tmp = p->next;
	max = p->nbr;
	while (tmp)
	{
		if (max < tmp->nbr)
			max = tmp->nbr;
		tmp = tmp->next;
	}
	return (max);
}

int	nbr_from_position(t_stack *a, int pos)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 1;
	while (tmp && i != pos)
	{
		++i;
		tmp = tmp->next;
	}
	if (!tmp)
		return (-1);
	return (tmp->nbr);
}

int	pos_int(t_stack *a, int nbr)
{
	t_stack	*tmp;
	int		i;

	tmp = a;
	i = 1;
	while (tmp && tmp->nbr != nbr)
	{
		++i;
		tmp = tmp->next;
	}
	if (!tmp)
		return (1);
	return (i);
}
