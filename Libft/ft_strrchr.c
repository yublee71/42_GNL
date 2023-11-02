/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:49:21 by yublee            #+#    #+#             */
/*   Updated: 2023/11/02 16:18:32 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"
#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	size_t	len;
	
	len = ft_strlen(s);
	while (len >= 0)
	{
		if(*(s + len) == c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_strrchr("abcdddbdddd", '\0'));
}
