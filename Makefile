# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 18:21:52 by abtouait          #+#    #+#              #
#    Updated: 2025/12/24 16:16:54 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	SRC/GNL/get_next_line_utils.c\
		SRC/GNL/get_next_line.c\
		SRC/UTILS/common_utils.c\
		SRC/PARSE_MAP/check_extension.c\
		SRC/PARSE_MAP/init_struct.c\
		SRC/PARSE_MAP/copy_map.c\
		SRC/PARSE_MAP/get_cardinals.c\
		SRC/PARSE_MAP/get_fc.c\
		SRC/PARSE_MAP/check_map_closed.c\
		SRC/PARSE_MAP/parse.c\
		SRC/PARSE_MAP/flood_fill.c\
		SRC/PARSE_MAP/equalize_map.c\
		SRC/2D/handle_key.c\
		SRC/2D/draw.c\
		SRC/2D/init_pos.c\
		SRC/2D/raycast.c\
		SRC/2D/render.c\
		SRC/2D/main.c\
		SRC/UTILS/utils_rgb.c\
		SRC/PARSE_MAP/exit_clean.c\
		SRC/UTILS/utils_parsing.c\
		SRC/parsing/inits.c\
		SRC/parsing/free_map.c\
		SRC/parsing/parse_map.c\
		SRC/parsing/parse_map3.c\
		SRC/parsing/utils.c\
		
		
		
CFLAGS = -Wall -Wextra -g

MLX_LIB = mlx/libmlx.a

#-fsanitize=address -g3

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
	rm -f SRC/GNL/*.o
	rm -f SRC/PARSE_MAP/*.o
	rm -f SRC/WINDOW/*.o
	rm -f SRC/UTILS/*.o
	rm -f SRC/2D/*.o
	make -C mlx clean

fclean: clean
	rm -f $(NAME)
	rm -f mlx/libmlx.a

re: fclean all

.PHONY: all clean fclean re