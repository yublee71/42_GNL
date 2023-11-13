/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:49:19 by yublee            #+#    #+#             */
/*   Updated: 2023/11/06 18:49:21 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	int dest[4] = {0, 1, 2, 3};
	int src[4] = {4, 5, 6, 7};
	ft_memcpy(dest, src, 2);
	printf("%i\n", dest[0]);
}*/
