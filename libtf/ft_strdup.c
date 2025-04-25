/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 21:54:17 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 19:03:35 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	sl;
	char	*scpy;
	size_t	i;

	sl = ft_strlen(s1);
	scpy = malloc((sl + 1) * sizeof(char));
	i = 0;
	if (scpy == NULL)
		return (NULL);
	while (s1[i])
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
