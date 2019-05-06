/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:32:10 by abinois           #+#    #+#             */
/*   Updated: 2019/05/06 10:38:07 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

void		*free_lst(t_tetri **head, int fd)
{
	t_tetri		*current;
	t_tetri		*next;

	current = *head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
	close(fd);
	return (NULL);
}

void		adjust_coor(t_tetri **cur)
{
	while ((*cur)->h1.x != 0 && (*cur)->h2.x != 0 && (*cur)->h3.x != 0
			&& (*cur)->h4.x != 0)
	{
		(*cur)->h1.x -= 1;
		(*cur)->h2.x -= 1;
		(*cur)->h3.x -= 1;
		(*cur)->h4.x -= 1;
	}
	while ((*cur)->h1.y != 0 && (*cur)->h2.y != 0 && (*cur)->h3.y != 0
			&& (*cur)->h4.y != 0)
	{
		(*cur)->h1.y -= 1;
		(*cur)->h2.y -= 1;
		(*cur)->h3.y -= 1;
		(*cur)->h4.y -= 1;
	}
}

void		get_coor(int h, t_tetri **tetri, int x, int y)
{
	if (h == 1)
	{
		(*tetri)->h1.x = x;
		(*tetri)->h1.y = y;
	}
	if (h == 2)
	{
		(*tetri)->h2.x = x;
		(*tetri)->h2.y = y;
	}
	if (h == 3)
	{
		(*tetri)->h3.x = x;
		(*tetri)->h3.y = y;
	}
	if (h == 4)
	{
		(*tetri)->h4.x = x;
		(*tetri)->h4.y = y;
	}
}

t_tetri		*tetri_to_struct(int fd)
{
	char	*line;
	t_tetri	*tetri;
	int		x;
	int		y;
	int		h;

	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	h = 0;
	y = -1;
	while (ft_get_next_line(fd, &line) && ++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (line[x] == '#')
			{
				h++;
				get_coor(h, &tetri, x, y);
			}
		free(line);
	}
	if (y == 4)
		free(line);
	tetri->next = NULL;
	return (tetri);
}

t_tetri		*make_list(int fd, int ntetri)
{
	t_tetri		*head;
	t_tetri		*tmp;
	char		ltr;

	tmp = NULL;
	ltr = 'A';
	if (!(head = tetri_to_struct(fd)))
		return (NULL);
	adjust_coor(&head);
	head->ltr = ltr++;
	ntetri--;
	while (ntetri--)
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = tetri_to_struct(fd)))
			return (free_lst(&head, fd));
		adjust_coor(&(tmp->next));
		tmp->next->ltr = ltr++;
	}
	tmp = NULL;
	return (head);
}
