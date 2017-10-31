/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:30:16 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 15:56:09 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	clean(t_stack **pile, t_step **l)
{
	delete_steps(l);
	delete_stack(pile);
	return ;
}

int			main(int ac, char **av)
{
	t_stack	*pile;
	t_step	*l;
	int		pb;

	pb = 1;
	l = NULL;
	if (ac < 2)
		return (0);
	if (!(pile = fill(ac, av)))
	{
		write(2, ERROR, 6);
		return (0);
	}
	read_steps(0, &pb, &l);
	if (!pb)
	{
		clean(&pile, &l);
		write(2, "Error\n", 6);
		return (0);
	}
	(apply(&pile, &l) && check_order(pile)) ?
	write(1, OK, 3) : write(1, KO, 3);
	delete_stack(&pile);
	sleep(30);
	return (0);
}
