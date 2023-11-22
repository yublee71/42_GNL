/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:26 by yublee            #+#    #+#             */
/*   Updated: 2023/11/16 18:41:12 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * The value returned is that of the converted letter, or c if theconversion was not possible.
 * If c is neither an unsigned char value nor EOF, the behavior of these functions is undefined.
 * If the argument c is of type char, it must be cast to unsigned char.
 * This is necessary because char may be the equivalent of signed char, 
 * in which case a byte where the top bit is set would be sign extended when converting to int,
 * yielding a value that is outside the range of unsigned char.
 * The details of what characters belong to which class depend on the locale.
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}