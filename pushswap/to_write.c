/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 14:23:20 by amansour          #+#    #+#             */
/*   Updated: 2017/10/16 15:03:52 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void write_op(t_opt op, int p)
{
	char *s;

	s = (!ft_strcmp(op.s, SB)) ? NULL : RB;
	op.n += p;
	while ((op.n)--)
	{
		ft_putstr(op.s);
		(s) ? ft_putstr(s) : 0;
	}
	return ;

}
void    to_write(t_opt op, char *s)
{
	if (!op.n)
	{
		ft_putstr(s);
		return ;
	}
	if (!ft_strcmp(op.s, RB))
	{
		if (s[0] == 'r')
			ft_putstr("rr\n");
		else
			ft_putstr("rb\nsa\n");
		return ;
	}
	if (s[0] == 's')
	{
		ft_putstr("ss\n");
		ft_putstr(RB);
	}
	else
	{
		ft_putstr(SB);
		ft_putstr("rr\n");
	}
	write_op(op, -1);
	op.s = RRB;
	write_op(op, 0);
	return ;
}


void    write_b(t_opt op)
{
	int i;

	if (!op.s)
		return ;
	i = op.n;
	if (op.s == RB)
	{
		ft_putstr(RB);
		return ;
	}
	write_op(op, 0);
	op.s = RRB;
	write_op(op, 0);
	return ;
}
