/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-22 15:43:08 by akosaca           #+#    #+#             */
/*   Updated: 2024-11-22 15:43:08 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_unsigned(unsigned int num)
{
	char	arr[11];
	int		i;
	int		count;

	i = 0;
	if (num == 0)
		return (ft_putchar('0'));
	while (num > 0)
	{
		arr[i++] = num % 10 + '0';
		num /= 10;
	}
	count = i;
	while (i > 0)
		ft_putchar(arr[--i]);
	return (count);
}
