/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 14:16:09 by akosaca           #+#    #+#             */
/*   Updated: 2024-11-24 14:16:09 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(int num, int isx)
{
	unsigned int	unum;
	char			*hexs;
	char			*hexb;
	int				count;

	unum = (unsigned int)num;
	hexs = "0123456789abcdef";
	hexb = "0123456789ABCDEF";
	count = 0;
	if (unum < 16)
	{
		if (isx == 1)
			count += ft_putchar(hexs[unum]);
		else
			count += ft_putchar(hexb[unum]);
	}
	else
	{
		count += ft_printf_hex(unum / 16, isx);
		if (isx == 1)
			count += ft_putchar(hexs[unum % 16]);
		else
			count += ft_putchar(hexb[unum % 16]);
	}
	return (count);
}
