/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:21:57 by abinois           #+#    #+#             */
/*   Updated: 2019/04/12 11:56:23 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy;

	copy = (unsigned char*)b;
	if (len == 0)
		return (b);
	while (len--)
		*copy++ = (unsigned char)c;
	return (b);
}
