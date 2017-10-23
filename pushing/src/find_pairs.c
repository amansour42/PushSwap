/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pairs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:12:32 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 19:05:39 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_steps(t_string **l, char c)
{
	t_string *tmp;
	//int		i;

	tmp = *l;
	//i = 0;
	while (tmp)
	{
	//	++i;
		ft_putstr(tmp->str);
		write(1, &c, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	//printf("il es rentre = %c = %d\n", c, i);
	delete_steps(l);
	return ;
}

static void	write_pairs(char *str)
{
	if (str[0] == 's')
		ft_putstr("ss\n");
	else if (str[0] == str[1])
		ft_putstr("rrr\n");
	else
		ft_putstr("rr\n");
	return ;
}

void		find_pairs(t_string **la, t_string **lb)
{
	if (!(*lb))
		print_steps(la, 'a');
	else
	{
		while (*lb && *la)
		{
			if (ft_strcmp((*lb)->str, (*la)->str))
			{
				ft_putstr((*lb)->str);
				ft_putstr("b\n");
			}
			else
			{
				write_pairs((*lb)->str);
				delete_steps_first(la);
			}
			delete_steps_first(lb);
		}
	(*lb) ? print_steps(lb, 'b') : 0;
	(*la) ? print_steps(la, 'a') : 0;
	}
	return ;
}
