/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_objects.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:59:10 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 03:15:18 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_OBJECTS_H
# define TETRI_OBJECTS_H

# include "libft.h"

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_tetrimino
{
	t_point		pieces[4];
	char		initial;
}				t_tetrimino;

typedef struct	s_map
{
	char		**map;
	int			size;
}				t_map;

void			free_tetrimino(void *tetrimino, size_t size);
void			free_tetrimino_list(t_list **tetriminos);
t_map			*get_new_map(int size);
void			delete_map(t_map **map);
t_map			*clone_map(t_map *map_ptr);

#endif
