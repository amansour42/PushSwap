/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:30:00 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 16:01:18 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	min_end_a(t_env *env, t_step **steps)
{
	while (ASIZE > 1 && nbr_from_position(A, ASIZE) == AMIN)
	{
		add_steps_end(steps, reverse_rotate(env, 'a'));
		add_steps_end(steps, push(env, 'b'));
		test_in_b(env, steps);
		update_env(env);
	}
	return ;
}

void	algo_max(t_env *env)
{
	t_step *steps;

	steps = NULL;
	while (1)
	{
		min_end_a(env, &steps);
		while (check_sup(A, MED) && ASIZE > 1)
		{
			if (A && ANBR < MED)
			{
				add_steps_end(&steps, push(env, 'b'));
				test_in_b(env, &steps);
			}
			else if (A)
				add_steps_end(&steps, rotate(env, 'a'));
			update_env(env);
		}
		if ((MED += PAD) > AMAX || ASIZE <= 1)
			break ;
	}
	push_to_a(env, &steps);
	QUICK = steps;
}
