/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:37:03 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 16:10:08 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check_doublons(t_stack *a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		nbr;

	tmp1 = a;
	while (tmp1)
	{
		nbr = tmp1->nbr;
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->nbr == nbr)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static void	clean_split(char **s)
{
	int	nbr;

	nbr = 0;
	while (s[nbr])
		++nbr;
	while (--nbr >= 0)
	{
		free(*(s + nbr));
		*(s + nbr) = NULL;
	}
	return ;
}

static int	check_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) &&  str[i] != '-'
				&& str[i] != '+')
			return (0);
		++i;
	}
	return (1);
}

static int	fill_one_string(t_stack **p, char **s)
{
	int nbr;
	int i;
	int n;

	i = -1;
	n = 0;
	while (s[n])
		++n;
	while (++i < n)
	{
		if (!(check_digit(s[i])))
			return (0);
		nbr = ft_atoi(s[i]);
		if ((nbr == -1 && ft_strcmp(s[i], "-1"))
				|| (nbr == 0 && ft_strcmp(s[i], "0")))
			return (0);
		add_stack_end(p, nbr);
	}
	return (1);
}

t_stack		*fill(int ac, char **av)
{
	int		i;
	char	**s;
	t_stack *p;

	p = NULL;
	i = 0;
	while (++i < ac)
	{
		s = ft_strsplit(av[i], ' ');
		if (!(fill_one_string(&p, s)))
		{
			delete_stack(&p);
			clean_split(s);
			free(s);
			return (NULL);
		}
		clean_split(s);
		free(s);
	}
	if (p->next && !check_doublons(p))
		delete_stack(&p);
	return (p);
}
