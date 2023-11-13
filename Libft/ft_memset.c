/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:54:18 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 20:10:26 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = (unsigned char)c;
	return (s);
}
/*
#include <stdio.h>
int main(void)
{
	int array[5] = {0, 1, 2, 3};
		ft_memset(array, 20000, 4);
	for (int i = 0; i < 4; i++)
		printf("%i\n", array[i]);
}
*/
