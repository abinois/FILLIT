/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:28:45 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/03 14:14:50 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"

int		check_hashz(char *s, int i, int nb_hash)
{
	int		conex;
	int		len;

	conex = 0;
	len = 21;
	while (nb_hash > 0 && --len > 0)
	{
		if (s[i] == '#')
		{
			if (len > 1)
				if (s[i - 1] == '#')
					conex++;
			if (len > 5)
				if (s[i - 5] == '#')
					conex++;
			if (len < 16)
				if (s[i + 5] == '#')
					conex++;
			if (s[i + 1] == '#')
				conex++;
			nb_hash--;
		}
		i--;
	}
	return ((conex < 6) ? -1 : 0);
}

int		check_cr(char *s, int i, int *line, int *hash)
{
	(*line)++;
	if (*line == 4 && (*hash != 4 || (s[i + 1] != '\0' && s[i + 1] != '\n')))
		return (-1);
	else if (*line == 4)
	{
		if (check_hashz(s, i, *hash) == -1)
			return (-1);
		*hash = 0;
	}
	return (0);
}

int		new_block(char *s, int i, int *block, int *line)
{
	if (s[i - 1] == '\n')
	{
		(*block)++;
		if (*line != 5 || (s[i + 1] != '#' && s[i + 1] != '.'))
			return (-1);
		*line = 0;
	}
	return (0);
}

int		browse_str(char *str, int block, int hash)
{
	int		i;
	int		j;
	int		line;

	i = -1;
	j = 1;
	line = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			hash++;
		else if (str[i] == '\n')
		{
			if (str[i - 1] != '\n' && j != 5)
				return (-1);
			j = 0;
			if ((check_cr(str, i, &line, &hash) == -1)
					|| (new_block(str, i, &block, &line) == -1))
				return (-1);
		}
		else if (str[i] != '.')
			return (-1);
		j++;
	}
	return ((line == 4) ? block : -1);
}

int		check_input(char *input)
{
	int		fd;
	char	buf[BUFF_SIZE_FILLIT + 1];
	int		ret;
	int		block;
	int		hash;

	block = 1;
	hash = 0;
	if (!(fd = open(input, O_RDONLY)))
		return (-1);
	if (!(ret = read(fd, buf, BUFF_SIZE_FILLIT)))
		return (-1);
	buf[ret] = '\0';
	close(fd);
	return (browse_str(buf, block, hash));
}
