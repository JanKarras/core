# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 14:20:43 by jkarras           #+#    #+#              #
#    Updated: 2024/02/22 15:53:01 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	main.c \
		check_map_utils.c \
		check_map.c \
		create_map.c \
		start_game.c \
		check_path_is_valid.c \

OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
INCLUDES = -I/opt/X11/include -Imlx
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) libft/libft.a

.c.o:
	$(CC) -c -o $@ $< $(INCLUDES)

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
