/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:32:26 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 15:17:15 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	best_case(t_env *env, t_step *steps)
{
	int		i;

	i = 0;
	if (!A)
		return ;
	while (!check_order(A))
	{
		add_steps_end(&steps, rotate(env, 'a'));
		if (!NORMAL)
			NORMAL = steps;
	}
	return ;
}

static	int	two_cases(t_stack *a)
{
	int		pos;
	int		len;
	int		i;

	pos = pos_int(a, min(a));
	len = length(a);
	i = 1;
	while (i <= len)
	{
		if (nbr_from_position(a, (i + pos) % len) <
			nbr_from_position(a, (i + pos + 1) % len))
			return (FALSE);
		++i;
	}
	return (TRUE);
}

void		algo_normal(t_env *env)
{
	t_step *steps;

	steps = NULL;
	while (!check_order(A))
	{
		if (two_cases(A))
		{
			best_case(env, steps);
			break ;
		}
		if (!(ANBR == AMAX && ASECOND == AMIN) && ANBR > ASECOND)
			add_steps_end(&steps, stack_swap(env, 'a'));
		else
			add_steps_end(&steps, rotate(env, 'a'));
	}
	NORMAL = steps;
	return ;
}
