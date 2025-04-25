/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:03:49 by akosaca           #+#    #+#             */
/*   Updated: 2024/10/30 13:45:00 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sonelen;
	size_t	stwolen;
	char	*str;
	size_t	i;
	size_t	j;

	sonelen = ft_strlen(s1);
	stwolen = ft_strlen(s2);
	str = malloc((sonelen + stwolen + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
