/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:29:27 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 13:38:16 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	add_stack_first(t_stack **pile, int nbr)
{
	t_stack *tmp;

	if ((tmp = (t_stack*)malloc(sizeof(t_stack))))
	{
		tmp->nbr = nbr;
		tmp->next = *pile;
		*pile = tmp;
	}
	return ;
}

void	add_stack_end(t_stack **pile, int nbr)
{
	t_stack *tmp;
	t_stack *list;

	tmp = NULL;
	if ((tmp = (t_stack*)malloc(sizeof(t_stack))))
	{
		tmp->nbr = nbr;
		tmp->next = NULL;
		if (!*pile)
			*pile = tmp;
		else
		{
			list = *pile;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}
