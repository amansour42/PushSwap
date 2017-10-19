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

int	delete_pile(t_int **pile)
{
    /*t_int *tmp;

    tmp = *pile;
    while ((*pile)->next)
    {
        *pile = (*pile)->next;
        free(tmp);
        tmp = *pile;
    }
    free(*pile);*/
    /*while ((*pile)->next)
	{
		delete_pile_end(pile);
	   // delete_steps(pile);
	}
    free(*pile);
    *pile = NULL;*/
    while(*pile)
        delete_pile_end(pile);
	//while (1);
     //   ;
	return (0);
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
