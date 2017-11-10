/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:21:08 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 12:12:38 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	main(int ac, char **av)
{
	t_env *env;

	if (ac < 2)
		return (0);
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	if (!(A = fill(ac, av)))
	{
		write(2, "Error\n", 6);
		free(env);
		return (0);
	}
	if (check_order(A))
		return (0);
	sort(env);
	if (NORMAL && steps_length(NORMAL) < steps_length(QUICK))
		display_steps(NORMAL);
	else
		display_steps(QUICK);
	clean(env);
	free(env);
	return (0);
}
