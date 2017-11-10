/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:06:53 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 10:59:15 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static int	check_steps(char *s)
{
	if (!ft_strcmp(s, "ra") || !ft_strcmp(s, "rra") || !ft_strcmp(s, "sa")
			|| !ft_strcmp(s, "pa"))
		return (1);
	if (!ft_strcmp(s, "rb") || !ft_strcmp(s, "rrb") || !ft_strcmp(s, "sb")
			|| !ft_strcmp(s, "pb"))
		return (1);
	if (!ft_strcmp(s, "rr") || !ft_strcmp(s, "rrr") || !ft_strcmp(s, "ss"))
		return (1);
	return (0);
}

int			read_steps(int fd, t_step **l)
{
	char		*line;
	int			ret;

	if (get_next_line(fd, &line) == 0)
		return (1);
	if (!(ret = check_steps(line)))
	{
		free(line);
		return (0);
	}
	add_steps_end(l, line);
	free(line);
	line = NULL;
	while (get_next_line(fd, &line) == 1 && (ret = check_steps(line)))
	{
		add_steps_end(l, line);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	return (ret);
}
