/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:44:20 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 15:18:57 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static int	*fill_from_stack(t_stack *a, int len)
{
	int		*tab;
	t_stack	*tmp;
	int		i;

	tab = NULL;
	if ((tab = (int*)malloc(sizeof(int) * len)))
	{
		i = 0;
		tmp = a;
		while (tmp)
		{
			tab[i++] = tmp->nbr;
			tmp = tmp->next;
		}
	}
	return (tab);
}

int			define_med(t_env *env)
{
	int *array;
	int med;

	array = fill_from_stack(A, ASIZE);
	quicksort(array, ASIZE);
	if (ASIZE < 100)
		med = array[(ASIZE - 1) / 2];
	else
	{
		med = array[(ASIZE - 1) / 10];
		PAD = ASIZE / 10;
	}
	free(array);
	return (med);
}

void		sort(t_env *env)
{
	ACOPY = NULL;
	ASIZE = length(A);
	if (ASIZE <= 3)
	{
		algo_min(env, &QUICK);
		return ;
	}
	if (!make_env(env))
		return ;
	MED = define_med(env);
	if (ASIZE <= 100)
	{
		algo_normal(env);
		delete_stack(&A);
		A = copy_a(ACOPY);
	}
	if (ASIZE < 50)
		algo_med(env);
	else
		algo_max(env);
}
