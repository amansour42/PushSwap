/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:53:02 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 13:40:59 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

int		steps_length(t_step *steps)
{
	t_step	*tmp;
	int		i;

	tmp = steps;
	i = 0;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
