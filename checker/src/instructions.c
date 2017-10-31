/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 13:41:48 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 15:57:20 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	rotate(t_stack **p)
{
	int nbr;

	nbr = (*p)->nbr;
	delete_stack_first(p);
	add_stack_end(p, nbr);
	return ;
}

void	reverse_rotate(t_stack **p)
{
	int		nbr;
	t_stack	*tmp;

	tmp = *p;
	while (tmp->next)
		tmp = tmp->next;
	nbr = tmp->nbr;
	delete_stack_end(p);
	add_stack_first(p, nbr);
	return ;
}

void	stack_swap(t_stack **p)
{
	t_stack *tmp;

	tmp = (*p)->next;
	ft_swap(&((*p)->nbr), &(tmp->nbr));
	return ;
}
