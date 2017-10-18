/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:39:33 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 19:36:34 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	apply_rotate_reverse(char *s, t_int **a, t_int **b)
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

static void	apply_rotate(char *s, t_int **a, t_int **b)
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

static void	apply_push(char *s, t_int **a, t_int **b)
{
	int nbr;

	if (s[1] == 'a' && !isempty_list(*b))
	{
		nbr = (*b)->nbr;
		add_first_pile(a, nbr);
		delete_pile_first(b);
	}
	else if (s[1] == 'b' && !isempty_list(*a))
	{
		nbr = (*a)->nbr;
		add_first_pile(b, nbr);
		delete_pile_first(a);
	}
	return ;
}

static void	apply_swap(char *s, t_int **a, t_int **b)
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
	(i && (*a) && ((*a)->next)) ? pile_swap(a) : 0;
	(j && (*b) && ((*b)->next)) ? pile_swap(b) : 0;
	return ;
}

int			apply(t_int **a, t_string *l)
{
	t_int		*b;
	t_string	*tmp;
	int			result;

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
	result = isempty_list(b);
	delete_pile(&b);
	return (result);
}
