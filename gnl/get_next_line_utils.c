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

size_t	ft_strlen(const char *s)
{
	if (!s)
		return (0);
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

static char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	charnum;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	charnum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(charnum + 1);
	if (!result)
		return (NULL);
	*result = '\0';
	result = ft_strcat(result, s1);
	result = ft_strcat(result, s2);
	return (result);
}


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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dst;

	size_src = ft_strlen(src);
	if (!dst && !size)
		return (size_src + size);
	size_dst = ft_strlen(dst);
	if (size_dst >= size)
		return (size_src + size);
	i = 0;
	while (src[i] && i < size - size_dst - 1)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	return (size_src + size_dst);
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
