/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:55:56 by amansour          #+#    #+#             */
/*   Updated: 2017/10/20 10:20:06 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int ac, char **av)
{
	t_int		*pile;

	if (ac < 2)
		return (0);
	if (!(pile = fill(ac, av)))
		exit_msg(ERROR);
	/*printf("First\n");
    affiche(pile);*/
	if (!check_order(pile))
		sort(&pile);
	//printf("Result PUSH\n");
    //affiche(pile);
    /*if (check_order(pile))
        printf("OK\n");
    else
      printf("KO\n"); */ 
    delete_pile(&pile);
	return (0);
}
