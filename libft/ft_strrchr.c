/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:06 by yublee            #+#    #+#             */
/*   Updated: 2023/11/20 17:45:47 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * if s == NULL && (int == 0 || int != 0) : segfault
 * if s == "" && int == 0                 : returns ""
 * if s == "" && int != 0                 : returns NULL
 */

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(s + len) == (char)c)
			return ((char *)s + len);
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}
