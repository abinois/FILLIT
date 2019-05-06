/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:18:16 by abinois           #+#    #+#             */
/*   Updated: 2019/04/25 16:44:58 by abinois          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = NULL;
	if (!(str = (char*)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	while ((size + 1) > 0)
		str[size--] = '\0';
	return (str);
}
