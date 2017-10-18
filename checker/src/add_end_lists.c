/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end_lists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:27:14 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 16:28:09 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	add_end_pile(t_int **pile, int nbr)
{
	t_int *tmp;
	t_int *list;

	tmp = NULL;
	if ((tmp = (t_int*)malloc(sizeof(t_int))))
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

void	add_end_steps(t_string **steps, char *str)
{
	t_string *tmp;
	t_string *list;

	tmp = NULL;
	if ((tmp = (t_string*)malloc(sizeof(t_string))))
	{
		tmp->str = ft_strdup(str);
		tmp->next = NULL;
		if (!*steps)
			*steps = tmp;
		else
		{
			list = *steps;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}
