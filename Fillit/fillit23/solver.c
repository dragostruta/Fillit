/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:11:40 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 18:14:00 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int		try_place(t_map **map, int i, int j, t_tetrimino *tetrimino)
{
	int index;
	int	ok;

	index = 0;
	ok = 1;
	while (index < 4 && ok)
	{
		if (i + tetrimino->pieces[index].x >= (*map)->size ||
			j + tetrimino->pieces[index].y >= (*map)->size ||
			((*map)->map[i + tetrimino->pieces[index].x][j +
			tetrimino->pieces[index].y] != '.'))
			ok = 0;
		index++;
	}
	if (ok)
	{
		index = -1;
		while (++index < 4)
			(*map)->map[i + tetrimino->pieces[index].x][j +
			tetrimino->pieces[index].y] = tetrimino->initial;
		return (1);
	}
	return (0);
}

int		fill_map(t_list *tetriminos, t_map **map, int size)
{
	int		i;
	int		j;
	t_map	*map_cpy;

	if (tetriminos == NULL)
		return (1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			map_cpy = clone_map(*map);
			if (try_place(map, i, j, (t_tetrimino*)(tetriminos->content)))
				if (fill_map(tetriminos->next, map, size))
				{
					delete_map(&map_cpy);
					return (1);
				}
			delete_map(map);
			*map = map_cpy;
		}
	}
	return (0);
}

t_map	*solve(t_list *tetriminos)
{
	int		size;
	t_map	*map;

	size = 2;
	map = get_new_map(size);
	if (map == NULL)
		return (NULL);
	while (!fill_map(tetriminos, &map, size))
	{
		delete_map(&map);
		map = get_new_map(++size);
		if (map == NULL)
			return (NULL);
	}
	return (map);
}
