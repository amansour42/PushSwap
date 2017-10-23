/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:08:55 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 12:01:05 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_doublons(t_int *a)
{
	t_int	*tmp1;
	t_int	*tmp2;
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

static void clean_split(char **s)
{
	int	nbr;

	nbr = nbr_cases(s);
	while (--nbr >= 0)
	{
		free(*(s + nbr));
		*(s  + nbr) = NULL;
	}
	return ;
}

static int	fill_one_string(t_int **p, char **s)
{
	int nbr;
	int i;
	int n;

	i = -1;
	n = nbr_cases(s);
	while (++i < n)
	{
		nbr = ft_atoi(s[i]);
		if ((nbr == -1 && ft_strcmp(s[i], "-1"))
				|| (nbr == 0 && ft_strcmp(s[i], "0")))
			return (0);
		add_end_pile(p, nbr);
	}
	return (1);
}

t_int		*fill(int ac, char **av)
{
	int		i;
	char	**s;
	t_int	*p;

	p = NULL;
	i = 0;
	while (++i < ac)
	{
		s = ft_strsplit(av[i], ' ');
		if (!(fill_one_string(&p, s)))
		{
			delete_pile(&p);
			clean_split(s);
			free(s);
			return (NULL);
		}
		clean_split(s);
		free(s);
	}
	if (p->next && !check_doublons(p))
		delete_pile(&p);
	return (p);
}
