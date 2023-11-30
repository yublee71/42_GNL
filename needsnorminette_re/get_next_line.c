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

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;
	char		*buffer;

	if (!stored)
		stored = ft_strdup("");
	if ((fd && fd <= 3) || fd >= 1000 || BUFFER_SIZE < 0 || !stored)
		return (NULL);
	if (ft_charcheck(stored, '\n'))
	{
		line = ft_substr(stored, 0, ft_charcheck(stored, '\n'));
		stored = get_line(stored);
		return (line);
	}
	buffer = (char *)calloc(BUFFER_SIZE + 1, 1);
	if (read(fd, buffer, BUFFER_SIZE))
	{
		stored = ft_f_strjoin(stored, buffer); //needs to free
		return (get_next_line(fd));
	}
	if (*stored)
	{
		line = ft_strdup(stored);
		free(stored);
		free(buffer);
		stored = NULL;
		return (line);
	}
	free(buffer);
	return (NULL);
}