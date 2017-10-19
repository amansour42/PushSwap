/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 11:08:55 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 18:16:26 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		check_entry(int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!digit_test(av[i]))
			return (0);
	}
	return (1);
}

static int	check_doublons(t_int *a)
{
	t_int *tmp1;
	t_int *tmp2;

	tmp1 = a;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp2->nbr == tmp1->nbr)
                    return (0);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (1);
}

static void clean_split(char **s)
{
    //int     i;
   int     nbr;
    char    **str;

    nbr = nbr_cases(s);
    //i = -1;
    str = s + nbr - 1;
    //while (++i <= nbr)
    free(*(s + nbr));
    *(s + nbr) = NULL;
    while (--nbr >= 0)
    {
        printf("%d = %s\n", nbr, *(s + nbr));
        free(*(s + nbr));
        *(s  + nbr) = NULL;
    }
    free(*s);
    //**s = NULL;
    //printf("%d = %s\n", i, s[0]);   
    return ;
}

static int	fill_one_string(t_int **p, char **s)
{
	int nbr;
	int i;

	i = -1;
	while (s[++i])
	{
		//nbr = ft_atoi(s[i]);
        nbr = 5;
        //if (nbr == -1 && ft_strcmp(s[i], "-1"))
          //  return (0);
        add_end_pile(p, nbr);
	}
	return (1);
}

void        fill(int ac, char **av, t_int **p)
{
	int		i;
    char    **s;

	if (!check_entry(ac, av))
        return ;
	i = 1;
    printf("AC = %d\nav = %s\n", ac, av[1]);
    while (i < ac)
    {
        s = ft_strsplit(av[i], ' ');
        if (!(fill_one_string(p, s)))
		{
            //sleep(60);
            delete_pile(p);
            *p = NULL;
            //sleep(60);
            clean_split(s);
            free(s);
            //s = NULL;
			return ;
		}
        //sleep(60);
        clean_split(s);
        free(s);
        ++i;
        //s = NULL;
    }
    //sleep(60);
    if (!check_doublons(*p))
    {
        printf("YES DOUBLONS\n");
	    //sleep(60);
        delete_pile(p);
        *p = NULL;
        return ;
        //sleep(60);
    }
    //sleep(60);
    //if (p)
      //  printf("Problem here\n");
    return ;
}
