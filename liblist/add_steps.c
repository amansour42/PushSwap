/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_steps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:29:46 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 16:58:06 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

void	add_steps_end(t_step **steps, char *str)
{
	t_step *tmp;
	t_step *list;

	tmp = NULL;
	if ((tmp = (t_step*)malloc(sizeof(t_step))))
	{
		tmp->str = str;
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
