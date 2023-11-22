/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:33 by yublee            #+#    #+#             */
/*   Updated: 2023/11/16 18:41:17 by yublee           ###   ########.fr       */
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

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}