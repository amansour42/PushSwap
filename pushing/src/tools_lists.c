/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:16:47 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 15:10:01 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	last(t_int *p)
{
	t_int *tmp;

	tmp = p;
	while(tmp->next)
		tmp = tmp->next;
	return (tmp->nbr);
}

int length(t_int *p)
{
    int     i;
    t_int   *tmp;
    
    tmp = p;
    i = 0;
    while (tmp)
    {
        ++i;
        tmp = tmp->next;
    }
    return (i);
}
