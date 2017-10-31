/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:09:02 by amansour          #+#    #+#             */
/*   Updated: 2017/10/31 16:05:33 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h> //A enlever a la fin
# include "../libft/libft.h"
# include "../liblist/liblist.h"

# define A 			env->a
# define B 			env->b
# define ANBR		(env->a)->nbr
# define BNBR		(env->b)->nbr
# define ANEXT		(env->a)->next
# define BNEXT		(env->b)->next
# define FALSE		0
# define TRUE		1
# define AMAX 		env->a_max
# define AMIN 		env->a_min
# define BMAX 		env->b_max
# define BMIN 		env->b_min
# define ASIZE 		env->a_size
# define BSIZE      env->b_size
# define ASECOND 	ANEXT->nbr
# define BSECOND 	BNEXT->nbr
# define ACOPY  	env->a_copy
# define QUICK 		env->quick_steps
# define NORMAL 	env->normal_steps
# define LNORMAL    env->len_normal
# define LQUICK     env->len_quick
# define MED 		env->med
# define PAD 		env->pad
# define MINT		-2147483648

typedef struct 		s_env
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*a_copy;
	ssize_t			a_size;
	ssize_t			b_size;
	int				a_min;
	int				a_max;
	int				b_max;
	int				b_min;
	int				med;
	int 			pad;
	int				len_normal;
	int				len_quick;
	t_step			*quick_steps;
	t_step			*normal_steps;
}					t_env; 

int					main(int ac, char **av);
t_stack 			*fill(int ac, char **av);
//env.c
int 				make_env(t_env *env);
void				update_env(t_env *env);
void				clean(t_env *env);
//sorting
void				sort(t_env *env);
void				algo_normal(t_env *env);
void				algo_min(t_env *env, t_step **steps);
void				algo_med(t_env *env);
void				algo_max(t_env *env);
void				push_to_a(t_env *env, t_step **steps);
void				test_in_b(t_env *env, t_step **step);
int					define_med(t_env *env);
void				quicksort(int *tableau, int len);
void				min_end_a(t_env *env, t_step **steps);

//stack
void				display_stack(t_stack *pile);
//steps
void 				display_steps(t_step *steps);
//instructions
char    			*rotate(t_env *env, char c);
char    			*reverse_rotate(t_env *env, char c);
char    			*stack_swap(t_env *env, char c);
char    			*push(t_env *env, char c);
//check stack
int 				check_order(t_stack *p);
int 				check_sup(t_stack *p, int nbr);
#endif
