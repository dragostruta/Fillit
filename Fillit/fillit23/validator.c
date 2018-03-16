/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:15:24 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 20:42:18 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

int	file_exists(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	get_chunk_connections(char *piece, int i, int j)
{
	int connections;

	connections = 0;
	if (i > 0 && piece[(i - 1) * 5 + j] == '#')
		connections++;
	if (i < 3 && piece[(i + 1) * 5 + j] == '#')
		connections++;
	if (j > 0 && piece[i * 5 + (j - 1)] == '#')
		connections++;
	if (j < 3 && piece[i * 5 + (j + 1)] == '#')
		connections++;
	return (connections);
}

int	is_tetrimino_connected(char *piece)
{
	int	i;
	int	j;
	int con;

	con = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (piece[i * 5 + j] == '#')
				con += get_chunk_connections(piece, i, j);
	}
	if (con >= 6)
		return (1);
	return (0);
}

int	is_valid_piece(char *piece, int t_length)
{
	int i;
	int hash_count;

	if ((int)ft_strlen(piece) != t_length)
		return (0);
	if (piece[4] != '\n' || piece[9] != '\n' || piece[14] != '\n' ||
			piece[19] != '\n')
		return (0);
	i = 0;
	hash_count = 0;
	while (i < t_length)
	{
		if (piece[i] == '#')
			hash_count++;
		else if (piece[i] != '.' && piece[i] != '\n')
			return (0);
		i++;
	}
	if (hash_count != 4)
		return (0);
	return (is_tetrimino_connected(piece));
}

int	file_is_too_large(char *filename)
{
	int		fd;
	int		ret;
	char	*buffer;

	buffer = (char*)malloc((MAX_FILE_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = read(fd, buffer, MAX_FILE_SIZE + 1);
	free(buffer);
	close(fd);
	return (ret > MAX_FILE_SIZE);
}
