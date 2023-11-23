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

char	*get_next_line(int fd)
{
	static char		*stored;
	char			*result;
	char			rd_buf[BUFFER_SIZE + 1] = {0};
	size_t			n;
	static ssize_t			rd_size;

//	printf("stored is: \"%s\"\n", stored);
	if (!stored)
	{
		if (!(stored = ft_strdup("")))
			return (NULL);
	}
	else
	{
		n = ft_charcheck(stored, '\n');
		if (n)
		{
			if(!(result = ft_substr(stored, 0, n)))
				return (NULL);
			stored += n;
			if (!*stored)
				stored = NULL; 
			return (result);
		}
	}
	rd_size = read(fd, rd_buf, BUFFER_SIZE);
//	printf("rd_size is: %ld\n", rd_size);
	rd_buf[BUFFER_SIZE] = 0;
//	printf("buf is \"%s\"\n", rd_buf);
	if (rd_size < 0)
		return (NULL);
	else if (rd_size == 0)
	{
		result = ft_strdup(stored);
		stored = NULL;
		return (result);
	}
	else
	{
		if(!(stored = ft_strjoin(stored, rd_buf)))
			return (NULL);
		return(get_next_line(fd));
	}
}