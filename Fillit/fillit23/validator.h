/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:16:33 by gpop              #+#    #+#             */
/*   Updated: 2017/12/14 01:09:13 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# include <fcntl.h>
# include "libft.h"

int	file_exists(char *filename);
int	is_valid_piece(char *piece, int t_length);
int file_is_too_large(char *filename);

# define MAX_FILE_SIZE 545

#endif
