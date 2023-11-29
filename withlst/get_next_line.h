/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:26:56 by yublee            #+#    #+#             */
/*   Updated: 2023/11/21 21:55:45 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

typedef struct s_buf
{
    char    *buf;
    struct s_buf   *next;
}   t_buf;

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
t_buf	*ft_lstnew(char *buf);
t_buf	*ft_lstlast(t_buf *lst);
void	ft_lstadd_back(t_buf **lst, t_buf *new);
void	ft_lstclear(t_buf **lst);
size_t	ft_lstsize(t_buf *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_charcheck(char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strcat(char *dst, char *src, size_t n);

#endif