/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 03:25:10 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 03:28:29 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.h"

void	print_map(t_map *map_ptr)
{
	int i;
	int j;

	i = 0;
	while (i < map_ptr->size)
	{
		j = 0;
		while (j < map_ptr->size)
			ft_putchar(map_ptr->map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
