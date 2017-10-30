/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:37:40 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 13:38:01 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
# define LIBLIST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct 		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct 		s_step
{
	char 			*str;
	struct s_step	*next;
}					t_step;

//stack_properties
int					length(t_stack *a);
int					min(t_stack *a);
int					max(t_stack *a);
int 				nbr_from_position(t_stack *a, int pos);
int 				pos_int(t_stack *a, int nbr);
//stack
void				add_stack_first(t_stack **pile, int nbr);
void				add_stack_end(t_stack **pile, int nbr);
void 				delete_stack_end(t_stack **pile);
void				delete_stack_first(t_stack **pile);
//steps
void				add_steps_end(t_step **steps, char *str);
void				delete_steps_end(t_step **steps);
void				delete_steps_first(t_step **steps);
void 				display_steps(t_step *steps);
void 				delete_stack(t_stack **stack);
int					steps_length(t_step *steps);
void				delete_steps(t_step **steps);
//tools
char				*ft_strdup(char const *s);
size_t				ft_strlen(char const *s);
char				*ft_strcpy(char *dest, char const *src);
#endif
