/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:14 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 17:13:32 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;
	size_t	j;
	int		flag;
	char	*result;

	i = 0;
	count = ft_strlen(s1) + 1;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				count--;
			j++;
		}
		i++;
	}
	i = 0;
	l = 0;
	result = malloc(count);
	if (!result)
		return (NULL);
	while (s1[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			*result++ = s1[i];
		i++;
	}
	*result = '\0';
	return (result - count);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n",ft_strtrim("abc", "b"));
}*/
