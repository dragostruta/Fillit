/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:22:29 by gpop              #+#    #+#             */
/*   Updated: 2017/12/13 01:05:04 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include "libft.h"
# include "tetri_objects.h"
# include "validator.h"
# include <fcntl.h>

# define T_LENGTH 20

t_list	*process_file(char *filename);

#endif
