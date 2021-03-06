/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:36:51 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 12:10:35 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack			*copy_a(t_stack *a)
{
	t_stack	*copy;
	t_stack	*tmp;
	int		nbr;

	tmp = a;
	copy = NULL;
	while (tmp)
	{
		nbr = tmp->nbr;
		add_stack_end(&copy, nbr);
		tmp = tmp->next;
	}
	return (copy);
}

int				make_env(t_env *env)
{
	ACOPY = NULL;
	if (ASIZE <= 100 && !(ACOPY = copy_a(A)))
		return (FALSE);
	B = NULL;
	NORMAL = NULL;
	QUICK = NULL;
	update_env(env);
	return (TRUE);
}

void			update_env(t_env *env)
{
	if (A)
	{
		AMIN = min(A);
		AMAX = max(A);
		ASIZE = length(A);
	}
	else
		ASIZE = 0;
	if (B)
	{
		BMIN = min(B);
		BMAX = max(B);
		BSIZE = length(B);
	}
	else
		BSIZE = 0;
	return ;
}

void			clean(t_env *env)
{
	delete_stack(&A);
	delete_stack(&ACOPY);
	delete_steps(&QUICK);
	if (NORMAL)
		delete_steps(&NORMAL);
}
