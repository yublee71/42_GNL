/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:20 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 17:13:40 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	size_t			strlen;
	char			*substring;

	i = start;
	j = 0;
	strlen = ft_strlen(s);
	if (strlen >= start)
	{
		if (strlen - start > len)
		{
			substring = (char *)malloc(len + 1);
			if (!substring)
				return (NULL);
		}
		else
		{
			substring = (char *)malloc(strlen - start + 1);
			if (!substring)
				return (NULL);
		}
		while (s[i] && j < len)
			substring[j++] = s[i++];
		substring[j] = '\0';
		return (substring);
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_substr("abc", 1, 2));
}
*/
