/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:49:44 by yublee            #+#    #+#             */
/*   Updated: 2023/11/06 18:49:46 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] && s[i] != c)
		count++;
	i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_copytil(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	result = malloc(len + 1);
	while (i < len)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	wordcount;
	size_t	i;
	char	**result;

	wordcount = ft_wordcount(s, c);
	i = 0;
	result = malloc(wordcount * sizeof(char *));
	if (!result || wordcount == 0)
		return (NULL);
	while (*s && i < wordcount)
	{
		if (*s == c)
			s++;
		else
		{
			result[i++] = ft_copytil(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
    char **result;
    result = ft_split("abc", 'b');
    printf("%s", result[0]);
}
*/
