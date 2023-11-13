/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:50:04 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 20:04:38 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	srclen;

	srclen = ft_strlen(s);
	dest = (char *)malloc(srclen + 1);
	if (dest == NULL)
		return (NULL);
	while (*s)
		*dest++ = *s++;
	*dest = '\0';
	return (dest - srclen);
}
