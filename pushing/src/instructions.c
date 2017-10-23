/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 13:41:48 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 16:29:42 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_int **p)
{
	int nbr;

	nbr = (*p)->nbr;
	delete_pile_first(p);
	add_end_pile(p, nbr);
	return ;
}

void	reverse_rotate(t_int **p)
{
	int		nbr;
	t_int	*tmp;

	tmp = *p;
	while (tmp->next)
		tmp = tmp->next;
	nbr = tmp->nbr;
	delete_pile_end(p);
	add_first_pile(p, nbr);
	return ;
}

void	pile_swap(t_int **p)
{
	t_int *tmp;

	tmp = (*p)->next;
	ft_swap(&((*p)->nbr), &(tmp->nbr));
	return ;
}

char   * push(t_int **a, t_int **b, char c)
{
	int nbr;

	nbr = (*b)->nbr;
	add_first_pile(a, nbr);
	delete_pile_first(b);
	if (c == 'a')
        return ("pa\n");
    return ("pb\n");
}

