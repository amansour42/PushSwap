/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 15:06:26 by amansour          #+#    #+#             */
/*   Updated: 2017/10/20 11:13:42 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define OK			"OK\n"
# define KO			"KO\n"
# define ERROR		"Error\n"
# define ABS(a)     (a < 0) ? -a : a
# include <stdlib.h>
# include "../../libft/libft.h"
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
//int					isempty_list(t_int *list);
t_int				*fill(int ac, char **av);
void				exit_msg(char *str);
int					check_order(t_int *p);
int					check_invorder(t_int *p);
void				rotate(t_int **p);
void				rotate(t_int **p);
void				reverse_rotate(t_int **p);
void				pile_swap(t_int **p);
char				*push(t_int **a, t_int **b, char c);
int					nbr_cases(char **str);
void				affiche(t_int *p);
//only for pushswap
//t_string			*decale_a(t_int **pile, int pivot);
void                treat_b(t_int **pile, t_int **pile2 , int p, char **str);
void    			treat_a(t_int **pile, t_int **b, int p, char **str);
int					last(t_int *pile);
int					length(t_int *pile);
int                 pivot(t_int **a, char c, char **str);
void                short_way(t_int **a, int pos);
void                sort(t_int **pile);
#endif
