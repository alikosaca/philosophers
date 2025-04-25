/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:01:58 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 19:11:55 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	intcount(int n)
{
	long	i;
	long	a;

	i = 0;
	a = n;
	if (a < 0)
	{
		if (a == -2147483648)
			a += 1;
		a *= -1;
		i++;
	}
	else if (a == 0)
		i++;
	while (a > 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static void	if_int_negative(int *pointer_n, char *str)
{
	if (*pointer_n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		*pointer_n = 147483648;
	}
	if (*pointer_n < 0)
	{
		str[0] = '-';
		*pointer_n *= -1;
	}
}

char	*ft_itoa(int n)
{
	long	intlen;
	char	*str;
	int		*pointer_n;

	pointer_n = &n;
	intlen = intcount(n);
	str = malloc((intlen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		if_int_negative(pointer_n, str);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	str[intlen] = '\0';
	while (intlen > 0 && n > 0)
	{
		str[--intlen] = ((n % 10) + '0');
		n /= 10;
	}
	return (str);
}
