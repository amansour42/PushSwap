/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:35:46 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 17:06:12 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	delete_steps_end(t_step **steps)
{
	t_step *tmp;

	if (*steps)
	{
		if (!((*steps)->next))
		{
			free(*steps);
			*steps = NULL;
		}
		else
		{
			tmp = *steps;
			while ((tmp->next)->next)
				tmp = tmp->next;
			free(tmp->next);
			tmp->next = NULL;
		}
	}
	return ;
}

void	delete_steps_first(t_step **steps)
{
	t_step *tmp;

	if (*steps)
	{
		tmp = *steps;
		*steps = (*steps)->next;
		free(tmp);
	}
	return ;
}

void	delete_steps(t_step **steps)
{
	while (*steps)
		delete_steps_first(steps);
	return ;
}
