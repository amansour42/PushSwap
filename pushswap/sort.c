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

void		sort(int **p, int n)//norminette = une ligne en plus
{
	int		a;
	int		m;
	int		*b;
	t_list  *l;;

    m = 0;
    l = NULL;
  
    if ((b = (int*)malloc(sizeof(int) * n)))
	{
		while (n != 2 && (!check_order(*p, n) || !m || (*p)[0] < b[m - 1]))
		{
			to_write(l, treat_a(p, n, &a));
            if (l)
            {
                ft_lstdel2(&l);
                l = NULL;//pas obligatoire
            }
		    //printf("ya rab a = %d\n", a);
            add_to(&b, a, &m, 'b'); 
            decale(p, n);
            --n;
		    //add_to(&b, a, &m, 'b');
		    if (m == 2 && !check_invorder(b, n))   
            {
                ft_swap(&b[0], &b[1]);
                l = (t_list*)malloc(sizeof(t_list));
                l->next = NULL;
                l->content = (void*)SB;
             } 
            else
                l = treat_b(&b, m);
		}
        if (n == 2 && !check_order(*p, n))   
        {
            ft_swap(&(*p)[0], &(*p)[1]);
            to_write(l, "sa\n");
        } 
        else
            write_b(l);
        if (l)
            ft_lstdel2(&l);
	   // printf("A\n");
       // affiche(*p, n);
       // printf("B\n");
       // affiche(b, m);
        a = -1;
		while (b && ++a < m)
		add_to(p, b[a], &n, 'a');
    }
	return ;
}
