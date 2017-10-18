/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 13:39:29 by amansour          #+#    #+#             */
/*   Updated: 2017/10/16 15:23:18 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char    *treat_a(int **p, int n, int *a) //OK
{
	int     min;

	min = (n >= 3) ? MIN((*p)[1], (*p)[n - 1]) : (*p)[1];
	*a = (*p)[0];
	if (*a >= min)
	{
		if (n >= 3 && min == (*p)[n - 1])
		{
			reverse_rotate(p, n);
			*a = (*p)[0];
			return ("ra\n");
		}
		else
		{
			*a = (*p)[1];
			ft_swap(&(*p)[0], &(*p)[1]);
			return ("sa\n");
		}
	}
	return ("");
}

void	add_to(int **pile, int a, int *n, char c)//OK
{
	int i;
	
	*n += 1;
	i = *n - 1;
	while (i >= 1)
	{
		(*pile)[i] = (*pile)[i - 1];
		--i;
	}
	(*pile)[0] = a;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return ;
}

t_opt	ft_opnew(int n, char *s)
{
	t_opt op;

	op.s = s;
	op.n = n;
	return (op);
}

t_opt	treat_b(int **p, int len)
{
	int		i;
	t_opt	op;

	op = ft_opnew(0, NULL);
	if (len == 1)
		return (op);
	if ((*p)[0] <= (*p)[len - 1])
	{
		rotate(p, len);
		return (ft_opnew(1, RB));
	}
	else if ((*p)[0] < (*p)[1])
	{
		op.s = SB;
		while ((*p)[0] < (*p)[1])
		{
			++op.n;
			ft_swap(&(*p)[0], &(*p)[1]);
			rotate(p, len);
		}
		i = op.n + 1;
		while (--i)
			reverse_rotate(p, len);
	}
	return (ft_opnew(0, NULL));
}
