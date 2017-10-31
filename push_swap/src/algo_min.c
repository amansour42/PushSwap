/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:31:31 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 16:01:40 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	algo_min(t_env *env, t_step **steps)
{
	while (A && !check_order(A))
	{
		if (ANBR == AMAX)
			add_steps_end(steps, rotate(env, 'a'));
		else if (nbr_from_position(A, ASIZE) == AMAX)
			add_steps_end(steps, stack_swap(env, 'a'));
		else if (nbr_from_position(A, ASIZE) == AMIN)
			add_steps_end(steps, reverse_rotate(env, 'a'));
		else
		{
			add_steps_end(steps, reverse_rotate(env, 'a'));
			add_steps_end(steps, reverse_rotate(env, 'a'));
		}
	}
	return ;
}
