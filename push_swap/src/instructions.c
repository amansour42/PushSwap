/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:37:25 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 15:24:34 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*rotate(t_env *env, char c)
{
	int	nbr;

	nbr = (c == 'a') ? ANBR : BNBR;
	if (c == 'a')
	{
		delete_stack_first(&A);
		add_stack_end(&A, nbr);
		return ("ra\n");
	}
	else
		delete_stack_first(&B);
	add_stack_end(&B, nbr);
	return ("rb\n");
}

char	*reverse_rotate(t_env *env, char c)
{
	int		nbr;
	t_stack	*tmp;

	tmp = (c == 'a') ? A : B;
	while (tmp->next)
		tmp = tmp->next;
	nbr = tmp->nbr;
	if (c == 'a')
	{
		delete_stack_end(&A);
		add_stack_first(&A, nbr);
		return ("rra\n");
	}
	delete_stack_end(&A);
	add_stack_first(&A, nbr);
	return ("rrb\n");
}

char	*stack_swap(t_env *env, char c)
{
	t_stack *tmp;

	tmp = (c == 'a') ? ANEXT : BNEXT;
	if (c == 'a')
	{
		ft_swap(&(ANBR), &(tmp->nbr));
		return ("sa\n");
	}
	ft_swap(&(BNBR), &(tmp->nbr));
	return ("sb\n");
}

char	*push(t_env *env, char c)
{
	int		nbr;

	nbr = (c == 'a') ? BNBR : ANBR;
	if (c == 'a')
	{
		add_stack_first(&A, nbr);
		delete_stack_first(&B);
		return ("pa\n");
	}
	add_stack_first(&B, nbr);
	delete_stack_first(&A);
	return ("pb\n");
}
