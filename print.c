/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:11:13 by abinois           #+#    #+#             */
/*   Updated: 2019/05/03 17:37:32 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>

int		ft_exit(int fd)
{
	if (fd != -1)
		close(fd);
	ft_putstr("error\n");
	return (-1);
}

int		ft_usage(char *usage)
{
	ft_display_file(usage);
	ft_putstr("\nA few examples of ");
	ft_putstrclr("VALID ", "green");
	ft_putstr("Tetriminos:\n\n");
	ft_putstrclr(".... .... #### ....\n..## .... .... ##..\n", "green");
	ft_putstrclr("...# ..## .... .##.\n...# ..## .... ....\n", "green");
	ft_putstr("\nA few examples of ");
	ft_putstrclr("INVALID ", "red");
	ft_putstr("Tetriminos:\n\n");
	ft_putstrclr("#### ...# ##... ....\n...# ..#. ##... ....\n", "red");
	ft_putstrclr(".... .#.. ..... ....\n.... #... ..... ....\n", "red");
	return (-1);
}
