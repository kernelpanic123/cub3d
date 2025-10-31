# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 18:21:52 by abtouait          #+#    #+#              #
#    Updated: 2025/10/31 17:40:15 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	SRC/GNL/get_next_line_utils.c\
		SRC/GNL/get_next_line.c\
		SRC/UTILS/common_utils.c\
		SRC/PARSE_MAP/check_extension.c\
		SRC/PARSE_MAP/init_struct.c\
		SRC/PARSE_MAP/copy_map.c\
		
CFLAGS = -Wall -Wextra -Werror

MLX_LIB = mlx/libmlx.a


OBJ = $(SRC:.c=.o)

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C mlx

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(MLX_LIB)
	cc $(OBJ) -fsanitize=address -g3 -Lmlx -lmlx -lXext -lX11 -lm -o $(NAME)

clean:
	rm -f *.o
	rm -f SRC/GNL/*.o
	rm -f SRC/PARSE_MAP/*.o
	make -C mlx clean

fclean: clean
	rm -f $(NAME)
	rm -f mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re