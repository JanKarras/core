# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 16:17:39 by jkarras           #+#    #+#              #
#    Updated: 2024/02/06 20:32:13 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

BONUS_SRCS =	push_swap_bonus/swap_b_bonus.c \
				push_swap_bonus/ckeck_bonus.c \
				push_swap_bonus/get_next_line_bonus/get_next_line_bonus.c \
				push_swap_bonus/get_next_line_bonus/get_next_line_utils_bonus.c \
				push_swap_bonus/ft_strcmp_bonus.c \
				push_swap_bonus/get_functions_array_bonus.c \
				push_swap_bonus/main_bonus.c \
				push_swap_bonus/main_utils_bonus.c \
				push_swap_bonus/push_a_bonus.c \
				push_swap_bonus/push_b_bonus.c \
				push_swap_bonus/reverse_rotate_a_b_bonus.c \
				push_swap_bonus/reverse_rotate_a_bonus.c \
				push_swap_bonus/reverse_rotate_b_bonus.c \
				push_swap_bonus/rotate_a_b_bonus.c \
				push_swap_bonus/rotate_a_bonus.c \
				push_swap_bonus/rotate_b_bonus.c \
				push_swap_bonus/swap_a_b_bonus.c \
				push_swap_bonus/swap_a_bonus.c \


SRCS =	execute_utils.c \
		execute.c \
		ft_push_swap.c \
		ft_strcmp.c \
		get_calls.c \
		getter_utils.c \
		main_utils.c \
		main.c \
		sort_big_amount.c \
		sort_small_amount.c \
		./operations/push_a.c \
		./operations/push_b.c \
		./operations/reverse_rotate_a_b.c \
		./operations/reverse_rotate_a.c \
		./operations/reverse_rotate_b.c \
		./operations/rotate_a_b.c \
		./operations/rotate_a.c \
		./operations/rotate_b.c \
		./operations/swap_a_b.c \
		./operations/swap_a.c \
		./operations/swap_b.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

bonus: $(BONUS_NAME)

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

