/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:30:16 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 15:33:45 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		*pile;
	int		len;
//	char	*how;

//Lire les donnees sur l'entree standard = OK
	if (!(len = fill(ac, av, &pile)))
		exit_msg(ERROR);
	//Excecuter le tri
	if (!check_order(pile, len))
		sort(&pile, len);
	affiche(pile, len);
	//Afficher les instructions
	return (0);
}

void	affiche(int *pile, int len)
{
	while (len--)
	{
		printf("%d\n", *pile);
		++pile;
	}
	return ;
}
