/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:30:16 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 17:03:09 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	clean(t_stack **pile, t_step **l)
{
	delete_steps(l);
	delete_stack(pile);
	return ;
}

int		main(int ac, char **av)
{
	t_stack	*pile;
	t_step	*l;
	int		pb;

	pb = 1;
	if (ac < 2)
		return (0);
	if (!(pile = fill(ac, av)))
	{
		write(2, ERROR, 6);
		return (0);
	}
	l = read_steps(0, &pb);
	if (!pb)
	{
		clean(&pile, &l);
		write(2, "Error\n", 6);
		return (0);
	}
	(apply(&pile, l) && check_order(pile)) ?
	write(1, OK, 3) : write(1, KO, 3);
	clean(&pile, &l);
	return (0);
}
