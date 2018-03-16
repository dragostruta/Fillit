/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:09:52 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 03:18:32 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetri_objects.h"

void	free_tetrimino(void *tetrimino, size_t size)
{
	if (size != 0)
		free(tetrimino);
	tetrimino = NULL;
}

void	free_tetrimino_list(t_list **tetriminos)
{
	if (tetriminos != NULL)
		ft_lstdel(tetriminos, &free_tetrimino);
}

t_map	*get_new_map(int size)
{
	t_map	*map_ptr;
	int		i;
	int		j;

	map_ptr = (t_map*)malloc(sizeof(t_map));
	if (map_ptr == NULL)
		return (NULL);
	map_ptr->map = (char**)malloc(sizeof(char*) * size);
	if (map_ptr->map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map_ptr->map[i] = ft_strnew(size - 1);
		if (map_ptr->map[i] == NULL)
			return (NULL);
		j = 0;
		while (j < size)
			map_ptr->map[i][j++] = '.';
		i++;
	}
	map_ptr->size = size;
	return (map_ptr);
}

void	delete_map(t_map **map_ptr)
{
	int i;

	i = 0;
	while (i < (*map_ptr)->size)
		ft_memdel((void**)&((*map_ptr)->map[i++]));
	ft_memdel((void**)&(*map_ptr)->map);
	ft_memdel((void**)&(*map_ptr));
}

t_map	*clone_map(t_map *map_ptr)
{
	t_map	*map;
	int		i;
	int		j;

	map = get_new_map(map_ptr->size);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			map->map[i][j] = map_ptr->map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}
