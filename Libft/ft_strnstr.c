/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:51:59 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 16:04:07 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0' || len == 0)
		return ((char *)big);
	while (!big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && j < len)
			j++;
		if (little[j] == '\0' || j == len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_strnstr("abc", "br", 1));
}*/
