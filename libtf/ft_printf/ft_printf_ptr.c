/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 16:02:10 by akosaca           #+#    #+#             */
/*   Updated: 2024-11-24 16:02:10 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(long num)
{
	unsigned long	unum;
	char			*hex;
	int				count;

	unum = num;
	hex = "0123456789abcdef";
	count = 0;
	if (unum < 16)
	{
		count += ft_putchar(hex[unum]);
	}
	else
	{
		count += ft_hex(unum / 16);
		count += ft_putchar(hex[unum % 16]);
	}
	return (count);
}

int	ft_printf_ptr(long num)
{
	int	count;

	count = 0;
	if (num == '\0')
		return (write(1, "(nil)", 5));
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_hex(num);
	return (count);
}
