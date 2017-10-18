/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:25:21 by amansour          #+#    #+#             */
/*   Updated: 2017/10/16 15:01:17 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define OK		"OK\n"
# define KO		"KO\n"
# define ERROR	"Error\n"
# define MIN(a, b) (a < b) ? a : b
# define RB     "rb\n"
# define RRB    "rrb\n"
# define SB     "sb\n"

#include <stdlib.h>
#include "../libft/libft.h"
#include <libc.h>

typedef struct		s_opt
{
	char			*s;
	int				n;
}					t_opt;

//Principl
int				main(int ac, char **av);
int				check_entry(int ac, char **av);
int				fill(int ac, char **av, int **p);
int				digit_test(char *str);
void			exit_msg(char *str);
void			sort(int **p, int n);
int				check_order(int *p, int n);
int				check_invorder(int *p, int n);   
//sort
char            *treat_a(int **p, int n, int *a);
t_opt			treat_b(int **p, int n);
t_opt			ft_opnew(int n, char *s);
void			add_to(int **p, int nbr, int *n, char c);
void			rotate(int **p, int n);
void			reverse_rotate(int **p, int n);
void			decale(int **p, int n);
//Affichage instructions
void			to_write(t_opt op, char *s);
void			write_b(t_opt op);
//Second
int				nbr_cases(char **str);
//extra
void			affiche(int *p, int n);
#endif
