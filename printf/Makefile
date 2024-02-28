# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 15:03:46 by jkarras           #+#    #+#              #
#    Updated: 2023/11/29 16:53:50 by jkarras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_phex_p.c \
		ft_printf.c \
		ft_putchar_p.c \
		ft_putnbr_p.c \
		ft_putstr_p.c \
		ft_putu_p.c \
		ft_putvoidhex_p.c \

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = -rcs
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

