/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_steps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:36:38 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 09:18:53 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	display_steps(t_step *steps)
{
	t_step *tmp;

	tmp = steps;
	while (tmp)
	{
		if (!ft_strcmp(tmp->str, "pb\n") && tmp->next
			&& !ft_strcmp(tmp->next->str, "pa\n"))
			tmp = tmp->next;
		else
			ft_putstr(tmp->str);
		tmp = tmp->next;
	}
	return ;
}
