# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lejulien <lejulien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 13:10:44 by lejulien          #+#    #+#              #
#    Updated: 2021/03/05 17:08:41 by lejulien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_UTILS = ./srcs/utils/ft_atoi.c ./srcs/utils/ft_putnbr_fd.c \
			 ./srcs/utils/ft_putstr.c
SRCS_CHECKER = ./srcs/checker/checker.c ./srcs/checker/actions.c \
			   ./srcs/checker/error.c

OBJS_UTILS = $(SRCS_UTILS:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

NAME	= checker

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror




all:	$(NAME)

.PHONY:	clean fclean re

$(NAME):	$(OBJS_UTILS) $(OBJS_CHECKER)
	gcc -o $(NAME) $(OBJS_UTILS) $(OBJS_CHECKER)

clean:
	rm -f $(OBJS_CHECKER) $(OBJS_UTILS)

fclean: clean:
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(GCC) -c $<  -o $(<:.c=.o)
