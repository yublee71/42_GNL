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

t_buf	*ft_read(int fd)
{
	ssize_t	rd_size;
	t_buf	*result;

	result = (t_buf *)malloc(sizeof(t_buf));
	if (!result)
		return (NULL);
	rd_size = read(fd, result->buf, BUFFER_SIZE);
	if (rd_size <= 0)
		return (NULL);
	result->buf[rd_size] = 0;
	result->n = ft_charcheck(result->buf, '\n');
	result->end = 0;
	if (rd_size < BUFFER_SIZE)
		result->end = 1;
	return (result);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	t_buf		*mybuffer;
	char		*result;
	static char	*left;
	size_t		n;

	if (!left)
		left = ft_strdup(""); //if there was no leftover, we just create empty string
	else //if there was leftover, we start from there
	{
		n = ft_charcheck(left, '\n');
		if (n)
		{
			result = ft_substr(left, 0, n);
			left = ft_substr(left, n, BUFFER_SIZE);
			return (result);
		}
	}
	mybuffer = ft_read(fd);
	if(!mybuffer)
		return (left);
	result = ft_strjoin(left, mybuffer->buf);
	//printf("result is \"%s\"\n", result);
	n = ft_charcheck(result, '\n');
	if (n)
	{
		left = ft_substr(result, n, 200);
		result = ft_substr(result, 0, n);
		//printf("left is \"%s\"\n", left);
	}
	return (result);
	/*
	printf("result precheck: \"%s\"\n",result);
	while (mybuffer && !mybuffer->n && !mybuffer->end) // while !\n and didn't reach the end of file in buf concatenate to result and read again
	{
		result = ft_strjoin(result, mybuffer->buf);
		mybuffer = ft_read(fd);
	}
	//now there is \n or file end in buf
	//concatenate until \n or \0 to result && store leftover in leftover
    result = ft_substr(mybuffer->buf, 0, mybuffer->n);
	if (!mybuffer->end)
		left = ft_substr(mybuffer->buf, mybuffer->n, BUFFER_SIZE); 
	return (result);
	*/
}