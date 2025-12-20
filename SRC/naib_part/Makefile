# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmagamad <nmagamad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 16:10:18 by nmagamad          #+#    #+#              #
#    Updated: 2025/11/12 16:19:57 by nmagamad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g 
NAME = cub3d
SRC_DIR = parsing
OBJ_DIR = obj
INCLUDE = include
SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT_DIR = libft
LIBFT_A	= $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT_LNK = -L$(LIBFT_DIR) -lft
RL_INC = -I$(shell brew --prefix readline 2>/dev/null || echo "/usr/include/readline")
RL_LNK = -lreadline -lncurses

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCLUDE) $(LIBFT_INC) -c $< -o $@

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) -I$(INCLUDE) $(LIBFT_INC) $(OBJS) $(LIBFT_LNK) $(RL_LNK) -o $(NAME)

all: $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re