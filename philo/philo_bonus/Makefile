# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 12:53:26 by jkarras           #+#    #+#              #
#    Updated: 2024/06/04 15:48:06 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	main_bonus.c \
		utils_bonus.c\


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
