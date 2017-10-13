/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 16:25:21 by amansour          #+#    #+#             */
/*   Updated: 2017/10/13 18:08:03 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# define OK		"OK\n"
# define KO		"KO\n"
# define ERROR	"Error\n"

#include <stdlib.h>

typedef struct	s_pile
{
	int		nb;
	s_pile	*p;
}				t_pile;
//Principl
int				main(int ac, char **av);
void			fill_pile(t_pile **pile, char **str);
int				digit_test(char *str);
void			exit_msg(char *str);
//Second
char			**ft_strsplit(char const *s, char c);
int				ft_atoi(char *str);
#endif
