/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:33:16 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 17:19:32 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		sort(int **p, int len)
{

	int		a;
	int		m;
	int		*b;
	int		n;
	//how = NULL;
	m = 0;
	n = len;
	if ((b = (int*)malloc(sizeof(int) * n)))
	{
		//printf("HELLO : On commence!\n");
		while (!check_order(*p, n) || !m || (*p)[0] < ft_max(b, n))
		{
			a = treat_a(p, n);
		//	printf("LE AAAAAAAAAAAa = %d\n", a);
			//printf("A\n");
			//affiche(*p, n);
				decale(p, n);
		//		printf("HELLO : On est dans la boucle du tri!\n");
				--n;
				add_to(&b, a, &m, 'b');
				//printf("M = %d\n", m);
				treat_b(&b, m);
			//	printf("THIS IS B!\n");
			//	affiche(b, m);
			//printf("A\n");
			//affiche(*p, n);
		}
		//printf("THIS IS B!\n");
		//affiche(b, m);
		//printf("THIS IS A!\n");
		//affiche(*p, n);
		a = -1;
		//printf("HELLO : On est a la fin du tri!\n");
		while (++a < m)
		{
		//affiche (b, m);
		add_to(p, b[a], &n, 'a');
		}
	}
	return ;
}
