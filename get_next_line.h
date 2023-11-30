/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:26:56 by yublee            #+#    #+#             */
/*   Updated: 2023/11/30 15:22:32 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_f_strjoin(char *s1, char *s2);
char	*ft_store_until_newline(char *stored);
char	*ft_free(char *s1, char *s2);
char	*ft_initialize(char *stored, int fd);
size_t	ft_charcheck(char *s, char c);

#endif
