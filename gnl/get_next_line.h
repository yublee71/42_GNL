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
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_buf
{
	char	buf[BUFFER_SIZE + 1];
	int		n;
	int		end;
} t_buf;

char *get_next_line(int fd);
t_buf	*ft_read(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_charcheck(char *s, char c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

#endif
