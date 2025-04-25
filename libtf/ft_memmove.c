/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:58:41 by akosaca           #+#    #+#             */
/*   Updated: 2024/10/23 13:21:29 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char unsigned	*d;
	char unsigned	*s;

	d = (char unsigned *)dst;
	s = (char unsigned *)src;
	if (d < s)
		return (ft_memcpy(d, s, len));
	else if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	return (dst);
}
