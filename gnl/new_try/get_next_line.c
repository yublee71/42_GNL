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
	char		buffer[BUFFER_SIZE + 1];
	size_t		n;
//	ssize_t		rd_size;

/*
	rd_size = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = 0;
	printf("rd is \"%zu\"\n", rd_size);
	printf("buffer is \"%s\"\n", buffer);
	return("");
	*/
//	printf("stored is: \"%s\"\n", stored);
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
		return (line);
	}
	else
	{
		while (read(fd, buffer, BUFFER_SIZE))
		{
			buffer[BUFFER_SIZE] = '\0';
//			printf("buf is \"%s\"\n", buffer);
			temp = stored;
			stored = ft_strjoin(stored, buffer); //needs to free
			free(temp);
			n = ft_charcheck(stored, '\n');
			if (n)
			{
				line = ft_substr(stored, 0, n);
				temp = stored;
				stored = ft_substr(stored, n, ft_strlen(stored)); //needs to free
				free(temp);
				return (line);
			}
			ft_wipe(buffer, BUFFER_SIZE + 1);
		}
		if (stored)
		{
			line = ft_strdup(stored);
			stored = NULL;
			free(stored);
			return(line);
		}
		return (NULL);
	}
}