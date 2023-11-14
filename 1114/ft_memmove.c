/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:49:33 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 20:02:06 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dest >= src)
	{
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
		*((unsigned char *)dest + i) = '\0';
	}
	else
	{
		*((unsigned char *)dest + n) = '\0';
		while (--n)
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char src[] = "12345";
	char *dest = src + 1;
//	memmove(dest, src, 3);
	ft_memmove(dest, src, 3);
	printf("%s\n", dest);
}
*/
