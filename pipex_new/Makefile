# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 14:20:43 by jkarras           #+#    #+#              #
#    Updated: 2024/04/11 16:53:02 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	main.c \
		utils.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS) $(MLX)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

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























