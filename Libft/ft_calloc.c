/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:44:39 by yublee            #+#    #+#             */
/*   Updated: 2023/11/13 16:08:06 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	int		i;
	long	i_com;

	i = nmemb * size;
	i_com = nmemb * size;
	if (i != i_com)
		return (NULL);
	array = (void *)malloc(i);
	if (!array)
		return (NULL);
	while (i--)
		*((unsigned char *)array++) = 0;
	return (array);
}
/*
int	main(void)
{
	ft_calloc(10, 2);
}*/
