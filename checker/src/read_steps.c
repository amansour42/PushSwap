/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_steps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:06:53 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 15:57:38 by amansour         ###   ########.fr       */
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

void		read_steps(int fd, int *n, t_step **l)
{
	char		*line;
	int			ret;

	ret = 1;
	if (get_next_line(fd, &line) == 0 || !(ret = check_steps(line)))
	{
		if (*line)
			free(line);
		(!ret) ? --(*n) : 0;
		return ;
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
	(!ret) ? --(*n) : 0;
	return ;
}
