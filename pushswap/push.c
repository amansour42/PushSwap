/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:33:03 by amansour          #+#    #+#             */
/*   Updated: 2017/10/13 18:08:14 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		main(int ac, char **av)
{
	t_pile	*pile;
	int		i;

	pile = NULL;
	i = 0;
	while (++i < ac)
	{
		if (!digit_test(av[i]))
			exit_msg(ERROR);
		fill_pile(&pile, ft_strsplit(av[i],' '));
		if (!pile)
			return (0);
	}
	return (0);
}
