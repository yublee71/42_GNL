/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:09 by yublee            #+#    #+#             */
/*   Updated: 2023/11/30 16:56:38 by yublee           ###   ########.fr       */
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

char	*ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
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
	static t_strings	*str;
	char		*buffer;
	ssize_t		rd_size;

	str->stored = ft_initialize(str->stored, fd);
	str->line = ft_substr(str->stored, 0, ft_charcheck(str->stored, '\n'));
	if (ft_charcheck(str->stored, '\n'))
		str->stored = ft_store_until_newline(str->stored);
	else if (str->stored)
	{
		buffer = ft_malloc(BUFFER_SIZE + 1);
		rd_size = read(fd, buffer, BUFFER_SIZE);
		if (rd_size < 0)
		{
			str->stored = ft_free(str->stored, buffer);
			return (str->stored);
		}
		str->stored = ft_f_strjoin(str->stored, buffer);
		if (rd_size > 0)
			return (get_next_line(fd));
		if (*str->stored)
			str->line = ft_strdup(str->stored);
		str->stored = ft_free(str->stored, buffer);
	}
	return (str->line);
}
