# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 14:20:43 by jkarras           #+#    #+#              #
#    Updated: 2024/03/04 16:13:30 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	main.c \
		check_map_utils.c \
		check_map.c \
		create_map.c \
		start_game.c \
		check_path_is_valid.c \
		get_koordinats.c \
		destroy.c \
		init.c \
		resize_img.c \
		move.c \
		draw.c \

OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -L/usr/X11/lib -lX11 -lXext -lm
MLX_DIR = ./mlx
MLX = ./mlx/libmlx.a
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS) $(MLX)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) libft/libft.a $(MLX)

$(MLX):
	make -C $(MLX_DIR)

$(BONUS_NAME): $(BONUS_OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) libft/libft.a

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean : clean
	$(RM) $(NAME) $(BONUS_OBJS) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
