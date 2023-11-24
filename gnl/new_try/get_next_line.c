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
#include <stdio.h> 

void	ft_wipe(char *s, size_t a)
{
	size_t i;

	i = 0;
	while (i < a)
		s[i++] = 0;
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*temp;
	char		*line;
	char		*buffer;
	size_t		n;
	ssize_t		rd_size;

/*
	rd_size = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	printf("rd is \"%zu\"\n", rd_size);
	printf("buffer is \"%s\"\n", buffer);
	return("");
	*/
//	printf("stored is: \"%s\"\n", stored);
	if (fd <= 3 || fd >= 1000 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	if (!stored)
		if (!(stored = ft_strdup("")))
			return (NULL);
	n = ft_charcheck(stored, '\n');
	if (n)
	{
		line = ft_substr(stored, 0, n);
		temp = stored;
		stored = ft_substr(stored, n, ft_strlen(stored)); //needs to free
		free(temp);
		free(buffer);
		return (line);
	}
	else
	{
		while ((rd_size = read(fd, buffer, BUFFER_SIZE)))
		{
			buffer[BUFFER_SIZE] = '\0';
//			printf("buf is \"%s\"\n", buffer);
			temp = stored;
			stored = ft_strjoin(stored, buffer); //needs to free
			free(temp);
			if (ft_charcheck(buffer, '\n'))
			{
				free(buffer);
				return (get_next_line(fd));
			}
		}
//		printf("stored is \"%s\"\n", stored);
		if (*stored)
		{
			line = ft_strdup(stored);
//			printf("line: \"%s\"\n", line);
			free(stored);
			stored = NULL;
			free(buffer);
			return (line);
		}
		free(buffer);
		return (NULL);
	}
}