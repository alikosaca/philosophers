/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:41:19 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 16:18:34 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	gnl_strchr(const char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (0);
		s++;
	}
	return (1);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	new_str = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[++j])
		new_str[i + j] = s2[j];
	new_str[i + j] = '\0';
	free(s1);
	return (new_str);
}

char	*gnl_strcpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
