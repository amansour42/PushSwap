/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:39:33 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 16:47:57 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	apply_rotate_reverse(char *s, t_stack **a, t_stack **b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[2] == 'r')
	{
		++j;
		++i;
	}
	else
		(s[2] == 'a') ? ++i : ++j;
	(i && (*a) && ((*a)->next)) ? reverse_rotate(a) : 0;
	(j && (*b) && ((*b)->next)) ? reverse_rotate(b) : 0;
	return ;
}

static void	apply_rotate(char *s, t_stack **a, t_stack **b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[1] == 'r')
	{
		++j;
		++i;
	}
	else
		(s[1] == 'a') ? ++i : ++j;
	(i && (*a) && ((*a)->next)) ? rotate(a) : 0;
	(j && (*b) && ((*b)->next)) ? rotate(b) : 0;
	return ;
}

static void	apply_push(char *s, t_stack **a, t_stack **b)
{
	int nbr;

	if (s[1] == 'a' && (*b))
	{
		nbr = (*b)->nbr;
		add_stack_first(a, nbr);
		delete_stack_first(b);
	}
	else if (s[1] == 'b' && (*a))
	{
		nbr = (*a)->nbr;
		add_stack_first(b, nbr);
		delete_stack_first(a);
	}
	return ;
}

static void	apply_swap(char *s, t_stack **a, t_stack **b)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[1] == 's')
	{
		++j;
		++i;
	}
	else
		(s[1] == 'a') ? ++i : ++j;
	(i && (*a) && ((*a)->next)) ? stack_swap(a) : 0;
	(j && (*b) && ((*b)->next)) ? stack_swap(b) : 0;
	return ;
}

int			apply(t_stack **a, t_step *l)
{
	t_stack	*b;
	t_step	*tmp;

	b = NULL;
	tmp = l;
	while (tmp)
	{
		if ((tmp->str)[0] == 'r' && (tmp->str)[2])
			apply_rotate_reverse(tmp->str, a, &b);
		else if ((tmp->str)[0] == 'r')
			apply_rotate(tmp->str, a, &b);
		else if ((tmp->str)[0] == 'p')
			apply_push(tmp->str, a, &b);
		else if ((tmp->str)[0] == 's')
			apply_swap(tmp->str, a, &b);
		tmp = tmp->next;
	}
	if (b)
	{
		delete_steps(&l);
		delete_stack(&b);
		return (0);
	}
	return (1);
}
