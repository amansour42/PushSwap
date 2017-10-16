/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:08:55 by amansour          #+#    #+#             */
/*   Updated: 2017/10/16 15:57:04 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		check_entry(int ac, char **av)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (++i < ac)
	{
		//if (!digit_test(av[i]))
		//	return (0);//pour le check de l'existence que des digits
		n += nbr_cases(ft_strsplit(av[i],' '));//calculer le nombre de nombres existants
	}
	return (n);
}

static void	fill_one_string(int **p, int *start, char **s)
{
	int n;

	n = nbr_cases(s);
	while (n--)
	{
		(*p)[*start] = ft_atoi(*s);
		++s;
		*start += 1;
	}
	return ;
}

int			fill(int ac, char **av, int **p)
{

	int		i;
	int		n;

	*p = NULL;
	if (!(n = check_entry(ac, av)))
		return (0);
	if (((*p) = (int*)malloc(sizeof(int) * n)))
	{
		i = 0;
		n = 0;
		while (++i < ac)
			fill_one_string(p, &n,ft_strsplit(av[i], ' '));
		return (n);
	}
	return (0);
}
