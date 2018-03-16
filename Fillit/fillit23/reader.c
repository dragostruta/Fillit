/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:13:47 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 01:08:17 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reader.h"

int			read_next_piece(int fd, char **piece)
{
	int		ret;
	char	c;

	*piece = ft_strnew(T_LENGTH);
	if (piece == NULL)
		return (-1);
	ret = read(fd, *piece, T_LENGTH);
	if (ret != T_LENGTH)
	{
		ft_strdel(piece);
		return (-1);
	}
	if (!is_valid_piece(*piece, T_LENGTH))
	{
		ft_strdel(piece);
		return (-1);
	}
	ret = read(fd, &c, 1);
	if (ret == 0)
		return (0);
	else if (c == '\n')
		return (1);
	return (-1);
}

void		normalize_piece(t_tetrimino **tetrimino)
{
	int topmost;
	int leftmost;
	int i;

	topmost = 4;
	leftmost = 4;
	i = 0;
	while (i < 4)
	{
		if ((*tetrimino)->pieces[i].x < topmost)
			topmost = (*tetrimino)->pieces[i].x;
		if ((*tetrimino)->pieces[i].y < leftmost)
			leftmost = (*tetrimino)->pieces[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*tetrimino)->pieces[i].x -= topmost;
		(*tetrimino)->pieces[i++].y -= leftmost;
	}
}

t_tetrimino	*string_to_tetrimino(char *piece)
{
	t_tetrimino	*tetrimino;
	int			i;
	int			index;

	tetrimino = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	if (tetrimino == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (i < T_LENGTH)
	{
		if (piece[i] == '#')
		{
			tetrimino->pieces[index].x = i / 5;
			tetrimino->pieces[index++].y = i % 5;
		}
		i++;
	}
	normalize_piece(&tetrimino);
	return (tetrimino);
}

t_list		*name_tetriminos(t_list *tetriminos)
{
	char	initial;
	t_list	*list;

	initial = 'A';
	list = tetriminos;
	while (list)
	{
		((t_tetrimino*)(list->content))->initial = initial;
		initial++;
		list = list->next;
	}
	return (tetriminos);
}

t_list		*process_file(char *filename)
{
	t_list	*tetriminos;
	int		fd;
	char	*piece;
	int		ret;

	tetriminos = NULL;
	if (file_exists(filename) && !file_is_too_large(filename))
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (NULL);
		while ((ret = read_next_piece(fd, &piece)) == 1)
			ft_lstappend(&tetriminos, ft_lstnew(string_to_tetrimino(piece),
						sizeof(t_tetrimino)));
		if (ret == -1)
		{
			free_tetrimino_list(&tetriminos);
			return (NULL);
		}
		ft_lstappend(&tetriminos, ft_lstnew(string_to_tetrimino(piece),
					sizeof(t_tetrimino)));
		close(fd);
		return (name_tetriminos(tetriminos));
	}
	return (NULL);
}
