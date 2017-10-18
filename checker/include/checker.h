/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:08:22 by amansour          #+#    #+#             */
/*   Updated: 2017/10/18 19:34:54 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define OK			"OK\n"
# define KO			"KO\n"
# define ERROR		"Error\n"
# include <stdlib.h>
# include "../libft/libft.h"
# include <libc.h>

typedef struct		s_int
{
	int				nbr;
	struct s_int	*next;
}					t_int;

typedef struct		s_string
{
	char			*str;
	struct s_string	*next;
}					t_string;

int					main(int ac, char **av);
void				add_end_pile(t_int **pile, int nbr);
void				add_end_steps(t_string **steps, char *step);
void				add_first_pile(t_int **pile, int nbr);
void				delete_pile_end(t_int **pile);
void				delete_steps_end(t_string **steps);
void				delete_pile_first(t_int **pile);
void				delete_steps_first(t_string **steps);
void				delete_pile(t_int **pile);
void				delete_steps(t_string **steps);
void				clean_lists(t_int **p, t_string **steps);
int					isempty_list(t_int *list);
t_int				*fill(int ac, char **av, int *n);
int					digit_test(char *str);
void				exit_msg(char *str);
t_string			*read_steps(int fd, int *n);
int					check_order(t_int *p);
int					apply(t_int **pile, t_string *l);
void				rotate(t_int **p);
void				reverse_rotate(t_int **p);
void				pile_swap(t_int **p);
int					nbr_cases(char **str);
void				affiche(t_int *p);
#endif
