/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:25:21 by amansour          #+#    #+#             */
/*   Updated: 2017/10/15 16:33:54 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define OK		"OK\n"
# define KO		"KO\n"
# define ERROR	"Error\n"
# define MIN(a, b) (a < b) ? a : b

#include <stdlib.h>
#include "../libft/libft.h"
#include <libc.h>

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*p;
}					t_pile;

//Principl
int				main(int ac, char **av);
int				check_entry(int ac, char **av);
int				fill(int ac, char **av, int **p);
int				digit_test(char *str);
void			exit_msg(char *str);
void			sort(int **p, int n);
int				check_order(int *p, int n);
//sort
int				treat_a(int **p, int n);
void			treat_b(int **p, int n);
void			add_to(int **p, int nbr, int *n, char c);
void			rotate(int **p, int n, char c);
void			reverse_rotate(int **p, int n, char c);
void			decale(int **p, int n);
//Second
int				nbr_cases(char **str);
//extra
void			affiche(int *p, int n);
#endif
