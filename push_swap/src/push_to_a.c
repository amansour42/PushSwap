/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:38:04 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 15:26:19 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		just_before(t_env *env, int nbr)
{
	int		closest;
	int		current;
	int		i;
	t_stack	*tmp;

	current = AMAX;
	closest = (current > nbr) ? current : MINT;
	tmp = A;
	i = 0;
	while (i < ASIZE)
	{
		if (tmp->nbr > nbr && tmp->nbr < current)
		{
			closest = tmp->nbr;
			current = tmp->nbr;
		}
		tmp = tmp->next;
		++i;
	}
	return (closest);
}

static void		update(t_env *env, t_step **steps)
{
	while (!check_order(A))
	{
		if (pos_int(A, AMIN) < ASIZE / 2)
			add_steps_end(steps, rotate(env, 'a'));
		else
			add_steps_end(steps, reverse_rotate(env, 'a'));
	}
}

void			push_to_a(t_env *env, t_step **steps)
{
	int	closest;
	int	pos;

	while (B)
	{
		closest = just_before(env, BNBR);
		(closest == MINT) ? closest = AMIN : 0;
		pos = pos_int(A, closest);
		if (pos > ASIZE / 2)
			while (ANBR != closest)
				add_steps_end(steps, reverse_rotate(env, 'a'));
		else
			while (ANBR != closest)
				add_steps_end(steps, rotate(env, 'a'));
		add_steps_end(steps, push(env, 'a'));
		update_env(env);
	}
	update(env, steps);
}
