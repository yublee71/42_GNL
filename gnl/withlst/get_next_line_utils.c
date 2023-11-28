/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:25:07 by yublee            #+#    #+#             */
/*   Updated: 2023/11/21 21:57:50 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_charcheck(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_buf	*ft_lstnew(char *buf)
{
	t_buf	*new_node;

	new_node = (t_buf *)malloc(sizeof(t_buf));
	if (!new_node)
		return (NULL);
	new_node->buf = ft_strdup(buf);
	if(!new_node->buf)
		return (NULL);
	new_node->next = NULL;
	return (new_node);
}

t_buf	*ft_lstlast(t_buf *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_buf **lst, t_buf *new)
{
	t_buf	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

void	ft_lstclear(t_buf **lst)
{
	t_buf	*current;
	t_buf	*next;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		current->buf = NULL;
		free(current);
		current = next;
	}
	*lst = NULL;
}

size_t	ft_lstsize(t_buf *lst)
{
	size_t	count;
	t_buf	*temp;

	if (!lst)
		return (0);
	count = 1;
	temp = lst->next;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			strlen;
	char			*substring;

	if (!s)
		return (NULL);
	i = start;
	j = 0;
	strlen = ft_strlen(s);
	if (!strlen || !len || start > strlen)
	{
		substring = ft_strdup("");
		return (substring);
	}
	if (len < strlen - start)
		substring = (char *)malloc(len + 1);
	else
		substring = (char *)malloc(strlen - start + 1);
	if (!substring)
		return (NULL);
	while (s[i] && j < len)
		substring[j++] = s[i++];
	substring[j] = '\0';
	return (substring);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	srclen;

	srclen = ft_strlen(s);
	dest = (char *)malloc(srclen + 1);
	if (dest == NULL)
		return (NULL);
	while (*s)
		*dest++ = *s++;
	*dest = '\0';
	return (dest - srclen);
}

char	*ft_strcat(char *dst, char *src, size_t n)
{
	size_t	i;
	size_t	j;
	i = 0;
	j = 0;

	while (dst[i])
		i++;
	while (src[j] && n--)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}