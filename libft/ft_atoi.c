/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:59:21 by amansour          #+#    #+#             */
/*   Updated: 2017/05/02 11:03:19 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_blanks(char const *str)
{
	while ((*str >= 7 && *str <= 13) || *str == 32)
	{
		str++;
	}
	return ((char *)str);
}

static int	ft_result(char *str, int sign)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (*str && ft_isdigit(*str) && i++ < 9)
	{
		n = n * 10 + *str - '0';
		str++;
	}
	if (!*str || !ft_isdigit(*str))
		return (sign * n);
	if ((*(str + 1) && ft_isdigit(*(str + 1))) || n > 214748364)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	if ((n == 214748364 && (((*str - '0') <= 7 && sign == 1) ||
		((*str - '0') <= 8 && sign == -1))) || n < 214748364)
		return (sign * (n * 10 + *str - '0'));
	if ((*(str + 1) - '0') > 8 && sign == -1)
		return (0);
	return (-1);
}

int			ft_atoi(char const *s)
{
	int		sign;
	char	*str;

	if (!s)
		return (0);
	sign = 1;
	str = ft_blanks(s);
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	if (str[0] == '+')
		str++;
	while (*str && *str == '0')
	{
		str++;
	}
	return (ft_result(str, sign));
}
