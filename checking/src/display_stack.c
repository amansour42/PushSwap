/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:28:26 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 17:28:44 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	affiche(t_int *pile)
{
	t_int *tmp;

	tmp = pile;
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	return ;
}
