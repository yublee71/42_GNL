/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:02:38 by yublee            #+#    #+#             */
/*   Updated: 2023/11/06 17:26:52 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return (c >= '0' && c <= '9' || c >= 'a' && c <= 'z'
		|| c >= 'A' && c <= 'Z');
}
