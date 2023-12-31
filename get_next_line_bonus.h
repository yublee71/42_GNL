/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:26:56 by yublee            #+#    #+#             */
/*   Updated: 2023/11/30 17:49:22 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define FDMAX 1024

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_f_strjoin(char *s1, char *s2);
char	*ft_store_until_newline(char *stored);
void	*ft_free(char **s1, char *s2);
char	*ft_initialize(char *stored, int fd);
size_t	ft_charcheck(char *s, char c);
char	*ft_malloc(size_t n);

#endif
