/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:27:31 by akosaca           #+#    #+#             */
/*   Updated: 2024/10/18 01:00:05 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*csb;
	unsigned char	*csi;
	int				i;

	csb = (unsigned char *)s1;
	csi = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (csb[i] != csi[i])
			return (csb[i] - csi[i]);
		n--;
		i++;
	}
	return (0);
}
