# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpop <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 00:44:46 by gpop              #+#    #+#              #
#    Updated: 2017/12/14 20:56:34 by gpop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_DIR = ./fillit23
INC_DIR = ./fillit23
LIB_DIR = ./libft

FUNCTIONS = main reader tetri_objects validator solver console
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_LINK = -L $(LIB_DIR) -lft

SRC = $(patsubst %,$(SRC_DIR)/%.c,$(FUNCTIONS))
OBJ = $(patsubst %,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@$(CC) -I $(LIB_DIR) -I $(INC_DIR) $(CFLAGS) -c $(SRC)
	@$(CC) $(OBJ) $(LIB_LINK) -o $(NAME)

clean:
	@make -C $(LIB_DIR) clean
	@rm -f $(OBJ)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all
