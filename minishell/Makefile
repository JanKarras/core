# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 14:20:43 by jkarras           #+#    #+#              #
#    Updated: 2024/07/25 16:57:50 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	env/env.c \
		env/utils.c \
		exit/exit.c \
		input/input.c \
		input/utils.c \
		parse/multi_utils.c \
		parse/parse_multi.c \
		parse/parse_single.c \
		parse/single_utils.c \
		parse/utils.c \
		process/process_builtin.c \
		process/process_multi.c \
		process/process_single.c \
		process/utils.c \
		programm/main.c \
		programm/utils.c \
		builtins/builtins.c \
		builtins/builtins_help1.c \
		builtins/builtins_help2.c \
		builtins/builtins_help3.c \
		builtins/echo.c \

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a -lreadline

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean : clean
	$(RM) $(NAME) $(BONUS_OBJS) $(BONUS_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re























