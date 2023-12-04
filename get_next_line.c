/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:09 by yublee            #+#    #+#             */
/*   Updated: 2023/12/04 22:28:48 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store_until_newline(char *stored)
{
	char	*temp;
	size_t	i;

	i = ft_charcheck(stored, '\n');
	temp = stored;
	stored = ft_substr(stored, i, ft_strlen(stored));
	free(temp);
	return (stored);
}

void	*ft_free(char **s1, char *s2)
{
	free(*s1);
	free(s2);
	*s1 = NULL;
	return (NULL);
}

char	*ft_initialize(char *stored, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stored)
	{
		stored = ft_strdup("");
		if (!stored)
			return (NULL);
	}
	return (stored);
}

size_t	ft_charcheck(char *s, char c)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	char		*buffer;
	ssize_t		rd_size;

	stored = ft_initialize(stored, fd);
	line = ft_substr(stored, 0, ft_charcheck(stored, '\n'));
	if (ft_charcheck(stored, '\n'))
		stored = ft_store_until_newline(stored);
	else if (stored)
	{
		buffer = ft_malloc(BUFFER_SIZE + 1);
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size < 0)
			return (ft_free(&stored, buffer));
		stored = ft_f_strjoin(stored, buffer);
		if (rd_size > 0)
			return (get_next_line(fd));
		if (*stored)
			line = ft_strdup(stored);
		stored = ft_free(&stored, buffer);
	}
	return (line);
}
