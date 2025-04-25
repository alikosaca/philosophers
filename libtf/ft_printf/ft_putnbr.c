/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-19 10:44:13 by akosaca           #+#    #+#             */
/*   Updated: 2024-11-19 10:44:13 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == '\0')
		return (ft_putchar('0'));
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	else if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n < 10)
		count += ft_putchar(n + '0');
	else if (n > 9)
	{
		count += ft_putnbr((n / 10));
		count += ft_putnbr((n % 10));
	}
	return (count);
}
