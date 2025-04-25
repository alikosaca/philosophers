/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:47:06 by akosaca           #+#    #+#             */
/*   Updated: 2024/10/30 13:45:22 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			slen;

	slen = ft_strlen(s);
	while (slen > 0)
	{
		if (s[slen] == (char)c)
			return ((char *)(s + slen));
		slen--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
