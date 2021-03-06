/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:08:22 by amansour          #+#    #+#             */
/*   Updated: 2017/11/10 11:06:34 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define OK			"OK\n"
# define KO			"KO\n"
# define ERROR		"Error\n"
# include <stdlib.h>
# include "../libft/libft.h"
# include "../liblist/liblist.h"

int					main(int ac, char **av);
t_stack				*fill(int ac, char **av);
int					read_steps(int fd, t_step **l);
int					check_order(t_stack *p);
int					apply(t_stack **pile, t_step **l);
void				rotate(t_stack **p);
void				reverse_rotate(t_stack **p);
void				stack_swap(t_stack **p);
#endif
