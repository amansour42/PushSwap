/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:26:19 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 16:26:27 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_first_pile(t_int **pile, int nbr)
{
	t_int *tmp;

	if ((tmp = (t_int*)malloc(sizeof(t_int))))
	{
		tmp->nbr = nbr;
		tmp->next = *pile;
		*pile = tmp;
	}
	return ;
}
