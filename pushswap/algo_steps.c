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

char    *treat_a(int **p, int n, int *a) //n est le nombre de cases remplies, attention, il faut garder le vrai nombre
{
	int     min;

	min = (n >= 3) ? MIN((*p)[1], (*p)[n - 1]) : (*p)[1];
	*a = (*p)[0];
	if (*a >= min)
	{
		if (n >= 3 && (*p)[1] >= (*p)[n - 1])
		{
			reverse_rotate(p, n);
            *a = (*p)[0];
            return ("ra\n");          
		}
		else
		{
			*a = (*p)[1];
			ft_swap(&(*p)[0], &(*p)[1]);
			//printf("HI %d\n", *a);
            return ("sa\n");
		}
	}
	return ("");
}

void	add_to(int **pile, int a, int *n, char c)
{
	int i;

    //printf("B before\n");
    //printf("AAAAAAAAAAAA = %d\n", a);
    //affiche(*pile, *n);
	*n += 1;
    i = *n - 1;
	while (i >= 1)
    {
		(*pile)[i] = (*pile)[i - 1];
        --i;
    }
	(*pile)[0] = a;
	if (c == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
    //printf("B after\n");
    //affiche(*pile, *n); 
	return ;
}

t_list  *treat_b(int **p, int len)//utiliser ft_lstnew.
{
	int     i;
    t_list  *l;
    t_list  *new;

    l = NULL;
    if (len == 1)
		return (NULL);
	if ((*p)[0] <= (*p)[len - 1] && len != 2 && (l = (t_list*)malloc(sizeof(t_list))))
    {
            l->content = (void*)RB;
            l->next = NULL;
		    rotate(p, len);
    }
	else if ((*p)[0] < (*p)[len - 1])
	{
        i = 1;
		while ((*p)[0] < (*p)[1])
		{
            if (!(new = (t_list*)malloc(sizeof(t_list))))
                return (NULL);
            new->content = (void*)SB;
            new->next = NULL;
            if (!l)
		        l = new;
            else
                ft_lstadd(&l, new);
            ft_swap(&(*p)[0], &(*p)[1]); 
			++i;
            if (!(new = (t_list*)malloc(sizeof(t_list))))
                return (NULL);
            new->next = NULL;
            new->content = (void*)RB;
            ft_lstadd(&l, new);
            rotate(p, len);
            free(new);
		}
        while (--i)
        {
             if (!(new = (t_list*)malloc(sizeof(t_list))))
                return (NULL);
            new->next = NULL;
            new->content = (void*)RB;
            ft_lstadd(&l, new); 
            reverse_rotate(p, len);
        }
    }
	return (l);
}
