/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edillenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:19:38 by edillenb          #+#    #+#             */
/*   Updated: 2019/05/03 17:41:40 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

void	set_ltr(char **board, t_tetri *tetri, int x, int y)
{
	board[y + tetri->h1.y][x + tetri->h1.x] = tetri->ltr;
	board[y + tetri->h2.y][x + tetri->h2.x] = tetri->ltr;
	board[y + tetri->h3.y][x + tetri->h3.x] = tetri->ltr;
	board[y + tetri->h4.y][x + tetri->h4.x] = tetri->ltr;
}

void	unset_ltr(char **board, t_tetri *tetri, int x, int y)
{
	board[y + tetri->h1.y][x + tetri->h1.x] = '.';
	board[y + tetri->h2.y][x + tetri->h2.x] = '.';
	board[y + tetri->h3.y][x + tetri->h3.x] = '.';
	board[y + tetri->h4.y][x + tetri->h4.x] = '.';
}

int		not_dot(char **board, int x, int y, t_tetri *tetri)
{
	if ((board[y + tetri->h1.y][x + tetri->h1.x] != '.')
		|| (board[y + tetri->h2.y][x + tetri->h2.x] != '.')
		|| (board[y + tetri->h3.y][x + tetri->h3.x] != '.')
		|| (board[y + tetri->h4.y][x + tetri->h4.x] != '.'))
		return (-1);
	return (0);
}

int		fill_tetri(char **board, int eob, t_tetri *tetri)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (is_out(eob, tetri, x, y) != -1)
	{
		if (not_dot(board, x, y, tetri) == -1)
			x++;
		else
		{
			set_ltr(board, tetri, x, y);
			if (tetri->next == NULL || fill_tetri(board, eob, tetri->next) == 0)
				return (0);
			unset_ltr(board, tetri, x, y);
			x++;
		}
		if (is_out(eob, tetri, x, -1) == -1)
		{
			x = 0;
			y++;
		}
	}
	return (-1);
}

int		main(int argc, char **argv)
{
	int		blcks;
	int		fd;
	int		eob;
	char	**board;
	t_tetri	*head_list;

	if (argc != 2)
		return (ft_usage("usage.txt"));
	blcks = check_input(argv[1]);
	if ((fd = open(argv[1], O_RDONLY)) == -1 || blcks > 26 || blcks == -1)
		return (ft_exit(fd));
	if ((head_list = make_list(fd, blcks)) == NULL)
		return (ft_exit(fd));
	eob = get_board_min(blcks);
	if (!(board = make_board(eob)))
		return ((int)free_lst(&head_list, fd));
	while (fill_tetri(board, eob, head_list) == -1)
		if (!(board = reset_board(board, eob++)))
			return ((int)free_lst(&head_list, fd));
	print_board(board, eob);
	return ((int)free_lst(&head_list, fd));
}
