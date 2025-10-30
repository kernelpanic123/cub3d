# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 18:21:52 by abtouait          #+#    #+#              #
#    Updated: 2025/10/30 18:28:10 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	SCR/GNL/get_next_line_utils.c\
		SCR/GNL/get_next_line.c\
		

CFLAGS = -Wall -Wextra -Werror

MLX_LIB = mlx/libmlx.a


OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C mlx

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX_LIB)
	cc $(OBJ) -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f *.o
	make -C mlx clean

fclean: clean
	rm -f $(NAME)
	rm -f mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re