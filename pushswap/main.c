/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:30:16 by amansour          #+#    #+#             */
/*   Updated: 2017/10/16 15:01:30 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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
	printf("FINAL RESULT\n");
    affiche(pile, len);
	//Afficher les instructions
//	while (1);
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
