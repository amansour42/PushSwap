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
#include <stdio.h>

/*static char	*ft_blanks(char const *str)
{
	while ((*str >= 7 && *str <= 13) || *str == 32)
	{
		str++;
	}
	return ((char *)str);
}*/

static int	ft_result(char const *str, int sign, int start)
{
	int long    n;
	int         i;

	i = 0;
	n = 0;
	while (str[start] && ft_isdigit(str[start]) && i++ < 9)
	{
		n = n * 10 + str[start] - '0';
		start++;
	}
	if (!str[start] || !ft_isdigit(str[start]))
    {
        //printf("1\n");
        //while(1)
        return (sign * n);
    }
	/*if ((str[start + 1] && ft_isdigit(str[start + 1])) || n > 214748364)
	{
        printf("2\n");
		if (sign == 1)
			return (-1);
		return (0);
	}*/
	/*if ((n == 214748364 && (((str[start] - '0') <= 7 && sign == 1) ||
		((str[start] - '0') <= 8 && sign == -1))) || n < 214748364)
       
    {
        printf("3\n");
        while (1)
            return (sign * (n * 10 + str[start] - '0'));
    }
	if ((str[start + 1] - '0') > 8 && sign == -1)
    {   
        printf("4\n");
        while (1)
        return (0);
    }*/
    //while (1)
	return (-1);
}

int			ft_atoi(char const *str)
{
    int		sign;
    //char	*str;
    int     i;

	if (!str)
		return (0);
	sign = 1;
    i = 0;
	//str = ft_blanks(s);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] == '0')
		i++;
    return (ft_result(str, sign, i));
}
