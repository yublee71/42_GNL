/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:49:08 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 16:02:32 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*((unsigned char *)s1 + i) && i < n
		&& *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	if (i == n)
		return (0);
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
/*
#include <stdio.h>

int main(void)
{
	char *a = "97abc";
	char *b = "-97abd";
	printf("%i\n", ft_memcmp(a, b, 3));
}*/
