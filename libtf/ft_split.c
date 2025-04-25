/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:13:45 by akosaca           #+#    #+#             */
/*   Updated: 2024/11/05 18:38:40 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	j;
	int		in_word;

	i = 0;
	j = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!in_word)
			{
				in_word = 1;
				j++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (j);
}

static char	*newarr(const char *s, char c, size_t *i)
{
	size_t	len_word;
	size_t	start;
	char	*word;
	size_t	j;

	len_word = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		len_word++;
	}
	word = malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	word[len_word] = '\0';
	start = *i;
	j = 0;
	while (j < len_word)
		word[--len_word] = s[--start];
	return (word);
}

static void	free_memory(char **arrstr, size_t count)
{
	size_t	j;

	j = 0;
	while (j < count)
	{
		free(arrstr[j]);
		j++;
	}
	free(arrstr);
}

char	**ft_split(char const *s, char c)
{
	char	**arrstr;
	size_t	i;
	size_t	j;
	size_t	arrstr_count_word;

	i = 0;
	j = 0;
	arrstr_count_word = count_word(s, c);
	arrstr = malloc(sizeof(char *) * (arrstr_count_word + 1));
	if (!arrstr)
		return (NULL);
	arrstr[arrstr_count_word] = NULL;
	while (j < arrstr_count_word)
	{
		arrstr[j] = newarr(s, c, &i);
		if (!arrstr[j])
		{
			free_memory(arrstr, j);
			return (NULL);
		}
		j++;
	}
	return (arrstr);
}
