/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:40:27 by amansour          #+#    #+#             */
/*   Updated: 2017/10/13 18:08:09 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void fill_pile(t_pile **pile, char **str)
{
	t_pile *tmp;
	t_pile *prev;

	prev = *pile;
	if (!(*pile) && !(tmp = (t_pile*)malloc(sizeof(t_pile))))
		return ;
	while (*str)
	{
		tmp->nb = ft_atoi(*str);
		if (prev)
			prev->p = tmp;
		else 
			prev = tmp;
		++str;
		prev = tmp;
	}
	tmp->p = NULL;
	free(tmp);
	return ;
}
