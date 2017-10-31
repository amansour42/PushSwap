/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:39:33 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 15:56:35 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

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

int			apply(t_stack **a, t_step **l)
{
	t_stack	*b;
	char	*str;

	b = NULL;
	while (*l)
	{
		str = (*l)->str;
		if (str[0] == 'r' && str[2])
			apply_rotate_reverse(str, a, &b);
		else if (str[0] == 'r')
			apply_rotate(str, a, &b);
		else if (str[0] == 'p')
			apply_push(str, a, &b);
		else if (str[0] == 's')
			apply_swap(str, a, &b);
		delete_steps_first(l);
	}
	if (b)
	{
		delete_stack(&b);
		return (0);
	}
	return (1);
}
