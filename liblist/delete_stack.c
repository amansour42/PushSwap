/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:35:28 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 13:38:39 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	delete_stack_end(t_stack **pile)
{
	t_stack *tmp;
	t_stack *ptmp;

	if (*pile)
	{
		if (!((*pile)->next))
		{
			free(*pile);
			*pile = NULL;
		}
		else
		{
			tmp = *pile;
			while ((tmp->next)->next)
				tmp = tmp->next;
			ptmp = tmp->next;
			tmp->next = NULL;
			free(ptmp);
		}
	}
	return ;
}

void	delete_stack_first(t_stack **pile)
{
	t_stack *tmp;

	if (*pile)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		free(tmp);
	}
	return ;
}

void	delete_stack(t_stack **a)
{
	while (*a)
		delete_stack_end(a);
	*a = NULL;
	return ;
}
