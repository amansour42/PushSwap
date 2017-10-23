/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_alink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:36:41 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 10:43:51 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	delete_pile_end(t_int **pile)
{
	t_int *tmp;
	t_int *ptmp;

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

void	delete_steps_end(t_string **steps)
{
	t_string *tmp;

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

void	delete_pile_first(t_int **pile)
{
	t_int *tmp;

	if (*pile)
	{
		tmp = *pile;
		*pile = (*pile)->next;
		free(tmp);
	}
	return ;
}

void	delete_steps_first(t_string **steps)
{
	t_string *tmp;

	if (*steps)
	{
		tmp = *steps;
		*steps = (*steps)->next;
		free(tmp->str);
		free(tmp);
	}
	return ;
}
