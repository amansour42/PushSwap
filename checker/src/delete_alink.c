/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_alink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:36:41 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 19:38:36 by amansour         ###   ########.fr       */
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
			//printf("je suis rentre1e\n");
			free(*pile);
			*pile = NULL;
		}
		else
		{
			//printf("je suis rentree2\n");
			tmp = *pile;
			while ((tmp->next)->next)
				tmp = tmp->next;
			ptmp = tmp->next;
			tmp->next = NULL;
			free(ptmp);
		}
	}
    //while (1);
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
