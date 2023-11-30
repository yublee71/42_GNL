/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:09 by yublee            #+#    #+#             */
/*   Updated: 2023/11/21 22:32:44 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *stored)
{
	char	*temp;
	size_t	i;

	i = ft_charcheck(stored, '\n');
	temp = stored;
	stored = ft_substr(stored, i, ft_strlen(stored)); //needs to free
	free(temp);
	return (stored);
}

char	*ft_free(char *s1, char* s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

char*	ft_initialize(char *stored, int fd)
{
	if (!stored)
	{
		stored = ft_strdup("");
		if (!stored)
		return (NULL);
	}
	if ((fd && fd < 3) || fd >= 1000 || BUFFER_SIZE < 0)
	{
		free(stored);
		return (NULL);
	}	
	return (stored);
}
/*
char	*ft_read(int fd, char *stored)
{
	char		*buffer;

	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE))
	{
		stored = ft_f_strjoin(stored, buffer);
		free(buffer);
		return (stored);
	}
	free(buffer);
	return (NULL);
}
*/

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	char		*buffer;

	stored = ft_initialize(stored, fd);
	line = ft_substr(stored, 0, ft_charcheck(stored, '\n'));
	if (ft_charcheck(stored, '\n'))
		stored = get_line(stored);
	else if (stored)
	{ 
		buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
		if (read(fd, buffer, BUFFER_SIZE))
		{
			stored = ft_f_strjoin(stored, buffer);
			return (get_next_line(fd));
		}
		if (*stored)
			line = ft_strdup(stored);
		stored = ft_free(stored, buffer);
	}
	return (line);
}