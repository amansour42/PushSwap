/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:30:16 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 19:41:28 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_int		*pile;
	t_string	*l;
	int			pb;

	pb = 1;
	if (ac < 2)
		return (0);
    pile = NULL;
    fill(ac, av, &pile);
    sleep(60);
    if (!pile)
        exit_msg(ERROR);
	l = read_steps(0, &pb);
	if (!pb)
	{
		clean_lists(&pile, &l);
		exit_msg(ERROR);
	}
	(apply(&pile, l) && check_order(pile)) ? write(1, OK, 3) : write(1, KO, 3);
	affiche(pile);
	clean_lists(&pile, &l);
	return (0);
}
