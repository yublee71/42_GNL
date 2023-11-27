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
#include <string.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static t_buf	*head;
	t_buf			*next_buf;
	char			*buf;
	char			*line;
	char			*temp;
	size_t			numoflst;
	size_t			n;

	buf = (char *)calloc(BUFFER_SIZE + 1, 1);
	head = ft_lstnew(buf);
	while(read(fd, buf, BUFFER_SIZE))
	{
		printf("%s\n", buf);
		buf[BUFFER_SIZE] = 0;
		n = ft_charcheck(buf, '\n');
		if (n)
		{
			numoflst = ft_lstsize(head);
			line = calloc(numoflst*BUFFER_SIZE + n, 1);
			if (!line)
			{
				ft_lstclear(&head);
				return (NULL);
			}
			while (numoflst--)
			{
				line = strcat(line, head->buf);
				head = head->next;
			}
			ft_lstclear(&head);
			head = ft_lstnew(ft_substr(buf, n, BUFFER_SIZE));
			return (line);
		// iterate from the head to now,
		// join them until \n,
		// free everything
		// store the rest on the head
		// return it
		}
		else
		{
			next_buf = ft_lstnew(buf);
			if (!next_buf)
			{
				ft_lstclear(&head);
				return (NULL);
			}
			ft_lstadd_back(&head, next_buf);
		}
	}
}