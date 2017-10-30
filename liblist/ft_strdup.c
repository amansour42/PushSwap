/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:14:41 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 13:39:25 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

char	*ft_strdup(char const *s)
{
	char *str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * ft_strlen(s));
	if (str)
		ft_strcpy(str, s);
	return (str);
}
