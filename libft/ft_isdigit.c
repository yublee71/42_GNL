/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:45:19 by yublee            #+#    #+#             */
/*   Updated: 2023/11/16 18:38:21 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * This function check whether c, which must have the value of an unsigned char or EOF, falls into a certain character class according to the specified locale.
 * The standards require that the argument c for this functions is either EOF or a value that is representable in the type unsigned char.
 * If the argument c is of type char, it must be cast to unsigned char.
 * This is necessary because char may be the equivalent of signed char, 
 * in which case a byte where the top bit is set would be sign extended when converting to int,
 * yielding a value that is outside the range of unsigned char.
 * The details of what characters belong to which class depend on the locale.
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}