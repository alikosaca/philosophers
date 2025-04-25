/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-19 10:43:41 by akosaca           #+#    #+#             */
/*   Updated: 2024-11-19 10:43:41 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(const char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'x')
		count += ft_printf_hex(va_arg(args, int), 1);
	else if (specifier == 'X')
		count += ft_printf_hex(va_arg(args, int), 0);
	else if (specifier == 'p')
		count += ft_printf_ptr(va_arg(args, long));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start (args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += conversion(*format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
