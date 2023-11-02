/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:28:57 by yublee            #+#    #+#             */
/*   Updated: 2023/11/01 19:42:56 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

str_len

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_src;
	size_t	size_dest;

	size_dest = ft_len(dest);
	size_src = ft_len(src);
	if (size_dest >= size)
		return (size + size_src);
	j = 0;
	while (src[j] && j < size - size_dest - 1)
	{
		dest[size_dest+j] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (size_src + size_dest);
}	
}
