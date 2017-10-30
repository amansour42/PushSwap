/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 10:07:28 by amansour          #+#    #+#             */
/*   Updated: 2017/10/19 12:03:53 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		**ft_tab(char const *str, size_t nb, char c, char **tab)
{
	size_t j;
	size_t i;

	j = 0;
	while (j < (nb - 1))
	{
		while (*str == c)
		{
			str++;
		}
		i = 0;
		while (str[i] && str[i] != c)
		{
			i++;
		}
		if (!(tab[j] = ft_strsub(str, 0, i)))
			return (NULL);
		str += i;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	nb;
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	nb = 1;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i])
			nb++;
		while (s[i] && s[i] != c)
		{
			i++;
		}
	}
	if ((tab = (char**)malloc(sizeof(char*) * nb)))
		return (ft_tab(s, nb, c, tab));
	return (NULL);
}