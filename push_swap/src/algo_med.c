/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:31:15 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 16:01:29 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	test_in_b(t_env *env, t_step **step)
{
	if (!B)
		return ;
	if (BNBR < BMIN)
	{
		add_steps_end(step, rotate(env, 'b'));
		BMIN = BNBR;
	}
	return ;
}

void	algo_med(t_env *env)
{
	t_step *step;

	step = NULL;
	while (1)
	{
		min_end_a(env, &step);
        while (check_sup(A, MED) && ASIZE > 3)
		{
			if (ANBR < MED)
			{
				add_steps_end(&step, push(env, 'b'));
				test_in_b(env, &step);
			}
			else
				add_steps_end(&step, rotate(env, 'a'));
			update_env(env);
		}
		if (ASIZE <= 3)
			break ;
		MED = define_med(env);
	}
	algo_min(env, &step);
	push_to_a(env, &step);
	QUICK = step;
}
