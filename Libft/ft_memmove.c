/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:53:09 by yublee            #+#    #+#             */
/*   Updated: 2023/11/02 15:30:51 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char temp[2];

	i = 0;
	if(n > 0)
		temp[0] = *((unsigned char *)src + i);
	while (i < n)
	{
		temp[1] = *((unsigned char *)src + i + 1);
		*((unsigned char *)dest + i) = temp[0];
		temp[0] = temp[1];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char src[] = "12345";
	char *dest = src + 1;
//	memmove(dest, src, 3);
	ft_memmove(dest, src, 3);
	printf("%s\n", dest);
}
