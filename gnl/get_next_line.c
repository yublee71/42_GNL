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
	if (rd_size < BUFFER_SIZE)
		result->end = 1;
	return (result);
}

char	*get_next_line(int fd)
{
	t_buf		*mybuffer;
	char		*result;
	static char	*left;

	mybuffer = ft_read(fd);
	if (left) //if there was leftover, we start from there and join buffer
		result = ft_strjoin(result, mybuffer->buf);
	else
		result = ft_strdup(mybuffer->buf); //if there was no leftover, we just duplicate buffer
	while (mybuffer) //if read succeeds
	{
		while (!mybuffer->n && !mybuffer->end && mybuffer) // while !\n and didn't reach the end of file in buf concatenate to result and read again
		{
			mybuffer = ft_read(fd);
			result = ft_strjoin(result, mybuffer->buf);
		}
		//now there is \n or file end in buf
		//concatenate until \n or \0 to result && store leftover in leftover
		ft_strlcat(result, mybuffer->buf, mybuffer->n);
		if (!mybuffer->end)
			left = ft_substr(mybuffer->buf, mybuffer->n + 1, BUFFER_SIZE);
		}
	return (result);
}
