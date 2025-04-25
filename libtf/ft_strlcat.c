/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:34:13 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 14:30:34 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;
	size_t			dcount;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	dcount = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize <= dcount)
		return (dstsize + ft_strlen(src));
	while (s[i] != '\0' && (dcount + i) < dstsize - 1)
	{
		d[dcount + i] = s[i];
		i++;
	}
	d[dcount + i] = '\0';
	return (dcount + ft_strlen(src));
}
