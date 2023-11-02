/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:27:11 by yublee            #+#    #+#             */
/*   Updated: 2023/11/02 14:35:10 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char dest[] = "abc";
	char src[] = "def";
	ft_memcpy(dest, src, 2);
	printf("%s\n", dest);
}
