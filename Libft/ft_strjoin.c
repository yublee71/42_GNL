/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:50:26 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 17:12:39 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcat(const char *dest, const char *src)
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

	charnum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(charnum + 1);
	if (!result)
		return (NULL);
	*result = '\0';
	result = ft_strcat(result, s1);
	result = ft_strcat(result, s2);
	return (result);
}
