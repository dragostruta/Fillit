/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 01:10:58 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 22:50:42 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "reader.h"
#include "solver.h"
#include "console.h"

int	main(int argc, char **argv)
{
	t_list	*tetriminos;
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (1);
	}
	else
	{
		tetriminos = process_file(argv[1]);
		if (tetriminos == NULL)
		{
			ft_putendl("error");
			return (1);
		}
		else
		{
			map = solve(tetriminos);
			print_map(map);
			delete_map(&map);
			free_tetrimino_list(&tetriminos);
		}
	}
	return (0);
}
