/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:09 by yublee            #+#    #+#             */
/*   Updated: 2023/11/29 16:54:18 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_seperate_by_linebreak(size_t i, char *stored, char *buffer)
{
	char	*line;
	char	*temp;

	temp = stored;
	line = ft_substr(stored, 0, i);
	if (!line)
	{
		free(buffer);
		free(temp);
		return (NULL);
	}
	stored = ft_substr(stored, i, ft_strlen(stored));
	if (!stored)
	{
		free(buffer);
		free(temp);
		return (NULL);
	}
	free(buffer);
	free(temp);
	return (line);
}

#include <stdio.h> //remove it later

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	char		*temp;
	char		*buffer;
	size_t		i;

	if ((fd && fd <= 3) || fd >= 1000 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	if (!stored)
	{
		stored = ft_strdup("");
		if (!stored)
		{
			free(buffer);
			return (NULL);
		}
	}
//	printf("stored is : \"%s\"\n", stored);
	i = ft_charcheck(stored, '\n');
	if (i)
	{
		temp = stored;
		line = ft_substr(stored, 0, i);
		if (!line)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		stored = ft_substr(stored, i, ft_strlen(stored));
		if (!stored)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		free(buffer);
		free(temp);
		return (line);
//		line = ft_seperate_by_linebreak(i, stored, buffer);
//		return (line);
	}
	else
	{
		if (read(fd, buffer, BUFFER_SIZE))
		{
			buffer[BUFFER_SIZE] = '\0';
			temp = stored;
			stored = ft_strjoin(stored, buffer);
			free(temp);
			free(buffer);
			return (get_next_line(fd));
		}
		if (*stored)
		{
			line = ft_strdup(stored);
			free(stored);
			stored = NULL;
			free(buffer);
			return (line);
		}
		free(buffer);
		return (NULL);
	}
}
