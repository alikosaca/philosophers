/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akosaca <akosaca@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:34:53 by akosaca           #+#    #+#             */
/*   Updated: 2025/03/17 16:08:17 by akosaca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(int fd, char *temporary)
{
	ssize_t	byte_size;
	int		status;
	char	*str;

	byte_size = 1;
	status = 1;
	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (byte_size > 0 && status)
	{
		byte_size = read(fd, str, BUFFER_SIZE);
		if (byte_size < 0)
			return (free(str), free(temporary), NULL);
		str[byte_size] = '\0';
		status = gnl_strchr(str);
		temporary = gnl_strjoin(temporary, str);
		if (!temporary)
			status = 0;
	}
	free(str);
	return (temporary);
}

char	*ft_before_next_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	gnl_strcpy(str, stash, i + 1);
	return (str);
}

char	*ft_new_line(char *stash)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	next_line = malloc(gnl_strlen(stash) - i + 1);
	if (!next_line)
		return (free(stash), NULL);
	i++;
	while (stash[i])
		next_line[j++] = stash[i++];
	next_line[j] = '\0';
	free(stash);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readline(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_before_next_line(buffer);
	buffer = ft_new_line(buffer);
	return (line);
}
