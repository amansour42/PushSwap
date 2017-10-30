/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:13:36 by amansour          #+#    #+#             */
/*   Updated: 2017/10/30 13:39:10 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblist.h"

char	*ft_strcpy(char *dest, char const *src)
{
	int i;

	i = 0;
	if (!src)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
