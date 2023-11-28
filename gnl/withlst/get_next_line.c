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

char	*get_next_line(int fd)
{
	static t_buf	*head;
	t_buf			*next_buf;
	t_buf			*temp_buf;
	char			*buf;
	char			*line;
	size_t			numoflst;
	size_t			n;

	buf = (char *)calloc(BUFFER_SIZE + 1, 1);
	if(!head)
		head = ()
	temp_buf = head;
	while(read(fd, buf, BUFFER_SIZE))
	{
//		printf("%s\n", buf);
		n = ft_charcheck(buf, '\n');
		if (n)
		{
			numoflst = ft_lstsize(head) + 1;
	//		printf("numoflst is : %ld\n", numoflst);
	//		printf("n is : %ld\n", n);
			line = (char *)calloc(numoflst*BUFFER_SIZE + n, 1);
			if (!line)
			{
				ft_lstclear(&head);
				return (NULL);
			}
			while (numoflst-- && temp_buf)
			{
				printf("here buf : %s\n", temp_buf->buf);
				line = ft_strcat(line, temp_buf->buf, BUFFER_SIZE);
				printf("here line :%s\n", line);
				temp_buf = temp_buf->next;
			}
			line = ft_strcat(line, buf, n);
			ft_lstclear(&head);
			head = ft_lstnew(ft_substr(buf, n, BUFFER_SIZE + 1));
			return (line);
		// iterate from the head to now,
		// join them until \n,
		// free everything
		// store the rest on the head
		// return it
		}
		else
		{
			printf("buf is this: \"%s\"\n", buf);
			next_buf = ft_lstnew(buf);
			if (!next_buf)
			{
				ft_lstclear(&head);
				return (NULL);
			}
			ft_lstadd_back(&head, next_buf);
		}
	}
	return(NULL);
}