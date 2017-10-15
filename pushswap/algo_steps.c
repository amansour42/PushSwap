/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 13:39:29 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 17:27:32 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		treat_a(int **p, int n) //n est le nombre de cases remplies, attention, il faut garder le vrai nombre
{
	int a;
	int min;

	min = (n >= 3) ? MIN((*p)[1], (*p)[n - 1]) : (*p)[1];
	a = (*p)[0];
	if (a >= min)
	{
		if (n >= 3 && (*p)[1] >= (*p)[n - 1])
		{
		//	printf("deuxieme >= dernier => echange dernier et premier et mettre le sommet en B\n");
			reverse_rotate(p, n, 'a');
			a = (*p)[0];
		}
		else
		{
			//printf("dernier > deuxieme => echange deuxieme  et premier et mettre le sommet en B\n");
			a = (*p)[1];
			ft_swap(&(*p)[0], &(*p)[1]);
//			printf("asbar \n");
			//affiche(*p, n);
			write(1, "sa\n", 3);
			//return (a);
		}
	}
//	printf("aucun echange et mettre le sommet en B\n");
//	if (n != 2)
//		decale(p, n);
	return (a);
}

void	add_to(int **pile, int a, int *n, char c)
{
	int i;

	i = *n + 1;
	while (--i > 0)
	{
//		printf("I = %d\n", i);
		(*pile)[i] = (*pile)[i - 1];
	}
	(*pile)[0] = a;
	*n += 1;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
	return ;
}

void	treat_b(int **p, int len) //len le nombre de cases remplies//PB : exemple 57 71 67 29 81 32 94
{
	if (len == 1)
		return ;//a definir apres
	if ((*p)[0] <= (*p)[len - 1])
	{
		rotate(p, len, 'b');
		printf("0 <= dernier => faire une rotation\n");
		printf("THIS B \n");
		affiche(*p, len);
	}
	else if ((*p)[0] < (*p)[1])
	{
//		printf("0 <= duxieme => faire des swaps jusqu'a arriver au bon ordre\n");
		while ((*p)[0] < (*p)[1])
		{
			write(1, "sb\n", 3);
			ft_swap(&(*p)[0], &(*p)[1]);
			rotate(p, len, 'b');
		}
	}
	return ;
}
