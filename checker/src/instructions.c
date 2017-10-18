/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 13:41:48 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 16:40:20 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
