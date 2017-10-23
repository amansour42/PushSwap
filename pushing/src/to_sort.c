/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 12:23:19 by amansour          #+#    #+#             */
/*   Updated: 2017/10/20 12:57:48 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort(t_int **pile)
{
	t_string	*lb;
	t_int		*b;
	t_string	*la;
    int         p;


	lb = NULL;
	b = NULL;
	la = NULL;
	p = pivot(*pile);
	put_pivot(pile, p);
	//affiche(*pile);
    push(&b, pile, 'b');
	while (*pile && !(check_order(*pile) && b->nbr < (*pile)->nbr))
	{
		while ((*pile)->nbr < p && !check_order(*pile))
		{
			push(&b, pile, 'b');
			lb = treat_b(&b);
			/*printf("OUI\n");*/
            print_steps(&lb, 'b');
			p = b->nbr;
            //printf("boucle infine\n");
		}
		/*printf("A\n");
		affiche(*pile);
		printf("B\n");
		affiche(b);*/
		if (!(check_order(*pile) && b->nbr < (*pile)->nbr))
		{
			//if (length(*pile) > 2)
			//{
				if (length(*pile) > 1)
                    p = close_min(*pile, b->nbr);
                //p = pivot(*pile);
                //printf("new pivot = %d\n", p);
				//push(&b, pile, 'b');
				//decale_a(pile, &b,p);
				//put_pivot(pile, p);
                if (length(*pile) > 1)
                    short_way(pile, pos_pivot(*pile, p));
                push(&b, pile, 'b');
                lb = treat_b(&b);
                print_steps(&lb, 'b');
                //printf("boucle infine ICI\n"); 
			//}
			//else
			/*{
				pile_swap(pile);
				ft_putstr("sa\n");
			}*/
		}
		//printf("A\n");
		//if (*pile)
        //    affiche(*pile);
		//sleep(1);
	}
	/*if (!check_order(*pile))
	{
		pile_swap(pile);
		ft_putstr("sa\n");
	}  */
	//printf("A\n");
	//affiche(*pile);
	while (b)
		push(pile, &b, 'a');
	return ;
}
