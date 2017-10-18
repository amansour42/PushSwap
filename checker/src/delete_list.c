/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:01:39 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 19:39:20 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	delete_pile(t_int **pile)
{
	if (*pile)
	{
		delete_pile_end(pile);
		delete_pile(pile);
	}
	return ;
}

void	delete_steps(t_string **steps)
{
	if (*steps)
	{
		delete_steps_first(steps);
		delete_steps(steps);
	}
	return ;
}

void	clean_lists(t_int **pile, t_string **steps)
{
	delete_steps(steps);
	delete_pile(pile);
	return ;
}
