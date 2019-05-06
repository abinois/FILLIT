/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinois <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:01:52 by abinois           #+#    #+#             */
/*   Updated: 2019/05/03 17:43:14 by edillenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE_FILLIT 546

typedef struct	s_hash
{
	int				x;
	int				y;
}				t_hash;

typedef struct	s_tetri
{
	t_hash			h1;
	t_hash			h2;
	t_hash			h3;
	t_hash			h4;
	struct s_tetri	*next;
	char			ltr;
}				t_tetri;

int				ft_usage(char *usage);
int				ft_exit(int fd);

int				check_input(char *input);
int				browse_str(char *str, int block, int hash);
int				check_cr(char *s, int i, int *line, int *hash);
int				check_hashz(char *s, int i, int nb_hash);
int				new_block(char *s, int i, int *block, int *line);

t_tetri			*make_list(int fd, int ntetri);
t_tetri			*tetri_to_struct(int fd);
void			get_coor(int h, t_tetri **tetri, int x, int y);
void			adjust_coor(t_tetri **cur);
void			*free_lst(t_tetri **head, int fd);

int				get_board_min(int tetri);
int				is_out(int eob, t_tetri *tetri, int x, int y);
char			**make_board(int eob);
char			**reset_board(char **board, int eob);
void			print_board(char **board, int eob);

int				fill_tetri(char **board, int eob, t_tetri *tetri);
void			set_ltr(char **board, t_tetri *tetri, int x, int y);
void			unset_ltr(char **board, t_tetri *tetri, int x, int y);
int				not_dot(char **board, int x, int y, t_tetri *tetri);

#endif
