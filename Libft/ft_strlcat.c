/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:50:41 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 17:12:48 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_src;
	size_t	size_dst;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size_dst >= size)
		return (size_src + size);
	j = 0;
	while (src[j] && j < size - size_dst - 1)
	{
		dest[size_dst + j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (size_src + size_dst);
}
