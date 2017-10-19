/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:01:39 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 10:44:53 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	delete_pile(t_int **pile)
{
	while(*pile)
		delete_pile_end(pile);
	return ;
}

void	delete_steps(t_string **steps)
{
	while (*steps)
		delete_steps_first(steps);
	return ;
}

void	clean_lists(t_int **pile, t_string **steps)
{
	delete_steps(steps);
	delete_pile(pile);
	return ;
}
