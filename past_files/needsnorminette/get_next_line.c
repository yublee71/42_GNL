/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:09 by yublee            #+#    #+#             */
/*   Updated: 2023/11/29 21:23:54 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //remove it later

char *ft_getline(char *stored)
{
	char	*line;
	char	*temp;
	size_t	i;

	if (!stored)
	{
		stored = ft_strdup("");
		if (!stored)
			return (NULL);
	}
	i = ft_charcheck(stored, '\n');
	temp = stored;
	line = ft_substr(stored, 0, i);//return until /n
	stored = ft_substr(stored, i, ft_strlen(stored)); //store the rest stored
	if (!stored || !line)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stored; //needs freeing
	char		*buffer; //needs freeing
	char		*line;

	if ((fd && fd <= 3) || fd >= 1000 || BUFFER_SIZE < 0)
		return (NULL);
	if (ft_charcheck(stored, '\n'))
		return (ft_getline(stored)); //takes care of stored and also free if there is error
	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE))
	{
		stored = ft_f_strjoin(stored, buffer);
		free(buffer);
		if (!stored)
			return (NULL);
		return (ft_getline(stored));
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
