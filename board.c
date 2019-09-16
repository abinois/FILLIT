/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 10:39:32 by abinois           #+#    #+#             */
/*   Updated: 2019/05/03 14:12:19 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>

int		get_board_min(int tetri)
{
	int		b;
	int		sq;

	b = tetri * 4;
	sq = ft_sqrt(b);
	if (ft_po(sq, 2) < b)
		return (sq + 1);
	return (sq);
}

int		is_out(int eob, t_tetri *tetri, int x, int y)
{
	if (y == -1 && ((x + tetri->h1.x) >= eob || (x + tetri->h2.x) >= eob
		|| (x + tetri->h3.x) >= eob || (x + tetri->h4.x) >= eob))
		return (-1);
	if (y >= 0 && ((y + tetri->h1.y) >= eob || (x + tetri->h1.x) >= eob
		|| (y + tetri->h2.y) >= eob || (x + tetri->h2.x) >= eob
		|| (y + tetri->h3.y) >= eob || (x + tetri->h3.x) >= eob
		|| (y + tetri->h4.y) >= eob || (x + tetri->h4.x) >= eob))
		return (-1);
	return (0);
}

char	**make_board(int eob)
{
	char	**board;
	int		x;
	int		y;

	y = -1;
	if (!(board = (char**)malloc(sizeof(char*) * eob)))
		return (NULL);
	while (++y < eob)
	{
		x = 0;
		if (!(board[y] = (char*)malloc(sizeof(char) * (eob + 1))))
		{
			while (--y >= 0)
				free(board[y]);
			free(board);
			board = NULL;
			return (NULL);
		}
		while (x < eob)
			board[y][x++] = '.';
		board[y][x] = '\0';
	}
	return (board);
}

char	**reset_board(char **board, int eob)
{
	int		y;

	y = eob;
	while (--y >= 0)
		free(board[y]);
	free(board);
	board = NULL;
	return (make_board(eob + 1));
}

void	print_board(char **board, int eob)
{
	int		y;

	y = -1;
	while (++y < eob)
		ft_putendl(board[y]);
	while (--y >= 0)
		free(board[y]);
	free(board);
	board = NULL;
}
