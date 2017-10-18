/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:08:55 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 18:16:26 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		check_entry(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!digit_test(av[i]))
			return (0);
	}
	return (1);
}

static int	check_doublons(t_int *a)
{
	t_int *tmp1;
	t_int *tmp2;

	tmp1 = a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->nbr == tmp1->nbr)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static int	fill_one_string(t_int **p, char **s)
{
	int n;
	int nbr;
	int i;
	char *str;

	n = nbr_cases(s); //to see for leaks
	i = -1;
	while (++i < n)
	{
		str = *s;
		nbr = ft_atoi(str);
		++s;
		free(str);
		if (nbr == -1 && ft_strcmp(s[i], "-1"))
			return (0);
		add_end_pile(p, nbr);
	}
	return (1);
}

t_int			*fill(int ac, char **av, int *n)
{
	int		i;
	t_int	*p;

	p = NULL;
	if (!check_entry(ac, av))
		return (NULL);
	i = 0;
	while (++i < ac)
	    if (!(fill_one_string(&p, ft_strsplit(av[i], ' '))))
		{
			*n = 0;
			return (p);
		}
	if (!check_doublons(p))
		*n = 0;
	return (p);
}
