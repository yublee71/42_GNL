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
	static char		*str;
	char			*rd_buf;
	char			*result;
	size_t			n;
	static size_t	rd_size;

	if (!str)
		str = ft_strdup("");
	else
	{
		n = ft_charcheck(str, '\n');
		if (n)
		{
			result = ft_substr(str, 0, n);
			str += n;
			return (result);
		}
	}
	rd_size = read(fd, rd_buf, BUFFER_SIZE);
	if (rd_size < 0)
		return (NULL);
	str = ft_strjoin(str, rd_buf);
	get_next_line(fd);
}