/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:44:20 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 16:04:39 by amansour         ###   ########.fr       */
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
	if (ASIZE < 50)
	{
		med = array[(ASIZE - 1) / 2];
		PAD = ASIZE / 2;
	}
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
	ASIZE = length(A);
	if (ASIZE == 3)
	{
		algo_min(env, &QUICK);
		return ;
	}
	if (!make_env(env))
		return ;
	MED = define_med(env);
	algo_normal(env);
	delete_stack(&A);
	A = ACOPY;
	if (ASIZE < 50)
		algo_med(env);
	else
		algo_max(env);
}
